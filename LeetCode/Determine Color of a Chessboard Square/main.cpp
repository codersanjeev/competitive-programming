class Solution {
public:
    bool squareIsWhite(string s) {
        int a = s[0] - 'a';
        int b = s[1] - '0';
        return (a + b) % 2 == 0;
    }
};