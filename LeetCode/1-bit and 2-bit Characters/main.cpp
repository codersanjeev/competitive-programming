auto speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
    	int i = bits.size() - 2;
    	while (i >= 0 && bits[i] > 0) i--;
    	return (bits.size() - i) % 2 == 0;
    }
};