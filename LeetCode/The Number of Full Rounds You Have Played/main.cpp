class Solution {
   private:
    int convertHHMMToMinutes(const string &s) {
        return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3));
    }

   public:
    int numberOfRounds(string s, string f) {
        double startTime = (double)convertHHMMToMinutes(s);
        double finishTime = (double)convertHHMMToMinutes(f);
        if (startTime > finishTime) finishTime += 24.0 * 60.0;
        return floor(finishTime / 15.0) - ceil(startTime / 15.0);
    }
};