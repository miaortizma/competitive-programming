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
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr, arr + n);
	queue<int> pq;
	pq.push(arr[0]);
	int ans = 0;
	for(int i = 1; i < n; i++){
		if(arr[i] > pq.front()){
			pq.pop();
			ans++;	
		}
		pq.push(arr[i]);
	}
	cout << ans << '\n';
	return 0;
}


