#include<iostream>
#include<vector>
using namespace std;
int main(){
  int N,P,Pm,sum=1;
  cin >> N;
  for(int i=1;i<=N;i++){
    cin >> P;
    if(i==1){
      Pm=P;
      continue;
    }else{
      if(P<Pm){
        sum++;
        Pm=P;
      }else{
        continue;
      }
    }
  }
  cout << sum << endl;
}
