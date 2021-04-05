class Solution {
    func squareIsWhite(_ S: String) -> Bool {
        let s = Array(S)
        let a = (s[0].asciiValue ?? UInt8(0)) - (Character("a").asciiValue ?? UInt8(0))
        let b = (s[1].asciiValue ?? UInt8(0)) - (Character("0").asciiValue ?? UInt8(0))
        return (a + b) % 2 == 0
    }
}