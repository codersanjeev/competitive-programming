#include<bits/stdc++.h>
using namespace std;

int prime[1000100] = {0};

void sieve(){
    prime[0] = prime[1] = 1;
    for(long long i = 2; i <= sqrt(1000100); i++)
        if(prime[i] == 0)
            for(long long j = i*i; j <= 1000100; j += i)
                prime[j] = 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t, n;
    sieve();
    cin >>t;
    vector<long long> primes;
    for(long long i = 0; i <= 1000100; i++){
        if(prime[i] == 0 && i%11 == 1)
            primes.push_back(i);
    }
    while(t--){
        cin >>n;
        cout << (*lower_bound(primes.begin(), primes.end(), n)) <<"\n";
        
    }
    return 0;
}