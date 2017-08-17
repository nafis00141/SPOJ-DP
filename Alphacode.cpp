#include<bits/stdc++.h>
using namespace std;

int n;

string s;

int dp[5000+10][2];

int f(int i,int k){

    if(i==n){
        return 1;
    }

    if(dp[i][k]!=-1) return dp[i][k];

    int p1,p2;

    p1=p2=0;

    if(s[i]!='0')
        p1 = f(i+1,0);

    if(i>0 && (s[i-1]=='0' || s[i-1]=='1')  && s[i]<='9' && k==0){
        p2 = f(i+1,1);
    }
    else if(i>0 && s[i-1]=='2' && s[i]<='6' && k==0){
        p2 = f(i+1,1);
    }

    return dp[i][k] = p1+p2;

}

int main(){

    while(cin>>s){
        if(s=="0") break;
        n = s.size();
        memset(dp,-1,sizeof(dp));
        cout<<f(0,0)<<"\n";
    }

}
