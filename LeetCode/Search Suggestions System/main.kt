data class Trie(
    var children: HashMap<Char, Trie> = HashMap(),
    var suggestion: ArrayList<String> = ArrayList()
)

class Solution {
    fun suggestedProducts(products: Array<String>, word: String): List<List<String>> {
        products.sort()
        var trie: Trie? = Trie()
        products.forEach { product ->
            var node = trie
            product.forEach { ch ->
                node?.children?.get(ch)?.let {
                    node = it
                } ?: run {
                    val newNode = Trie()
                    node?.children?.set(ch, newNode)
                    node = newNode
                }
                if ((node?.suggestion?.size ?: 3) < 3) {
                    node?.suggestion?.add(product) 
                }
            }
        }
        val ans = ArrayList<List<String>>()
        word.forEach { ch ->
            if (trie != null) {
                trie = trie?.children?.get(ch)
                if (trie == null) {
                    ans.add(emptyList())
                } else {
                    trie?.suggestion?.let { ans.add(it) }
                }
            } else {
                ans.add(emptyList())
            }
        }
        return ans
    }
}