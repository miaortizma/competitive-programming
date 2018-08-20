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

map<int,int> test;
map<int,int>::iterator it;
int n, m, S, t, l, r;

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	cin >> n >> m;
	S = sqrt(n);
	while(m--){
		cin >> t;
		switch(t){
			case 1:{
				cin >> l >> r >> t;		
				break;
			}
			case 2:{
				cin >> l >> r;
				break;
			}
		}
	}
	for(auto &x: test){
		cout << x.first << ' ' << x.second << '\n';
	}
	while(m--){
		
	}
	return 0;
}

