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
	int x, y;
	cin >> n;
	typedef pair<int,int> pii;
	pii arr[n];
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		arr[i] = pii(x, y);
	}
	int last = max(arr[0].first, arr[0].second);
	bool posb = true;
	for(int i = 1; i < n; i++){
		int next = 0;
		if(arr[i].first <= last){
			next = max(next, arr[i].first);
		}
		if(arr[i].second <= last){
			next = max(next, arr[i].second);
		}
		if(next == 0){
			posb = false;
			break;
		}
		last = next;
	}
	if(posb){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}



