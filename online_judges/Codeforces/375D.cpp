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

const int nmax = (int) 1e5;
int n, m, a, b, t;
int color[nmax], start[nmax], end_[nmax], subtree[nmax];
vector<int>  adj[nmax];

void dfs(int u){
	cout << u << ' ';
	subtree[t] = color[u];
	start[u] = t++;
	for(int v : adj[u]){
		dfs(v);
	}
	end_[u] = t;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> color[i];	
	}
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
	}
	dfs(0);
	cout << '\n';
	for(int i = 0; i < n; i++){
		cout << subtree[i] << ' ';
	}
	cout << "\nstart\n";
	for(int i = 0; i < n; i++){
		cout << start[i] << ' ';
	}
	cout << "\nend\n";
	for(int i = 0; i < n; i++){
		cout << end_[i] - 1<< ' ';
	}
	cout << '\n';
	return 0;
}

