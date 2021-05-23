import Foundation

class Solution {
	private func f(_ dist: [Int], _ hour: Double, _ speed: Int) -> Bool {
		var curr = Double(0)
		for i in dist.indices {
			let delta = Double(dist[i]) / Double(speed)
			if i == dist.count - 1 && curr + delta <= hour {
				return true
			}
			curr += ceil(delta)
		}
		return curr <= hour
	}
	
	func minSpeedOnTime(_ dist: [Int], _ hour: Double) -> Int {
		var (lo, hi, ans) = (1, Int(1e9), -1)
		while lo <= hi {
			let mid = lo + (hi - lo) / 2
			if f(dist, hour, mid) {
				ans = mid
				hi = mid - 1
			} else {
				lo = mid + 1
			}
		}
 		return ans
	}
}
