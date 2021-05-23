class Solution {
	func canReach(_ s: String, _ minJump: Int, _ maxJump: Int) -> Bool {
		let S = Array(s)
		var reachable = [Int]()
		reachable.append(0)
		for i in 1 ..< s.count {
			if S[i] == "0" {
				while !reachable.isEmpty && reachable.first! < i - maxJump {
					reachable.removeFirst()
				}
				if !reachable.isEmpty && reachable.first! <= i - minJump {
					reachable.append(i)
				}
			}
		}
		return !reachable.isEmpty && reachable.last! == s.count - 1
	}
}
