/*
https://practice.geeksforgeeks.org/problems/word-break/0
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;cin>>t;
	while (t--) {
		int n; cin>>n;
		vector<string> v(n);
		for (int i=0; i<n; i++) cin>>v[i];
		string key; cin>>key;
		
		unordered_map<string, bool> m;
		vector<string>::iterator k;
		int i1=0, i2=0, l=key.length();
		vector<string> found;
		
		for (i1=0; i1<l; ) {
			int currfoundsize = found.size();
			for (i2=i1; i2<l; ) {
				string s = key.substr(i1, i2-i1+1);
				int currfoundsize2 = found.size();
				// if found in the map
				if (m.count(s)) {
					cout<<"found: "<<s<<" from "<<i1<<" to "<<i2<<endl;
					i2++; i1=i2;
					found.push_back(s);
				}
				else {
					// not found in map
					for (k=v.begin(); k!=v.end(); k++) {
						if (*k == s) {
							cout<<"found: "<<s<<" from "<<i1<<" to "<<i2<<endl;
							found.push_back(s);
							m[s] = true;
							i2++; i1=i2;
						}
					}	 
				}
				// increment only if key not found
				if (found.size() == currfoundsize2) i2++;
			}
			// increment only if key not found
			if (found.size() == currfoundsize) i1++;
		}
		string temp = "";
		cout << "found vecor: ";
		for (k=found.begin(); k!=found.end(); k++) {
			temp = temp + *k;
			cout << *k;
		}
		cout << endl << "temp: "<<temp<< endl;
		cout << (temp==key) << endl;
	}
	return 0;
}