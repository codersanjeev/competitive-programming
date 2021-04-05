class Solution {
   public:
    int numberOfDays(int Y, int M) {
        if (M != 2) {
            return days[M];
        } else if (isLeapYear(Y)) {
            return 29;
        } else {
            return 28;
        }
    }

   private:
    vector<int> days = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeapYear(int year) {
        if (year % 4 != 0) {
            return false;
        } else if (year % 100 != 0) {
            return true;
        } else if (year % 400 != 0) {
            return false;
        } else {
            return true;
        }
    }
};