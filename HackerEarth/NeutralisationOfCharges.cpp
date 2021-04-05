#include<iostream>
using namespace std;
#include<string>
 
int main(){
    int n;cin>>n;
    string s;int c=0;
    for(int i=0;i<n;i++)
    {
        char ch;cin>>ch;
        if(s.back()==ch){
            s.pop_back();
        }
        else{
            s.push_back(ch);
        }
        
    }
    cout<<s.length()<<endl<<s;
    
    
    
}