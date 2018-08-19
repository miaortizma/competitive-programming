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

	cout << fixed << showpoint;
	cout << setprecision(3);
	int n, x;
	cin >> n >> x;
	bool set[101];
	memset(set, false, sizeof(set));
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		set[t] = true;
	}
	int ans = 0;
	for(int i = 0; i < x; i++){
		if(set[i] == false){
			ans++;
		}
	}
	if(set[x] == true){
		ans++;
	}
	cout << ans;
	return 0;
}

