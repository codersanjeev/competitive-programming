class Solution {
    fun largestOddNumber(num: String): String {
        var index = num.length - 1
        while (index >= 0) {
            if ((num[index] - '0') % 2 == 1) break
            --index
        }
        return num.substring(0, index + 1)
    }
}