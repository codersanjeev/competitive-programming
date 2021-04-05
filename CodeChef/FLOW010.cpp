#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	char id;
	cin >>t;
	while(t--){
		cin >>id;
		switch(id){
			case 'B' :
			case 'b' :
			cout <<"BattleShip\n";
			break;
			case 'C' :
			case 'c' :
			cout <<"Cruiser\n";
			break;
			case 'D' :
			case 'd' :
			cout <<"Destroyer\n";
			break;
			case 'F' :
			case 'f' :
			cout <<"Frigate\n";
			break;
		}
	}
	return 0;
}