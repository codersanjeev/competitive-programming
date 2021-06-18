let abc = readLine()!.split(separator: " ")
let c = Int(abc[2])!
var (a, b) = (Int(abc[0])!, Int(abc[1])!)
if c % 2 == 0 {
	a = abs(a)
	b = abs(b)
}
if a > b {
	print(">")
} else if a < b {
	print("<")
} else {
	print("=")
}