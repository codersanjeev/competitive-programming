class Solution {
    func kWeakestRows(_ mat: [[Int]], _ k: Int) -> [Int] {
        let n = mat.count, m = mat[0].count
        var st: SortedSet<CGPoint> = SortedSet()
        for i in 0..<n {
        	let curr = CGPoint(x: mat[i].reduce(0, +), y: i)
        	st.insert(curr)
        }
        var ans: [Int] = []
        var cnt = k
        for ele in st {
        	if (cnt > 0) {
        		ans.append(Int(ele.y) ?? 0)
        	}
        	cnt -= 1
        }
        return ans
    }
}

extension CGPoint: Hashable {
	public var hashValue: Int {
		return self.x.hashValue << 4 ^ self.y.hashValue
	}
}

public struct SortedSet<T: Comparable> {
  private var internalSet = [T]()
    
  var curr = 0
  
  public init() { }
  
  public var count: Int {
    return internalSet.count
  }
  
  public mutating func insert(_ item: T) {
    if exists(item) {
      return
    }
    
    for i in 0..<count {
      if internalSet[i] > item {
        internalSet.insert(item, at: i)
        return
      }
    }
    
    internalSet.append(item)
  }
  
  public mutating func remove(_ item: T) {
    if let index = index(of: item) {
      internalSet.remove(at: index)
    }
  }
  
    public func exists(_ item: T) -> Bool {
    return index(of: item) != nil
  }
  
  public func index(of item: T) -> Int? {
    var leftBound = 0
    var rightBound = count - 1
    
    while leftBound <= rightBound {
      let mid = leftBound + ((rightBound - leftBound) / 2)
      
      if internalSet[mid] > item {
        rightBound = mid - 1
      } else if internalSet[mid] < item {
        leftBound = mid + 1
      } else if internalSet[mid] == item {
        return mid
      } else {
        for j in stride(from: mid, to: count - 1, by: 1) {
          if internalSet[j + 1] == item {
            return j + 1
          } else if internalSet[j] < internalSet[j + 1] {
            break
          }
        }
        
        for j in stride(from: mid, to: 0, by: -1) {
          if internalSet[j - 1] == item {
            return j - 1
          } else if internalSet[j] > internalSet[j - 1] {
            break
          }
        }
        return nil
      }
    }
    return nil
  }
    
  public subscript(index: Int) -> T {
    assert(index >= 0 && index < count)
    return internalSet[index]
  }
  
  public func max() -> T? {
    return count == 0 ? nil : internalSet[count - 1]
  }
  
  public func min() -> T? {
    return count == 0 ? nil : internalSet[0]
  }
  
  public func kLargest(_ k: Int) -> T? {
    return k > count || k <= 0 ? nil : internalSet[count - k]
  }
  
  public func kSmallest(_ k: Int) -> T? {
    return k > count || k <= 0 ? nil : internalSet[k - 1]
  }
}

extension CGPoint: Comparable {
	public static func <(lhs: CGPoint, rhs: CGPoint) -> Bool {
		return lhs.x < rhs.x
	}
}

extension SortedSet: Sequence, IteratorProtocol {

	public mutating func next() -> T? {
		defer {
			curr += 1
		}
        if (curr == count) {
            return nil
        } else {
		    return internalSet[curr]
        }
	}
}
