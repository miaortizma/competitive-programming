#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#ifdef PAPITAS
	#define DEBUG 1
#else
	#define DEBUG 0
#endif
#define _DO_(x) if(DEBUG) x

typedef pair<int,int> pii;
pii nodes[110];
vector<int> adj[110];
bool visited[110];

bool f(int a, int b, int c){
	return a < b && b < c;
}


bool dfs(int x, int y){
	visited[x] = true;
	bool ans = false;
	for(int i = 0; i < adj[x].size(); i++){
		if(adj[x][i] == y){
			ans = true;
			break;
		}
		if(!visited[adj[x][i]]){
			ans = ans || dfs(adj[x][i], y);
			if(ans) break;
		}
	}
	return ans;
}

bool check(int x, int y){
	memset(visited, false, sizeof(visited));
	return dfs(x, y);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int q, n = 0, c, x, y;
	cin >> q;
	while(q--){
		cin >> c >> x >> y;
		if(c == 1){
			for(int i = 0; i < n; i++){
				int a = nodes[i].first, b = nodes[i].second;
				if(f(x, a, y) || f(x, b, y)){
					adj[i].push_back(n);
				}
				if(f(a, x, b) || f(a, y, b)){
					adj[n].push_back(i);
				}
			}
			nodes[n++] = pii(x, y); 
		}else{
			if(check(x - 1, y - 1)){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
	}
	return 0;
}


