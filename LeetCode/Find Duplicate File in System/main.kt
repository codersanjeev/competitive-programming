class Solution {
    fun findDuplicate(paths: Array<String>): List<List<String>> {
        val mp = hashMapOf<String, MutableList<String>>()
        val ans = mutableListOf<MutableList<String>>()
        paths.forEach { path ->
            val ss = path.split(" ")
            val directory = ss[0]
            for (i in 1 until ss.count()) {
                val s = ss[i]
                val index = s.indexOf("(")
                val fileName = s.substring(0, index)
                val fullName = "$directory/$fileName"
                val fileContents = s.substring(index + 1, s.indexOf(")"))
                mp[fileContents]?.add(fullName) ?: kotlin.run {
                    mp[fileContents] = mutableListOf(fullName)
                }
            }
        }
        mp.forEach { (_, value) ->
            if (value.size > 1) {
                ans.add(value)
            }
        }
        return ans
    }
}