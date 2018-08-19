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
		freopen("in.txt","w",stdout);
	#endif
	int t = 25;
	int n = 1;
	cout << t << '\n';
	for(int i = 1; i <= t; i++){
		cout << i << ' ' << n  << '\n';
	}
	return 0;
}

