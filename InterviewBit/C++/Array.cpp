/*
#include<iostream>
using namespace std;
*/

void reverseArray(int arr[], int N) {
    // Your code goes here
    int i = 0, j = N - 1;
    while (i < j) {
        swap(arr[i], arr[j]);
        ++i;
        --j;
    }
}

/*
int main()  {
    int N;
    cin>>N;
    int arr[N];
    for(int i = 0; i < N; i++){
        cin>>arr[i];
    }
    reverseArray(arr, N);
    for(int i = 0; i < N; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
*/