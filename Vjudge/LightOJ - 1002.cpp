#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

typedef pair<int,int> pii;


vector<pii> adj[501];
int dist[501];


void init(int n){
	for(int i = 0; i < n; i++){
		adj[i].clear();
		dist[i] = (int)1e9;
	}
}


void dijkstra(int s, vector<pii> adj[]){
	dist[s] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(pii(0,s));
	while(pq.size()){
		pii cur = pq.top(); pq.pop();
		int d = cur.first, u = cur.second;
		if(d > dist[u]) continue;
		for(int i = 0; i < adj[u].size(); i++){
            pii v = adj[u][i];
			if(max(d, v.first) < dist[v.second] ){
				dist[v.second] = max(d, v.first);
				pq.push(pii(dist[v.second], v.second));
			}
		}
	}
}



int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		int n, m, a , b, c, s;
		cin >> n >> m;
		init(n);
		for(int i = 0; i < m; i++){
			cin >> a >> b >> c;
			adj[a].push_back(pii(c, b));
			adj[b].push_back(pii(c, a));
		}
		cin >> s;
		cout << "Case " << t << ":\n";
		dijkstra(s, adj);
		for(int i = 0; i < n; i++){
			if(dist[i] == (int)1e9) cout << "Impossible\n";
			else cout << dist[i] << '\n';
		}
	}
	return 0;
}
