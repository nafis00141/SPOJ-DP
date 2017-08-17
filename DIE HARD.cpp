#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005][5];

int f(int h,int a,int t){

    if(h<=0 || a<=0) return 0;

    if(dp[h][a][t]!=-1) return dp[h][a][t];

    int p1,p2,p3;
    p1=p2=p3=0;

    if(t==0){
        p1 = f(h+3,a+2,1);
        p2 = f(h-5,a-10,2);
        p3 = f(h-20,a+5,3);
    }
    else if(t==1){
        p2 = 1 + f(h-5,a-10,2);
        p3 = 1 + f(h-20,a+5,3);
    }
    else if(t==2){
        p1 = 1 + f(h+3,a+2,1);
        p3 = 1 + f(h-20,a+5,3);
    }
    else if(t==3){
        p1 = 1 + f(h+3,a+2,1);
        p2 = 1 + f(h-5,a-10,2);
    }

    return dp[h][a][t] = max(p1,max(p2,p3));

}

int main(){

    int t,h,a;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&h,&a);
        memset(dp,-1,sizeof(dp));
        cout<<f(h,a,0)<<"\n";
    }

}
