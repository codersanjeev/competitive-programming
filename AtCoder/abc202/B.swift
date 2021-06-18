let s = readLine()!
var ans = ""
s.reversed().forEach {
	if $0 == "6" {
		ans += "9"
	} else if $0 == "9" {
		ans += "6"
	} else {
		ans += String($0)
	}
}
print(ans)
