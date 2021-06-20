class Solution {
	func numberOfRounds(_ s: String, _ f: String) -> Int {
		let startTime = s.toMinutes
		var finishTime = f.toMinutes
		if startTime > finishTime {
			finishTime += 24.0 * 60.0
		}
		return Int(floor(finishTime / 15.0) - ceil(startTime / 15.0))
	}
}

extension String {
	var toMinutes: Double {
		let hhmm = Array<Character>(self)
		let h = Double(String(hhmm[0..<2])) ?? 0.0
		let m = Double(String(hhmm[3...])) ?? 0.0
		return h * 60.0 + m
	}
}
