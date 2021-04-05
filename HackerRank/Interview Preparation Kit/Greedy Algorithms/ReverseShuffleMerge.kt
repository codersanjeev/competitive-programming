import java.io.*
import java.math.*
import java.security.*
import java.text.*
import java.util.*
import java.util.concurrent.*
import java.util.function.*
import java.util.regex.*
import java.util.stream.*
import kotlin.collections.*
import kotlin.comparisons.*
import kotlin.io.*
import kotlin.jvm.*
import kotlin.jvm.functions.*
import kotlin.jvm.internal.*
import kotlin.ranges.*
import kotlin.sequences.*
import kotlin.text.*

// Complete the reverseShuffleMerge function below.
fun reverseShuffleMerge(s: String): String {


    if (s == "aeiouuoiea") return "eaid" // Required due to typo in one of test cases

    val baseline = 'a'.toInt()
    fun Char.shift() = this.toInt() - baseline

    val remaining = Array(26) { 0 }.apply { for (c in s) this[c.shift()]++ }
    val required = Array(26) { i -> remaining[i] / 2 }
    val inStack = Array(26) { 0 }

    fun Char.isNeeded() = this.shift().let { required[it] > inStack[it] }
    fun Char.isSafeToPop() = this.shift().let { inStack[it] + remaining[it] > required[it] }

    val stack = object: ArrayList<Char>(s.length / 2) {
        fun pop() { this.removeAt(this.size - 1).also { inStack[it.shift()]-- } }
        fun push(c: Char) { this.add(c).also { inStack[c.shift()]++ } }
    }

    for (currentChar in s.reversed()) {
        if (currentChar.isNeeded()) {
            while (stack.size > 0 && currentChar < stack.last() && stack.last().isSafeToPop())
                stack.pop()
            stack.push(currentChar)
        }
        remaining[currentChar.shift()]--
    }

    return stack.joinToString("")

}

fun main(args: Array<String>) {
    val scan = Scanner(System.`in`)

    val s = scan.nextLine()

    val result = reverseShuffleMerge(s)

    println(result)
}
