 /*************************************************
 *                                                *
 * author    :    Sanjeev Sharma                  *
 * GitHub    :    github.com/thedevelopersanjeev  *
 * Contact   :    thedevelopersanjeev@gmail.com   *
 *                                                *
 *************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	char c;
	cin >>str;
	if(str == "?"){
	    cout <<"a";
	}
	else{
	    for(int i=0; i<str.length(); i++){
	    c = str.at(i);
	    if(i == str.length()-1 && c == '?' && str.at(i-1) != 'a'){
	        // replace last character by 'a'
	        str[str.length()-1] = 'a';
	    }
	    else if(i == str.length()-1 && c == '?'){
	        // replace last character by 'b'
	        str[str.length()-1] = 'b';
	    }
	    else if(i == 0 && c == '?' && str.at(i+1) == 'a'){
	        // replace first character by 'b'
	        str[0] = 'b';
	    }
	    else if(i == 0 && c == '?'){
	        // replace first character by 'a'
	        str[0] = 'a';
	    }
	    else if(c == '?' && str.at(i-1) == 'a'){
	        // replace character at i by 'b'
	        str[i] = 'b';
	    }
	    else if(c == '?' && str.at(i+1) == 'a'){
	        // replace character at i by 'b'
	        str[i] = 'b';
	    }
	    else if(c == '?'){
	        // replace character at i by 'a'
	        str[i] = 'a';
	    }
	    else{
	        // do nothing
	    }
	}
	cout <<str;   
	}
	return 0;
}
