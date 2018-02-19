#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n;
	cin >> n;
	queue<ll> q;
	ll t;
	for(int i = 0; i < n; i++){
		cin >> t;
		q.push(t);
	}
	bool flag = true;
	ll mod = 1e9 + 7;
	while(q.size() > 1){
		int sz = q.size();
		ll last = q.front();
		for(int i = 0; i < sz; i++){
			q.pop();
			if(flag){
				q.push((last + q.front())%mod);
			}else{
				q.push((last - q.front())%mod);
			}
			last = q.front();
		}
	}
	cout << q.front();
	return 0;
}

