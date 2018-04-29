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
	int n;
	while(cin >> n){
		int arr[n+1][n+1];
		memset(arr, 0, sizeof(arr));
		int best = -128;
		bool posiv = false;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cin >> arr[i][j];
				if(arr[i][j] < 0){
					best = max(best, arr[i][j]); 
				}else{
					posiv = true;
				}
				arr[i][j] += arr[i][j-1];
			}
		}
		if(!posiv){
			cout << best << '\n';
			continue;
		}
		for(int i = 1; i <= n; i++){
			for(int j = i; j <= n; j++){
				int cur = 0;
				for(int k = 1; k <= n; k++){
					int row = arr[k][j] - arr[k][i-1];
					cur = max(0, cur + row);
					best = max(best, cur);
				}
			}
		}
		cout << best << '\n';	
	}
	return 0;
}

