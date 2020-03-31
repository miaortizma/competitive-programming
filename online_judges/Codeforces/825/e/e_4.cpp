#include <bits/stdc++.h>
using namespace std;
#define ll long long
#ifdef PAPITAS
	#define DEBUG 1
#else
	#define DEBUG 0
#endif
#define _DO_(x) if(DEBUG) x

stack<int> st;
const int nmax = 1e5;
bool visited[nmax+1];
int comp[nmax+1], c = 0;
vector<int> adj[nmax+1];

void dfs(int n){
	visited[n] = true;
	for(int v : adj[n]){
		if(!visited[v]){
			dfs(v);
		}
	}
	comp[n] = c;
	st.push(n);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#else
		//asdads
	#endif
	int n, m, a, b;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
	}
	for(int i = 1; i <= n; i++){
		sort(adj[i].rbegin(), adj[i].rend());
	}
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	vector<int> topsort(n+1);
	for(int i = 1; i <= n; i++){
		topsort[i] = st.top(); st.pop();
	}
	memset(visited, false, sizeof(visited)); 
	vector< vector<int> > comptopsort;
	for(int i = 1; i <= n; i++){
		if(!visited[topsort[i]]){
			dfs(topsort[i]);
			c++;
			vector<int> next;
			while(st.size()){
				next.push_back(st.top()); st.pop();
			}
			comptopsort.push_back(next);
		}
	}
	int cnt = 1;
	int ans[n+1];
	memset(visited,false, sizeof(visited));
	for(int i = 1; i <= n; i++){
		if(!visited[comp[i]]){
			visited[comp[i]] = true;
			for(int val : comptopsort[comp[i]]){
				ans[val] = cnt++;
			}
		}
	}
	/*vector< int > topsort;
	vector< int > toppos;
	for(int i = 1; i < n; i++){
		for(int v : adj[topsort[i - 1]]){
			if(v == st.top()){
				ok = true;
			}
		}
		if(!ok){
			toppos.push_back(i);
		}
		topsort.push_back(st.top());
		st.pop();
	}
	toppos.push_back(n);
	for(int i = toppos.size() - 2; i >= 0; i--){
		_DO_(cout << toppos[i] << ' ' << toppos[i+1] << '\n');
		for(int j = toppos[i]; j < toppos[i+1]; j++){
			ans[topsort[j]] = cnt++;
		}
	}*/
	for(int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}

 
