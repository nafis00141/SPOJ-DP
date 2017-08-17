#include<bits/stdc++.h>
using namespace std;

unsigned long long dp[105];

unsigned long long f(int n){

    if(n==0) return 0;

    if(dp[n]!=-1) return dp[n];

    return dp[n] = n*n + f(n-1);

}

int main(){

    int n;
    memset(dp,-1,sizeof(dp));
    while(cin>>n,n!=0){
        cout<<f(n)<<"\n";
    }

}
