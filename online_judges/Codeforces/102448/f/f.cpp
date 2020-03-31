///By Stephan Ramirez dsramirezc@unal.edu.co
#include<bits/stdc++.h>
#define ms(a,v) memset(a,v,sizeof a)
#define ll long long
#define ALPHA 26
#define N 1000105
using namespace std;
int n;
int l,r;
ll h[N+2];
bool in[N+2];
bool out[N+2];
vector<pair<int,int> > v;
int main(){
	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d %d %lld",&l,&r,&h[i]);
        v.push_back({l,i});
        v.push_back({r,i});
    }
    sort(v.begin(),v.end());
    priority_queue<pair<ll,int> > pq;
    pq.push({0,N});
    pq.push({h[v[0].second],v[0].second});
    int l=v[0].first;
    in[v[0].second]=true;
    ll ans=0;
    for(int  i=1;i<v.size();i++){
        //cout<<l<<endl;
        if(!in[v[i].second]){
            ll dist=v[i].first-l;
            ans+=dist*pq.top().first;
            pq.push({h[v[i].second],v[i].second});
            in[v[i].second]=true;
        }else{
            out[v[i].second]=true;
            ll dist=v[i].first-l;
            ans+=dist*pq.top().first;
        }
        l=v[i].first;
        while(pq.size()>0 && out[pq.top().second]){
            pq.pop();
        }

    }
    cout<<ans<<endl;
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
