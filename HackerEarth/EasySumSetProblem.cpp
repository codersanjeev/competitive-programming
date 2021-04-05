#include<bits/stdc++.h>
using namespace std;

bool checkElement(int arr[], int size, int ele){
    for(int i = 0; i < size; i++){
        if(arr[i] == ele)
            return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >>n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >>a[i];
    cin >>m;
    int c[m];
    for(int i = 0; i < m;  i++)
        cin >>c[i];
    vector<int> b;
    for(int i = 1; i <= 100; i++){
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(!checkElement(c, m, i+a[j])){
                flag = false;
                break;
            }
        }
        if(flag){
            b.push_back(i);
        }
    }
    for(int i = 0; i < b.size(); i++)
        cout <<b[i] <<" ";
    return 0;
}