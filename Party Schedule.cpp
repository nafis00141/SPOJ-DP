#include<bits/stdc++.h>
using namespace std;

int dp[105][500*105];
int dir[105][500*105];
int w[105];
int cost[105];
int n,cap,z;


int napsack(int i,int we){

    if(i==n+1) return 0;
    if(dp[i][we]!=-1) return dp[i][we];

    int p1=0,p2=0;

    if(we+w[i]<=cap){
        p1 = cost[i] + napsack(i+1,we+w[i]);
    }

    p2 = napsack(i+1,we);

    if(p1>p2){
        dp[i][we]=p1;
        dir[i][we]=1;
    }
    else{
        dp[i][we]=p2;
        dir[i][we]=2;
    }

    return dp[i][we];

}

void pri(int i,int we){

    if(dir[i][we]==1){
        z=z+w[i];
        pri(i+1,we+w[i]);
    }
    else if(dir[i][we]==2){
        pri(i+1,we);
    }
    else if(dir[i][we]==-1) return;

}

int main(){
    int p;
    while(cin>>cap>>n){
        if(n==0 && cap==0) break;

        memset(dp,-1,sizeof(dp));
        memset(dir,-1,sizeof(dir));

        for(int i=1;i<=n;i++){
            cin>>w[i]>>cost[i];
        }

        p = napsack(1,0);
        z=0;
        pri(1,0);
        cout<<z<<" "<<p<<"\n";
    }

    return 0;

}



