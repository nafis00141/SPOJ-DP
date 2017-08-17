#include<bits/stdc++.h>
using namespace std;

int s,n;

int c[1005];

int dp[1005][1005][2];

int f(int i,int ww,int take){

    if(i==n) return 0;

    if(dp[i][ww][take]!=-1) return dp[i][ww][take];

    int p1 = 0,p2 = 0;

    if(ww+c[i]<=s){
        if(take==0) p1 = c[i] + f(i+1,ww+c[i],1);
    }

    p2 = f(i+1,ww,0);

    dp[i][ww][take] = max(p1,p2);

}


int main(){

    int t;

    cin>>t;

    for(int ck=1;ck<=t;ck++){

        cin>>n>>s;

        for(int i=0;i<n;i++){
            cin>>c[i];
        }

        memset(dp,-1,sizeof(dp));

        printf("Scenario #%d: ",ck);

        cout<<f(0,0,0)<<"\n";

    }

}

