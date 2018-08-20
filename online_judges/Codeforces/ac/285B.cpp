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

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, s, t;
	cin >> n >> s >> t;
	int adj[n];
	for(int i = 0; i < n; i++) cin >> adj[i];
	bool visited[n];
	memset(visited, false, sizeof(visited));
	int u = s;
	int i = 0;
	while(u != t && visited[u-1] != true){
		visited[u-1] = true;
		u = adj[u-1];
		i++;
	}
	if(u != t){
		cout << "-1";
	}else{
		cout << i; 
	}
	return 0;
}
