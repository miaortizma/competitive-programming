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
	ll W, N;
	cin >> W >> N;
	ll w, l;
	ll area = 0;
	for(int i = 0; i < N; i++){
		cin >> w >> l; 
		area += w*l;
	}
	ll L = area/W;
	cout << L << '\n';
	return 0;
}


