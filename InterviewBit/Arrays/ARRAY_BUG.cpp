vector<int> Solution::rotateArray(vector<int> &A, int B) {
    vector<int> ret; 
    for (int i = 0; i < A.size(); i++) {
        ret.push_back(A[(i + B) % A.size()]);
    }
    return ret; 
}
