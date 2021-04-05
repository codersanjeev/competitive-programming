class Solution {
public:
    int countStudents(vector<int>& A, vector<int>& B) {
        deque<int> students(A.begin(), A.end()), sandwiches(B.begin(), B.end());
        int idx = 0, cnt = 0;
        while (!students.empty() && cnt <= 10000) {
            cnt++;
            if (students[idx] == sandwiches[idx]) {
                students.pop_front();
                sandwiches.pop_front();
            } else {
                int curr = students.front();
                students.pop_front();
                students.push_back(curr);
            }
        }
        return students.size();
    }
};