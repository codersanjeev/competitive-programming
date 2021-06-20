import kotlin.math.ceil
import kotlin.math.floor

class Solution {

    private fun convertHHMMToMinutes(s: String): Int {
        return 60 * s.substring(0, 2).toInt() + s.substring(3).toInt()
    }

    fun numberOfRounds(s: String, f: String): Int {
        val startTime = convertHHMMToMinutes(s).toDouble()
        var finishTime = convertHHMMToMinutes(f).toDouble()
        if (startTime > finishTime) finishTime += 24.0 * 60.0
        return (floor(finishTime / 15.0) - ceil(startTime / 15.0)).toInt()
    }
}
