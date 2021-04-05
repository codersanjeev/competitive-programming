class Solution {
  public:
	int scheduleCourse(vector<vector<int>> &courses) {
		sort(courses.begin(), courses.end(), [](const vector<int> &x, const vector<int> &y) {
			return x[1] < y[1];
		});
		int currentTime = 0;
		priority_queue<int> pq;
		for (int i = 0; i < courses.size(); i++) {
			currentTime += courses[i][0];
			pq.push(courses[i][0]);
			if (currentTime > courses[i][1]) {
				currentTime -= pq.top();
				pq.pop();
			}
		}
		return pq.size();
	}
};