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
	int n;
	while(cin >> n){
		if(n == 0) break;
		int arr[n];
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		int best = 0, cur = 0;
		for(int i = 0; i < n; i++){
			cur = max(0, cur + arr[i]);
			best = max(best, cur);
		}
		if(best > 0){
			cout << "The maximum winning streak is " << best << ".\n";
		}else{
			cout << "Losing streak.\n";
		}
	}
	return 0;
}

