#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	double r;
	cin >>t;
	int x[3], y[3];
	double dist[3];
	while(t--){
		cin >>r;
		for(int i = 0; i < 3; i++)
			cin >>x[i] >>y[i];
		dist[0] = sqrt(((x[1] - x[0])*(x[1] - x[0])) + ((y[1]-y[0])*(y[1]-y[0])));
		dist[1] = sqrt(((x[2] - x[1])*(x[2] - x[1])) + ((y[2]-y[1])*(y[2]-y[1])));
		dist[2] = sqrt(((x[2] - x[0])*(x[2] - x[0])) + ((y[2]-y[0])*(y[2]-y[0])));
		if(dist[0] > r && dist[1] > r && dist[2] > r){
			cout <<"no\n";
		}
		else if(dist[0] > r && dist[1] > r){
			cout <<"no\n";
		}
		else if(dist[1] > r && dist[2] > r){
			cout <<"no\n";
		}
		else if(dist[0] > r && dist[2] > r){
			cout <<"no\n";
		}
		else{
			cout <<"yes\n";
		}
	}
	return 0;
}