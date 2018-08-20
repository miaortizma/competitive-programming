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

int Time[110];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, q;
	cin >> n >> q;
	while(q--){
		int t, k, d;
		cin >> t >> k >> d;
		vector<int> next;
		for(int i = 0; i < n; i++){
			if(next.size() == k) break;
			if(Time[i] <= t){
				next.push_back(i);
			}
		}
		if(next.size() == k){
			int q = 0;
			for(int i = 0; i < k; i++){
				int cur = next[i];
				q += (cur+1);
				Time[cur] = t + d; 
			}
			cout << q << '\n';
		}else{
			cout << "-1\n";
		}
	}
	return 0;
}


