class OrderedStream {
public:
    OrderedStream(int n) {
        this->n = n;
        idx = 0;
        arr.resize(n, "");
    }
    
    vector<string> insert(int id, string value) {
        arr[id - 1] = value;
        vector<string> ans;
        while (idx < arr.size()) {
            if (arr[idx] == "") {
                break;
            }
            ans.push_back(arr[idx]);
            idx++;
        }
        return ans;
    }
private:
    int n, idx;
    vector<string> arr;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */