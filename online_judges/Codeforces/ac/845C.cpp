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
	int n, a, b;
	cin >> n;
	typedef pair<int,int> pii;
	pii arr[n];
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		arr[i] = pii(a, b);
	}
	sort(arr, arr + n);
	int tv[2];
	tv[0] = tv[1] = -1;
	int i;
	for(i = 0; i < n; i++){
		int j;
		for(j = 0; j < 2; j++){
			if(tv[j] < arr[i].first){
				tv[j] = arr[i].second;
				break;
			}
		}
		if(j == 2) break;
	}
	if(i == n){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}


