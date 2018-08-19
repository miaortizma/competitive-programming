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
	int n, k;
	cin >> n >> k;
	int arr[n], max0 = (int)-1e10, min0 = (int)1e10;
	for(int i = 0; i < n; i++) cin >> arr[i], max0 = max(max0, arr[i]), min0 = min(min0, arr[i]);
	if(k == 1){
		cout << min0;
	}else if(k == 2){
		int A[n], B[n];
		A[0] = arr[0];
		for(int i = 1; i < n; i++){
			A[i] = min(A[i-1], arr[i]);
			
		}
		B[n-1] = arr[n-1];
		for(int i = n - 2; i >= 0; i--){
			B[i] = min(A[i+1], arr[i]);
		}
		int ans = (int)-1e10;
		for(int i = 0; i < n - 1; i++){
			ans = max(ans, max(A[i], B[i+1]));
		}
		cout << ans;
	}else{
		cout << max0;
	}
	return 0;
}

