#include<bits/stdc++.h>
using namespace std;

int a[100005],n;

long long dp[100005];

long long f(int i){

    if(i>=n) return 0;

    if(dp[i]!=-1) return dp[i];

    int rem = n - i;

    long long r1,r2,r3;

    r1 = r2 = r3 = 0;

    for(int j=1;j<4;j++){
        int k = min(j,rem);
        if(k==1) r1 =  a[i] + f(i+2);
        else if(k==2) r2 = a[i] + a[i+1] + f(i+4);
        else if(k==3) r3 = a[i] + a[i+1] + a[i+2] +  f(i+6);
    }

    return dp[i] = max(r1,max(r2,r3));

}

int main(){

    int t;

    cin>>t;

    while(t--){

        cin>>n;

        for(int i=0;i<n;i++)
            cin>>a[i];

        memset(dp,-1,sizeof(dp));

        cout<<f(0)<<"\n";

    }

    return 0;

}
