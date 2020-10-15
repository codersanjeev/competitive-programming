//CONTRIBUTE BY HRITIK MAHESHWARI





#include<bits/stdc++.h>
using namespace std;

int countDistinct(vector<int> arr, int n) 
{ 
    // First sort the array so that all 
    // occurrences become consecutive 
    sort(arr.begin(), arr.end()); 
  
    // Traverse the sorted array 
    int res = 0; 
    for (int i = 0; i < n; i++) { 
  
        // Move the index ahead while 
        // there are duplicates 
        while (i < n - 1 && arr[i] == arr[i + 1]) 
            i++; 
  
        res++; 
    } 
  
    return res; 
} 



int test(int t)
{
    if(t==0)
    {
        return 0;
        
    }
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int g;
        cin>>g;
        a.push_back(g);
    }
    int count=countDistinct(a,n);
   auto it = find (a.begin(), a.end(), 0); 
    if (it != a.end()) 
    { 
       cout<<count-1<<"\n"; 
    } 
    else
        cout<<count<<"\n";
        
    return test(--t);
}


int main()
{
    int t;
    cin>>t;
    test(t);
    return 0;
}
