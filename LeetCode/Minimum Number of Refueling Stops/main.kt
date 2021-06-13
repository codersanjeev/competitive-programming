class Solution {
    fun minRefuelStops(target: Int, s: Int, stations: Array<IntArray>): Int {
        var startFuel = s
        if (startFuel >= target) return 0
        val maxHeap = PriorityQueue<Int>(Collections.reverseOrder())
        var (previousStationPosition, refuelingDone) = arrayOf(0, 0)
        for (station in stations) {
            startFuel -= station[0] - previousStationPosition
            previousStationPosition = station[0]
            while (startFuel < 0 && maxHeap.isNotEmpty()) {
                maxHeap.poll()?.let { startFuel += it }
                ++refuelingDone
            }
            if (startFuel < 0) return -1
            maxHeap.add(station[1])
        }
        startFuel -= target - previousStationPosition
        while (startFuel < 0 && maxHeap.isNotEmpty()) {
            maxHeap.poll()?.let { startFuel += it }
            ++refuelingDone
        }
        return if (startFuel < 0) -1 else refuelingDone
    }
}