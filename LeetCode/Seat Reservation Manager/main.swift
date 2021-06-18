/// An ordered collection of unique `Element` instances
public struct SortedSet<Element : Hashable & Comparable> : Hashable, RandomAccessCollection {
	
	public typealias Indices = DefaultIndices<SortedSet<Element>>
	
	var array: [Element]
	var set: Set<Element>
	
	/// Always zero, which is the index of the first element when non-empty.
	public var startIndex: Int {
		return array.startIndex
	}
	
	/// A "past-the-end" element index; the successor of the last valid
	/// subscript argument.
	public var endIndex: Int {
		return array.endIndex
	}
	
	public func index(after i: Int) -> Int {
		return array.index(after: i)
	}
	
	public func index(before i: Int) -> Int {
		return array.index(before: i)
	}
	
	public subscript(position: Int) -> Element {
		return array[position]
	}
	
	public func hash(into hasher: inout Hasher) {
		hasher.combine(set)
	}
	
	public func indexOf(_ element: Element) -> Int? {
		guard set.contains(element) else { return nil }
		return indexOf(element, in: range)
	}
	
	var range: Range<Int> {
		return Range(uncheckedBounds: (startIndex, endIndex))
	}
	
	func indexOf(_ element: Element, in range: Range<Int>) -> Int {
		guard range.count > 2 else {
			return element == array[range.lowerBound] ? range.lowerBound : (range.upperBound - 1)
		}
		let middleIndex = (range.lowerBound + range.upperBound)/2
		let middle = self[middleIndex]
		if element < middle {
			return indexOf(element, in: range.lowerBound..<middleIndex)
		} else {
			return indexOf(element, in: middleIndex..<range.upperBound)
		}
	}
	
	/// Construct from an arbitrary sequence with elements of type `Element`.
	public init<S : Sequence>(_ s: S, presorted: Bool = false, noDuplicates: Bool = false) where S.Iterator.Element == Element {
		if noDuplicates {
			if presorted {
				(self.array, self.set) = (Array(s), Set(s))
			} else {
				(self.array, self.set) = (s.sorted(), Set(s))
			}
		} else {
			if presorted {
				(self.array, self.set) = collapse(s)
			} else {
				(self.array, self.set) = collapse(s.sorted())
			}
		}
	}
	
	/// Construct an empty SortedSet.
	public init() {
		self.array = []
		self.set = []
	}
	
}


public func ==<T>(lhs: SortedSet<T>, rhs: SortedSet<T>) -> Bool {
	guard lhs.count == rhs.count else {
		return false
	}
	for (lhs, rhs) in zip(lhs, rhs) where lhs != rhs {
		return false
	}
	return true
}

extension Array where Element : Comparable & Hashable {
	
	/// Cast SortedSet as an Array
	public init(_ sortedSet: SortedSet<Element>) {
		self = sortedSet.array
	}
	
}

extension Set where Element : Comparable {
	
	/// Cast SortedSet as a Set
	public init(_ sortedSet: SortedSet<Element>) {
		self = sortedSet.set
	}
	
}

extension SortedSet {
	
	public init(minimumCapacity: Int) {
		self.array = []
		self.set = Set(minimumCapacity: minimumCapacity)
		self.array.reserveCapacity(minimumCapacity)
	}
	
	/// Returns `true` if the sorted set contains a member.
	public func contains(_ member: Element) -> Bool {
		return set.contains(member)
	}
	
	/// Insert a member into the sorted set.
	public mutating func insert(_ member: Element) {
		_ = remove(member)
		set.insert(member)
		insert(member, into: range)
	}
	
	private mutating func insert(_ member: Element, into range: Range<Int>) {
		if range.count == 0 {
			return array.insert(member, at: range.lowerBound)
		} else if member < self[range.lowerBound] {
			return array.insert(member, at: range.lowerBound)
		} else if member > self[range.upperBound - 1] {
			return array.insert(member, at: range.upperBound)
		} else if range.count == 2 {
			return array.insert(member, at: range.lowerBound + 1)
		} else  {
			let middleIndex = (range.lowerBound + range.upperBound)/2
			let middle = self[middleIndex]
			if member < middle {
				insert(member, into: range.lowerBound..<middleIndex)
			} else {
				insert(member, into: middleIndex..<range.upperBound)
			}
		}
	}
	
	/// Remove the member from the sorted set and return it if it was present.
	public mutating func remove(_ member: Element) -> Element? {
		return set.remove(member).map { array.remove(at: indexOf($0, in: range)) }
	}
	
	/// Returns true if the sorted set is a subset of a finite sequence as a `Set`.
	public func isSubset<S : Sequence>(of sequence: S) -> Bool where S.Iterator.Element == Element {
		return set.isSubset(of: sequence)
	}
	
	/// Returns true if the sorted set is a subset of a finite sequence as a `Set`
	/// but not equal.
	public func isStrictSubset<S : Sequence>(of sequence: S) -> Bool where S.Iterator.Element == Element {
		return set.isStrictSubset(of: sequence)
	}
	
	/// Returns true if the sorted set is a superset of a finite sequence as a `Set`.
	public func isSuperset<S : Sequence>(of sequence: S) -> Bool where S.Iterator.Element == Element {
		return set.isSuperset(of: sequence)
	}
	
	/// Returns true if the sorted set is a superset of a finite sequence as a `Set`
	/// but not equal.
	public func isStrictSuperset<S : Sequence>(of sequence: S) -> Bool where S.Iterator.Element == Element {
		return set.isStrictSuperset(of: sequence)
	}
	
	/// Returns true if no members in the sorted set are in a finite sequence as a `Set`.
	public func isDisjoint<S : Sequence>(with sequence: S) -> Bool where S.Iterator.Element == Element {
		return set.isDisjoint(with: sequence)
	}
	
	/// Return a new `SortedSet` with items in both this set and a finite sequence.
	public func union<S : Sequence>(_ sequence: S) -> SortedSet where S.Iterator.Element == Element {
		return copy(self) { (set: inout SortedSet) in set.formUnion(sequence) }
	}
	
	/// Append elements of a finite sequence into this `SortedSet`.
	public mutating func formUnion<S : Sequence>(_ sequence: S) where S.Iterator.Element == Element {
		for member in sequence {
			insert(member)
		}
	}
	
	/// Return a new sorted set with elements in this set that do not occur
	/// in a finite sequence.
	public func subtracting<S : Sequence>(_ sequence: S) -> SortedSet where S.Iterator.Element == Element {
		return copy(self) { (set: inout SortedSet) in set.subtract(sequence) }
	}
	
	/// Remove all members in the sorted set that occur in a finite sequence.
	public mutating func subtract<S : Sequence>(_ sequence: S) where S.Iterator.Element == Element {
		set.subtract(sequence)
		array = array.filter { set.contains($0) }
	}
	
	/// Return a new sorted set with elements common to this sorted set and a finite sequence.
	public func intersection<S : Sequence>(_ sequence: S) -> SortedSet where S.Iterator.Element == Element {
		return copy(self) { (set: inout SortedSet) in set.formIntersection(sequence) }
	}
	
	/// Remove any members of this sorted set that aren't also in a finite sequence.
	public mutating func formIntersection<S : Sequence>(_ sequence: S) where S.Iterator.Element == Element {
		set.formIntersection(sequence)
		array = array.filter { set.contains($0) }
	}
	
	/// Return a new sorted set with elements that are either in the sorted set or a finite
	/// sequence but do not occur in both.
	public func symmetricDifference<S : Sequence>(_ sequence: S) -> SortedSet where S.Iterator.Element == Element {
		return copy(self) { (set: inout SortedSet) in set.formSymmetricDifference(sequence) }
	}
	
	/// For each element of a finite sequence, remove it from the sorted set if it is a
	/// common element, otherwise add it to the sorted set. Repeated elements of the
	/// sequence will be ignored.
	public mutating func formSymmetricDifference<S : Sequence>(_ sequence: S) where S.Iterator.Element == Element {
		set.formSymmetricDifference(sequence)
		for member in sequence {
			insert(member, into: range)
		}
		self.array = array.filter { set.contains($0) }
	}
	
	/// If `!self.isEmpty`, remove the first element and return it, otherwise
	/// return `nil`.
	public mutating func popFirst() -> Element {
		guard let first = array.first else { fatalError() }
		set.remove(first)
		return array.removeFirst()
	}
	
}

internal func copy<T>(_ sortedSet: SortedSet<T>, operate: (inout SortedSet<T>) -> ()) -> SortedSet<T> {
	var copy = sortedSet
	operate(&copy)
	return copy
}

internal func collapse<Element : Hashable, S : Sequence>(_ s: S) -> ([Element], Set<Element>) where S.Iterator.Element == Element {
	var aSet = Set<Element>()
	return (s.filter { set(&aSet, contains: $0) }, aSet)
}

private func set<Element>(_ set: inout Set<Element>, contains element: Element) -> Bool {
	defer { set.insert(element) }
	return !set.contains(element)
}

class SeatManager {
	
	private var seats = SortedSet<Int>()
	
	init(_ n: Int) {
		for i in stride(from: 1, to: n + 1, by: 1) {
			seats.insert(i)
		}
	}
	
	func reserve() -> Int {
		let ans = seats.first ?? 0
		seats.remove(ans)
		return ans
	}
	
	func unreserve(_ seatNumber: Int) {
		seats.insert(seatNumber)
	}
}


