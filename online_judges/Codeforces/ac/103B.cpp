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

bool visited[110][110];
bool nvisited[110];
int parent[110];
int c = 0;
vector<int> adj[110];

vector< vector<int> > cycles;

void cycle(int u, vector<int> path){
	c++;
	vector<int> edg = adj[u];
	nvisited[u] = true;
	for(int i = 0; i < edg.size(); i++){
		if(!visited[u][edg[i]]){	
			visited[u][edg[i]] = true;
			visited[edg[i]][u] = true;
			vector<int> next = path;
			next.push_back(edg[i]);	
			if(!nvisited[edg[i]]){
				cycle(edg[i], next);
			}else{	
				cycles.push_back(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, m, a, b;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> path;
	path.push_back(1);
	cycle(1, path);
	if(cycles.size() == 1 && c == n){
		/*vector<int> cycle = cycles[0];
		int s = cycle[cycle.size() - 1];
		int i = cycle.size() - 2;*/
		cout << "FHTAGN!";
	}else{
		cout << "NO";
	}
	return 0;
}


