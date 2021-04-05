class Rectangle {
  private:
	pair<long long, long long> bottom, top;
  public:
	Rectangle(int bx, int by, int tx, int ty) {
		bottom.first = bx;
		bottom.second = by;
		top.first = tx;
		top.second = ty;
	}

	long long getArea() {
		if (top.first < bottom.first || top.second < bottom.second) {
			return 0;
		} else {
			return (top.first - bottom.first) * (top.second - bottom.second);
		}
	}

};

class Solution {
  public:
	bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2) {
		Rectangle *xy = new Rectangle(max(rec1[0], rec2[0]), max(rec1[1], rec2[1]), min(rec1[2], rec2[2]), min(rec1[3], rec2[3]));
		return xy->getArea() > 0;
	}
};