#include<bits/stdc++.h>
using namespace std;

string s;

int dp[6105][6105];

int f(int i,int j){

    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(s[i]==s[j]) return dp[i][j] = f(i+1,j-1);
    else{

      int p1,p2;

      p1 = p2 = 0;

      p1 = f(i,j-1);

      p2 = f(i+1,j);

      return dp[i][j]  = 1 + min(p1,p2);

    }

}


int main(){

    int t;

    cin>>t;

    while(t--){
        cin>>s;

        memset(dp,-1,sizeof(dp));

        int l = s.size();

        printf("%d\n",f(0,l-1));

    }
}
