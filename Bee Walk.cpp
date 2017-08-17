#include<bits/stdc++.h>
using namespace std;

int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonal Direction

int dp[100][100][16];


int f(int x,int y,int n){

    if(n==0 && x==50 && y==50) return 1;
    else if(n==0) return 0;

    if(dp[x][y][n]!=-1) return dp[x][y][n];

    int num = 0;

    for(int i=0;i<6;i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        num = num + f(xx,yy,n-1);
    }

    return dp[x][y][n] = num;


}

int main(){

    int t,n;

    cin>>t;

    memset(dp,-1,sizeof(dp));

    while(t--){
        cin>>n;

        if(n==1){
            cout<<"0\n";
            continue;
        }

        cout<<f(50,50,n)<<"\n";
    }

}
