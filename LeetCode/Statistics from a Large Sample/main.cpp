#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<double> sampleStats(vector<int>& count) {
        vector<double> ans;
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                ans.push_back(i);
                break;
            }
        }
        for (int i = 255; i >= 0; i--) {
            if (count[i] > 0) {
                ans.push_back(i);
                break;
            }
        }
        long double sm = 0, cnt = 0;
        for (int i = 0; i < 256; i++) {
            if (count[i] > 0) {
                sm += ((long)i * (long)count[i]);
                cnt += count[i];
            }
        }
        ans.push_back(sm / cnt);
        double median = 0;
        if ((int)cnt % 2 == 0) {
            int x = (int)cnt / 2;
            int curr = 0;
            for (int i = 0; i < 256; i++) {
                if (curr + count[i] >= x) {
                    median += i;
                    break;
                }
                curr += count[i];
            }
            curr = 0;
            for (int i = 0; i < 256; i++) {
                if (curr + count[i] >= x + 1) {
                    median += i;
                    break;
                }
                curr += count[i];
            }
            median /= 2;
        } else {
            int x = (int)cnt / 2;
            int curr = 0;
            for (int i = 0; i < 256; i++) {
                if (curr + count[i] >= x + 1) {
                    median += i;
                    break;
                }
                curr += count[i];
            }
        }
        ans.push_back(median);
        int mx = 0, mode = 0;
        for (int i = 0; i < 256; i++) {
            if (count[i] > mx) {
                mx = count[i];
                mode = i;
            }
        }
        ans.push_back(mode);
        return ans;
    }
};