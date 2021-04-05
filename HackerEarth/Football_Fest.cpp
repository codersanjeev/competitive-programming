#include <bits/stdc++.h>
using namespace std;

int main(){

	int t, n, id, previd = 0, temp;
	char q;
	cin >>t;
	while(t--){

		cin >>n >>id;
		while(n--){

			cin >>q;
			if(q == 'P'){
				previd = id;
				cin >>id;
			}
			else{
				temp = id;
				id = previd;
				previd = temp;
			}

		}
		cout <<"Player " <<id <<endl;

	}

}