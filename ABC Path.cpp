/*
    Getsuga Tensho

    Don't look at my code its pure shit

    Nafis Islam

*/
#include<bits/stdc++.h>
using namespace std;

int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
int r,c;

int cost[55][55];

char a[55][55];

int dfs(int x,int y){

    if(cost[x][y]!=-1) return cost[x][y];

    for(int i=0;i<8;i++){

        int xx = x + dx[i];

        int yy = y + dy[i];

        if(xx>=0 && xx<r && yy>=0 && yy<c){

            if((a[xx][yy] - a[x][y]) == 1){

                if(cost[x][y] == -1){

                    cost[x][y] = 1 + dfs(xx,yy);

                }
                else cost[x][y] = max(cost[x][y] , 1+ dfs(xx,yy));

            }

        }

    }

    if(cost[x][y]==-1){

        cost[x][y] = 1;

    }

    return cost[x][y];

}

int main(){



    /*freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);*/

    //ios_base::sync_with_stdio(false);

    int Case = 0;

    while(cin>>r>>c){

        if(r==0 && c==0) break;

        queue<int>q;

        getchar();

        for(int i=0;i<r;i++){
            cin>>a[i];
        }


        for(int i=0;i<r;i++){

            for(int j=0;j<c;j++){

                if(a[i][j]=='A'){
                    q.push(i);
                    q.push(j);
                }

            }
        }


        memset(cost,-1,sizeof(cost));

        int ans = 0;
        int k = 1;


        while(q.empty()==false){

            int x = q.front();
            q.pop();

            int y = q.front();
            q.pop();

            int p = dfs(x,y);

            ans = max(ans,p);


        }


        printf("Case %d: %d\n",++Case,ans);


    }

}
