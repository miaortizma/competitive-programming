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
	int n, A, B, C, T;
	cin >> n >> A >> B >> C >> T;
	int arr[n];
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		if(B > C){
			ans += A;
		}else{
			ans += A - B*(T - arr[i]) + C*(T - arr[i]); 
		}
	}
	cout << ans << '\n';
	return 0;
}


