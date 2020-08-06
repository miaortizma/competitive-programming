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

const int NMAX = (int)1e5;
int N, M;
typedef pair<int,int> pii; 

vector<pii> edg;

void printTree(int m, int n, int k){
	if(M == 0 || n > N || m > N){
		return;
	}
	if(n != 1){
		edg.push_back(pii(n, m));
		M--;	
	}
	printTree(2*m - n, m, k + 1);	
	printTree(2*m + n, m, k + 1);
	printTree(m + 2*n, n, k + 1);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> N >> M;
	if(M >= N - 1){
		//make sure graph is connected
		for(int i = 2; i <= N; i++){
			edg.push_back(pii(1, i));
			M--;
		}
		//fill with extra edges
		printTree(3, 1, 0);
		printTree(2, 1, 0);
		//enough edges?
		if(M != 0){
			cout << "Impossible";
		}else{
			cout << "Possible\n";
			for(int i = 0; i < edg.size(); i++){
				cout << edg[i].first << ' ' << edg[i].second << '\n';					
			}
		}
	}else{
		cout << "Impossible";
	}
	return 0;
}


