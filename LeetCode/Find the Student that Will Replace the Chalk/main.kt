class Solution {
    fun chalkReplacer(chalk: IntArray, k: Int): Int {
        var rem = k.rem(chalk.map{ it.toLong() }.sum().toLong())
        for (i in chalk.indices) {
            if (chalk[i] > rem) return i
            rem -= chalk[i]
        }
        return 0
    }
}