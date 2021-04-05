#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1)

class Solution {
   public:
    Solution(double radius, double x_center, double y_center) {
        center.first = x_center;
        center.second = y_center;
        this->radius = radius;
    }

    vector<double> randPoint() {
        double theta = 2 * PI * random();
        double r = sqrt(random());
        return {center.first + r * radius * cos(theta), center.second + r * radius * sin(theta)};
    }

   private:
    pair<double, double> center;
    double radius;

    double random() {
        return (double)rand() / RAND_MAX;
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */