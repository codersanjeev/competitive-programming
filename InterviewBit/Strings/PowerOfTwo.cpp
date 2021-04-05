bool Not_one(string N) { //Checks if N is equal to 1 or not
    int sz = N.size();
    if(sz > 1)
            return 1;
    if(N[0] != '1')
            return 1;
    return 0;
}

bool is_Eve(string N) { //Checks if N is even or not
    int data = (N[N.size() - 1] - '0') & 1; //Bitwise AND operation 0 1 0 1 //binary for 5; N[index]
    if(data)                                //Binary for 6          0 1 1 0         & 1; 0 0 0 1
         return 0;                          //                      -------
    return 1;                               //Yields result:        0 1 0 0 //binary for 4 
}

string Divide(string N, int data) { //Divides the string by 2
    reverse(N.begin(), N.end());
    long long base = 10;
    string temp = "";
    for(int i = (int)N.size() - 1, rem = 0; i >= 0; --i) {
        long long Cur = (N[i] - '0') + rem * base;
        int val = Cur / data;
        rem = Cur % data;
        temp += (val + '0');
    }
    
    while(temp.size() && !(temp[0] - '0')) //Suppose temp = 00033; so temp is returned and assigned to N
            temp.erase(temp.begin());      //which is again sent to Divide(N,2) so now after reverse
                                           ///N = 33000 where this zeroes can be avaoided from computation.
    return temp;
}

int Solution::power(string N) {
    int sz = N.size();
    if(sz == 1) {
        if(N[0] == '2' || N[0] == '4' || N[0] == '8')
                return 1;
        return 0;
    } else {
        while(Not_one(N) && is_Eve(N)) {
            N = Divide(N, 2);
            if(N.size() == 1 &&  N[0] == '1')
                    break;
        }
        if(Not_one(N))
                return 0;
        return 1;
    }
}