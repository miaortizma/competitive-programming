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

int rep[256];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, m, l, r;
	char x, y;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 'a'; i <= 'z'; i++){
		rep[i] = i;
	}
	for(int i = 0; i < m; i++){
		cin >> x >> y;
		for(int i = 'a'; i <= 'z'; i++){
			if(rep[i] == (int)x ){
				l = i;
			}
			if(rep[i] == (int)y){
				r = i;
			}
		}
		rep[l] = y;
		rep[r] = x;
	}
	for(int i = 0; i < n; i++){
		cout << (char)(rep[s[i]]);
	}
	return 0;
}


