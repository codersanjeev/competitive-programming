#include <bits/stdc++.h>
using namespace std;

int strlen(char A[]){
	int i = 0;
	while(A[i]!='\0' && A[i]!='\n')
		i++;
	return i;
}

void done(char A[],char B[],int C[]){
    int n = strlen(A);
    B[n-1] = A[n-1];
    C[n-1] = n-1;
    for(int i=n-2;i>=0;i--){
        if(A[i]<=B[i+1]){
            B[i] = A[i];
            C[i] = i;
        }
        else{
            B[i] = B[i+1];
            C[i] = C[i+1];
        }
    }
}


int main(){

	char S[100001];
	scanf("%s",S);

	stack<char> T;
	list<char> U;
	int n = strlen(S);
	char B[n];
	int C[n];
	done(S,B,C);
	char m;
	int index;
	int i = 0;
	while(i<n){
		if(!T.empty()){
			m = T.top();
			index = -1;
		}
		else{
			m = S[i];
			index = i;
		}
		//printf("#%d %c %c\n",i,B[i],m);
		if(B[i]<m){
		    //printf("#%d %c %c\n",i,B[i],m);
		    /*
    		for(int j=i;j<n;j++){
	    		if(S[j]<m){
		    		m = S[j];
			    	index = j;
			    }
    		}
    		*/
    		if(B[i]<m){
    		    m = B[i];
    		    index = C[i];
    		}
		}
		if(index==-1){
			U.push_back(T.top());
			T.pop();
		}
		else{
			for(int j=i;j<index;j++){
				T.push(S[j]);
			}
			U.push_back(S[index]);
			i  = index + 1;
		}
	}

	while(!T.empty()){
		U.push_back(T.top());
		T.pop();
	}

	list<char> ::iterator itr;
	for(itr=U.begin();itr!=U.end();itr++){
		printf("%c",*itr);
	}


	return 0;
}