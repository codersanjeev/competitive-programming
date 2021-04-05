class Rectangle {
  private:
	pair<int, int> bottom, top;
  public:
	Rectangle(int bx, int by, int tx, int ty) {
		bottom.first = bx;
		bottom.second = by;
		top.first = tx;
		top.second = ty;
	}

	int getArea() {
		if (top.first < bottom.first || top.second < bottom.second) {
			return 0;
		} else {
			return (top.first - bottom.first) * (top.second - bottom.second);
		}
	}

};

class Solution {
  public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		Rectangle *x = new Rectangle(A, B, C, D);
		Rectangle *y = new Rectangle(E, F, G, H);
		Rectangle *z = new Rectangle(max(A, E), max(B, F), min(C, G), min(D, H));
		return x->getArea() - z->getArea() + y->getArea();
	}
};