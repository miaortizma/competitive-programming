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

const int NMAX = 5000;
int arr[NMAX + 5];
int mode[NMAX + 5];
int cur[NMAX + 5];
int n;
	

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < n; i++){
		int mx = 0, md = 0;
		memset(cur, 0, sizeof(cur));
		for(int j = i; j < n; j++){
			cur[arr[j]]++;
			if(cur[arr[j]] > mx){
				mx = cur[arr[j]];
				md = arr[j];
			}else if(cur[arr[j]] == mx && arr[j] < md){
				md = arr[j];
			}
			mode[md]++;
		}
	}
	for(int i = 1; i <= n; i++){
		cout << mode[i] << ' ';
	}
	return 0;
}


