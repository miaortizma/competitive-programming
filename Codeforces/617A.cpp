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
	int x;
	cin >> x;
	int left = x%5;
	int ans = x/5;
	if(left){
		ans++;
	}
	cout << ans;
	return 0;
}
