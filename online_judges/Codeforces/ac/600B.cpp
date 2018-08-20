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
	int n, m, t;
	cin >> n >> m;
	int arr[n];
	pair<int,int> brr[m];
	int ans[m];
	for(int i = 0; i < n; i++) cin >> arr[i];
	for(int i = 0; i < m; i++){
		cin >> t;
		brr[i] = pair<int,int>(t, i);
	}
	sort(arr, arr + n);
	sort(brr, brr + m);
	int j = 0;
	for(int i = 0; i < m; i++){
		while(j < n && arr[j] <= brr[i].first){
			j++;
		}
		ans[brr[i].second] = j;
	}
	for(int i = 0; i < m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}


