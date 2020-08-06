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
	queue<int> q;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < m; i++){
		cin >> t;
		q.push(t);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(q.front() >= arr[i]){
			ans++;
			q.pop();
		}
	}
	cout << ans << '\n';
	return 0;
}


