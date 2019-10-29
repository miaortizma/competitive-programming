#include <bits/stdc++.h>
#define ll long long
#define ms(a,v) memset(a,v, sizeof(a))
using namespace std;
char keyb[55][55];
string word;

int dp[10001][51][51];
int dist[51][51][51][51];
bool vis[51][51];
vector<pair<int,int> > pos[300];
int n,m;
int sol(int p, int i, int j){
    if(p==0)
        return 0;
    char x=word[p-1];
    if(dp[p][i][j]!=-1)
        return dp[p][i][j];
    int ans=1000000000;
    for(pair<int,int> aux : pos[x] ){
        int dis=dist[i][j][aux.first][aux.second]+1;
        ans=min(ans,dis+sol(p-1,aux.first,aux.second));
    }
    dp[p][i][j]=ans;
    return ans;
}
void bfs(int x,int y){
    deque<tuple<int,int,int>> dq;
    dq.push_back(make_tuple(x, y, 0));
    ms(vis,-1);
    while(dq.size()>0){
        int i=get<0>(dq.front());
        int j=get<1>(dq.front());
        int p=get<2>(dq.front());
        dist[x][y][i][j]=p;
        vis[i][j]=true;
        int U,D,L,R;
        U=D=L=R=0;
        for(int j1=j+1;j1<m;j1++){
            if(keyb[i][j1]!=keyb[i][j1-1])
                break;
            L=j1-j;
        }
        for(int j1=j-1;j1>=0;j1--){
            if(keyb[i][j1]!=keyb[i][j1+1])
                break;
            R=j-j1;
        }
        for(int j1=i+1;j1<n;j1++){
            if(keyb[j1][j]!=keyb[j1-1][j])
                break;
            U=j1-i;
        }
        for(int j1=i-1;j1>=0;j1--){
            if(keyb[j1][j]!=keyb[j1+1][j])
                break;
            D=i-j1;
        }
        if(!vis[i+D][j]){
           dq.push_back(make_tuple(i+D,j,p+1));
           vis[i+D][j]=true;
        }
        if(!vis[i+U][j]){
           dq.push_back(make_tuple(i+U,j,p+1));
           vis[i+U][j]=true;
        }
        if(!vis[i][j+L]){
           dq.push_back(make_tuple(i,j+L,p+1));
           vis[i][j+L]=true;
        }

        if(!vis[i][j+R]){
           dq.push_back(make_tuple(i,j+R,p+1));
           vis[i][j+R]=true;
        }
    }

}
int main(){
    #ifdef LOCAl
        freopen("in.txt","r",stdin);
    #endif // LOCAl
    while(scanf("%d %d",&n,&m)==2){
        for(int i=0;i<n;i++)
        scanf("%s",keyb[i]);
        string qq;
        cin>>qq;
        word="";
        word.push_back(keyb[0][0]);
        word+=qq;
        cout<<word<<endl;
        ms(dp,-1);
        for(int i=0;i<300;i++)
            pos[i].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                pos[keyb[i][j]].push_back(make_pair(i,j));
                cout<<keyb[i][j]<<" "<<i<<" "<<j<<endl;
            }

        for(int i=0;i<n;i++){
            for(int i1=0;i1<n;i1++){
                for(int j=0;j<m;j++){
                    for(int j1=0;j1<m;j1++){

                        dist[i][j][i1][j1]=1000000000;
                    }

                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                bfs(i, j);
            }
        }
        int res=1000000008;
        for(pair<int,int> aux : pos['*'] ){
            res=min(res,sol(word.size()-1,aux.first,aux.second));
        }
        cout<<res+1<<endl;

    }
}
