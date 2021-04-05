class Solution {
   public:
    vector<int> transformArray(vector<int>& arr) {
        int n = arr.size();
        while (true) {
            vector<int> temp = arr;
            for (int i = 1; i < n - 1; i++) {
                if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
                    temp[i]++;
                } else if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                    temp[i]--;
                }
            }
            if (arr == temp) {
                break;
            }
            arr = temp;
        }
        return arr;
    }
};