let s = readLine() ?? ""
let S = Array(s)
var answer = 0
for i in 0...9999 {
	var curr = i.toString()
	var good = true
	for d in 0...9 {
		if S[d] == "o" {
			var count = 0
			curr.forEach {
				if (($0.wholeNumberValue ?? 0) ?? 0) == d {
					count += 1
				}
			}
			if count == 0 {
				good = false
			}
		} else if S[d] == "x" {
			curr.forEach {
				if (($0.wholeNumberValue ?? 0) ?? 0) == d {
					good = false
				}
			}
		}
 	}
	if (good) {
		answer += 1
	}
}
print(answer)

extension Int {
	func toString() -> String {
		var ans = String(self)
		while ans.count < 4 {
			ans = "0" + ans
		}
		return ans
	}
}
