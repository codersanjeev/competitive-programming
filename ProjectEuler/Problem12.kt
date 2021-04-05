import java.io.*
import java.util.*
import java.math.*
object Solution {
  internal fun factor(a:Int):Int {
    val count = 0
    if (a == 1)
    {
      return 1
    }
    val i = 1
    while (i < Math.ceil(Math.sqrt(a.toDouble())))
    {
      if (a % i == 0)
      {
        count += 2
      }
      i++
    }
    if ((Math.ceil(Math.sqrt(a.toDouble()))) == Math.floor(Math.sqrt(a.toDouble())))
    {
      count++
    }
    return count
  }
  @JvmStatic fun main(args:Array<String>) {
    val arr = IntArray(1001)
    val temp = 0
    val box = 0
    for (i in 1..1000)
    {
      while (temp <= i)
      {
        box++
        temp = factor(((box) * (box + 1)) / 2)
      }
      arr[i] = ((box) * (box + 1)) / 2
    }
    val sc = Scanner(System.`in`)
    val test = sc.nextInt()
    while (test-- > 0)
    {
      val n = sc.nextInt()
      println(arr[n])
    }
  }
}