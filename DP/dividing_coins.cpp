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

const int NMAX = 100*500;
bool dp[NMAX+10];


int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int arr[n];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j <= NMAX; j++){
				if(dp[j]){
					dp[]
				}
			}
		}
	}
	return 0;
}

