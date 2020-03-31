///By Stephan Ramirez dsramirezc@unal.edu.co
#include<bits/stdc++.h>
#define ms(a,v) memset(a,v,sizeof a)
#define ll long long
#define ALPHA 26
#define N 1000105
using namespace std;
ll n,m,k;
ll burn[N];
vector<pair<ll,ll> > adj[N];
ll t[N];
priority_queue<pair<ll,ll> ,vector<pair<ll,ll> >,greater<pair<ll,ll> > > pq;

int main(){

	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		//freop en("out.txt","w",stdout);
	#endif
    scanf("%lld %lld %lld",&n,&m,&k);
    for(int i=0;i<m;i++){
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i=0;i<n;i++)
        scanf("%lld",&t[i+1]);
    for(int i=0;i<k;i++){
        ll node;
        scanf("%lld",&node);
        pq.push({0,node});
    }
    while(pq.size()>0){
        pair<ll,ll> x=pq.top();
        pq.pop();
        if(burn[x.second]!=0)
            continue;
        burn[x.second]=x.first+t[x.second];
        for(pair<ll,ll> i : adj[x.second]){
            if(burn[i.first]==0){
                pq.push({x.first+t[x.second]+i.second,i.first,});
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%lld\n",burn[i]);
	return 0;
}
/*
int nodes=0;
int trie[N][ALPHA];
int cnt[N];
int id[N];
int n,k;
string arr[N];
string word,s;
int idx;
void add( int op){
    int curNode=0;
    for(char i : s){
        if(trie[curNode][i-'a']==0){
            nodes++;
            trie[curNode][i-'a']=nodes;
        }
        curNode=trie[curNode][i-'a'];
        cnt[curNode]+=op;
    }
    id[curNode]=idx;
}
int ans=N;
int auxAns=N;
void sol( int node,int pos ,int dep){
    if(pos<word.size()){
        if( cnt[trie[node][word[pos]-'a']]<=0 ){
            ans=-1;
            auxAns=-1;
            return;
        }else{
            sol(trie[node][word[pos]-'a'],pos+1,dep+1);
            return;
        }
    }else{
        if(dep>=auxAns)
            return;
        if( id[node]!=-1){
            ans=id[node];
            auxAns=dep;
            return;
        }
        for(int i=0;i<ALPHA;i++){
            if( cnt[trie[node][i]]>0){
                sol(trie[node][i],pos,dep+1);
            }
        }
    }
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
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
            auxAns=N;
            sol(0,0,0);
            cout<<ans<<'\n';
        }
    }
	return 0;

}
*/
