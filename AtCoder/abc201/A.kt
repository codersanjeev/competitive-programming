fun main() {
    var nums = readLine()!!.split(" ").map { it.toInt() }
    nums = nums.sorted()
    if (nums[1] - nums[0] == nums[2] - nums[1]) {
        print("Yes")
    } else {
        print("No")
    }
}