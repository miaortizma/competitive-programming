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

int digitsum(ll s){
	int ans = 0;
	while(s > 0){
		ans += (s%10);
		s /= 10;
	}	
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int a, b, c;
	cin >> a >> b >> c;
	vector<ll> ans;
	for(int i = 1; i <= 81; i++){
		ll s = b;
		for(int j = 0; j < a; j++){
			s*= i;
		}
		s += c;
		if(digitsum(s) == i && s < (int)1e9){
			ans.push_back(s);
		}
	}
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << ' ';
	}
	return 0;
}


