class Solution {
   public:
    string similarRGB(string color) {
        return "#" + similarRGBHelper(color.substr(1, 2)) + similarRGBHelper(color.substr(3, 2)) + similarRGBHelper(color.substr(5, 2));
    }

   private:
    string similarRGBHelper(string color) {
        int q = (stoi(color, 0, 16) + 8) / 17;
        return string(2, q < 10 ? q + '0' : q + 'a' - 10);
    }
};