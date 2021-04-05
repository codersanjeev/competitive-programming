#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string reformatNumber(const string &number) {
        string ans = "";
        for (const auto &ele : number) {
            if (ele != ' ' && ele != '-') {
                ans += ele;
            }
        }
        return format(ans);
    }

    string format(const string &number) {
        if (number.size() >= 4) {
            int digits = number.size() > 4 ? 3 : 2;
            return number.substr(0, digits) + "-" + reformatNumber(number.substr(digits));
        } else {
            return number;
        }
    }
};