class Solution {
	func evalRPN(_ tokens: [String]) -> Int {
		var st = [Int]()
		tokens.forEach {
			switch ($0) {
				case "+":
					let x = st.removeLast()
					let y = st.removeLast()
					st.append(y + x)
				case "-":
					let x = st.removeLast()
					let y = st.removeLast()
					st.append(y - x)
				case "*":
					let x = st.removeLast()
					let y = st.removeLast()
					st.append(y * x)
				case "/":
					let x = st.removeLast()
					let y = st.removeLast()
					st.append(y / x)
				default:
					st.append(Int($0) ?? 0)
			}
		}
		return st.last ?? 0
	}
}
