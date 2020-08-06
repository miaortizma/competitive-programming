///By Stephan Ramirez dsramirezc@unal.edu.co
#include<bits/stdc++.h>
#define ms(a,v) memset(a,v,sizeof a)
#define ll long long
#define ALPHA 26
#define N 1000105
using namespace std;


int nodes=0;
int trie[N][ALPHA];
int dp[N];
int res[N];
int cnt[N];
int id[N];
int depth[N];
int n,k;
string arr[N];
string word,s;
int idx;
void add( int op){
    int curNode=0;
    depth[curNode]=0;
    dp[curNode]=-1;
    int dep=1;
    for(char i : s){
        if(trie[curNode][i-'a']==0){
            nodes++;
            trie[curNode][i-'a']=nodes;
        }
        dp[curNode]=-1;
        curNode=trie[curNode][i-'a'];
        cnt[curNode]+=op;
        depth[curNode]=dep;
        dep++;
        dp[curNode]=-1;
    }
    id[curNode]=idx;
    if(op==-1)
        id[curNode]=-1;

}
int ans=N;
int go(int node){
    if(dp[node]!=-1)
        return dp[node];
    if(id[node]!=-1){
        dp[node]=depth[node];
        res[node]=id[node];
        return dp[node];
    }
    for(int i=0;i<ALPHA;i++){
        if(cnt[trie[node][i]]>0){
            if(dp[node]==-1 || dp[node]>go(trie[node][i])){
                dp[node]=go(trie[node][i]);
                res[node]=res[trie[node][i]];
            }
        }
    }

    if(dp[node]==-1){
        dp[node]=depth[node];
        res[node]=id[node];
    }
    return dp[node];
}
void sol( int node,int pos ,int dep){
    if(pos<word.size()){
        if( cnt[trie[node][word[pos]-'a']]<=0 ){
            ans=-1;
            return;
        }else{
            sol(trie[node][word[pos]-'a'],pos+1,dep+1);
            return;
        }
    }else{
        go(node);
        ans=res[node];
        return;
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	ms(dp,-1);
    cin>>n;
    ms(id,-1);
    for(int i=0; i<n;i++){
        idx=i+1;
        int type;
        cin>>type;
        if(type==1){
            cin>>s;
            arr[i+1]=s;
            add(1);
        }else if(type==2){
            int pos;
            cin>>pos;
            s=arr[pos];
            add(-1);
        }else{
            cin>>word;
            ans=N;
            sol(0,0,0);
            cout<<ans<<'\n';
        }
    }
	return 0;
}
