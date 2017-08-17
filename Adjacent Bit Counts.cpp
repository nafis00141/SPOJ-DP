#include<bits/stdc++.h>
using namespace std;

int n,k;
int dp[2][105][105];

int f(int lb,int i,int num){

    if(i==n){
        if(num==k) return 1;
        else return 0;
    }


    if(dp[lb][i][num]!=-1) return dp[lb][i][num];

    int p1,p2;
    p1=p2=0;

    if(i==0){
        p1 = f(1,i+1,0);
        p2 = f(0,i+1,0);
    }
    else{
        if(lb==1){
            p1 = f(1,i+1,num+1);
            p2 = f(0,i+1,num);
        }
        else{
            p1 = f(1,i+1,num);
            p2 = f(0,i+1,num);
        }
    }

    return dp[lb][i][num] = p1+p2;

}


int main(){

    int t,a;

    scanf("%d",&t);

    while(t--){
        scanf("%d %d %d",&a,&n,&k);
        memset(dp,-1,sizeof(dp));
        printf("%d %d\n",a,f(0,0,0));
    }

}

