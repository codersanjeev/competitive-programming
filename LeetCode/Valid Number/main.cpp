class Solution {
   public:
    bool isNumber(string s) {
        regex number("^[+-]?((\\d+\\.?\\d*)|(\\d*\\.?\\d+))([eE][+-]?\\d+)?$");
        return regex_match(s, number);
    }
};