#include<bits/stdc++.h>
using namespace std;

map<long long,long long>dp;

long long f(long long n){

    if(n==0) return 0;
    if(n==1) return 1;

    if(dp.find(n)!=dp.end()) return dp[n];

    long long k = f(n/2) + f(n/3) + f(n/4);

    return dp[n] = max(n,k);

}


int main(){

    long long n;

    while(scanf("%lld",&n)!=EOF){
        cout<<f(n)<<"\n";
    }

}
