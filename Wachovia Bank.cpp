#include<bits/stdc++.h>
using namespace std;

int dp[55][2005];
int w[55];
int cost[55];
int n,cap;


int napsack(int i,int we){

    if(i==n+1) return 0;
    if(dp[i][we]!=-1) return dp[i][we];

    int p1=0,p2=0;

    if(we+w[i]<=cap){
        p1 = cost[i] + napsack(i+1,we+w[i]);
    }

    p2 = napsack(i+1,we);

    return dp[i][we] = max(p1,p2);

}

int main(){

    int t;

    scanf("%d",&t);

    while(t--){
        memset(dp,-1,sizeof(dp));

        cin>>cap>>n;
        int a,b;
        for(int i=1;i<=n;i++){
            cin>>w[i]>>cost[i];
        }

        int x = napsack(1,0);

        printf("Hey stupid robber, you can get %d.\n",x);

    }


    return 0;

}




