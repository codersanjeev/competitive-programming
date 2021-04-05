vector<int> Solution::maxset(vector<int> &A) {
    int n = A.size();
    long curr = 0, global = 0, j = 0, start = 0, end = 0;
    if(all_of(A.begin(), A.end(), [](int i){
        return i < 0;
    })){
        return vector<int>(0);
    }
    for(long i = 0; i < n; i++){
        curr += A[i];
        if(curr > global){
            global = curr;
            start = j;
            end = i;
        }
        if(curr < 0 || A[i] < 0){
            j = i + 1;
            curr = 0;
        }
    }
    vector<int> ans;
    for(long i = start; i <= end; i++)
        ans.push_back(A[i]);
    long i = end + 1;
    while(i < n && A[i] == 0){
        ans.push_back(0);
        i++;
    }
    return ans;
}