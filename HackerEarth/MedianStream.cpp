/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
 
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout <<#x <<" " <<x <<endl;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x;
    cin >>n;
    // using max heap for lower half
    priority_queue<int> left;
    // using min heap for upper half
    priority_queue<int, vector<int>, greater<int>> right;
    int current = 0;
    while(n--){
        cin >>x;
        // case 1 : left half has more elements
        if(left.size() > right.size()){
            // new element is less than current median
            if(x < current){
                // move one element from left heap to right heap
                right.push(left.top());
                left.pop();
                // add new element into left heap
                left.push(x);
            }
            // new element is greater than or equal to current median
            else{
                // everything is OK, right heap has less elements
                // and new element is greater than current median
                // so, add it in right heap.
                right.push(x);
            }
            // update median
            current = (left.top() + right.top()) / 2;
        }
        // case 2 : both heaps are balanced
        else if(left.size() == right.size()){
            // both heaps have same size, so just need to check if new element
            // is less than current median or greater and add accordingly
            if(x < current){
                left.push(x);
                current = left.top();
            }
            else{
                right.push(x);
                current = right.top();
            }
        }
        // case 3 : right heap has more number of elements
        else{
            if(x > current){
                // move one element from right heap to left heap
                left.push(right.top());
                right.pop();
                right.push(x);
            }
            else{
                left.push(x);
            }
            current = (left.top() + right.top()) / 2;
        }
        cout <<current <<endl;
    }
    return 0;
}
