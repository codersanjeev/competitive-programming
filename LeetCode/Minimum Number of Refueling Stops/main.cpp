class Solution {
   public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (startFuel >= target) return 0;
        priority_queue<int> maxHeap;
        int previousStationPosition = 0, refuelingDone = 0;
        for (const auto& station : stations) {
            startFuel -= station[0] - previousStationPosition;
            previousStationPosition = station[0];
            while (startFuel < 0 && !maxHeap.empty()) {
                startFuel += maxHeap.top();
                maxHeap.pop();
                ++refuelingDone;
            }
            if (startFuel < 0) return -1;
            maxHeap.push(station[1]);
        }
        startFuel -= target - previousStationPosition;
        while (startFuel < 0 && !maxHeap.empty()) {
            startFuel += maxHeap.top();
            maxHeap.pop();
            ++refuelingDone;
        }
        return startFuel < 0 ? -1 : refuelingDone;
    }
};