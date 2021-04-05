auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination) swap(start, destination);
        int x = 0, y = 0;
        for (int i = start; i != destination; i++) {
        	x += distance[i];
        }
        for (int i = destination; i != start; i = (i + 1) % distance.size()) {
        	y += distance[i];
        }
        return min(x, y);
    }
};