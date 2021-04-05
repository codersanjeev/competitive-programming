#include <bits/stdc++.h>
using namespace std;
long long readInt(long long l,long long r,char endd){
    long long x=0;
    int cnt=0;
    int fi=-1;
    bool is_neg=false;
    while(true){
	char g=getchar();
	if(g=='-'){
	    assert(fi==-1);
	    is_neg=true;
	    continue;
	}
	if('0'<=g && g<='9'){
	    x*=10;
	    x+=g-'0';
	    if(cnt==0){
	        fi=g-'0';
	    }
	    cnt++;
	    assert(fi!=0 || cnt==1);
	    assert(fi!=0 || is_neg==false);

	    assert(!(cnt>19 || ( cnt==19 && fi>1) ));
	} else if(g==endd){
	    assert(cnt>0);
	    if(is_neg){
	        x= -x;
	    }
	    assert(l<=x && x<=r);
	    return x;
	} else {
	    assert(false);
	}
    }
}
string readString(int l,int r,char endd){
    string ret="";
    int cnt=0;
    while(true){
	char g=getchar();
	assert(g!=-1);
	if(g==endd){
	    break;
	}
	cnt++;
	ret+=g;
    }
    assert(l<=cnt && cnt<=r);
    return ret;
}
long long readIntSp(long long l,long long r){
    return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
    return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
    return readString(l,r,'\n');
}
string readStringSp(int l,int r){
    return readString(l,r,' ');
}
map<string,int> mp;
string a[1000],b[1000];
int main()
{
    int t = readIntLn(1,100);
    while(t--)
    {
	mp.clear();
	int n = readIntLn(1,100);
	for (int i=1;i<=n;i++) {
	    a[i]=readStringSp(1,10);
	    b[i]=readStringLn(1,10);
	    mp[a[i]]++;
	}
	for (int i=1;i<=n;i++)
	    if (mp[a[i]]==1)
	        cout<<a[i]<<endl;
	    else
	        cout<<a[i]<<' '<<b[i]<<endl;
    }
    assert(getchar()==-1);
}
