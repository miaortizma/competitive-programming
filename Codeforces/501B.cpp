#include <bits/stdc++.h>
using namespace std;
#define ll long long


map< string, string> mp;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int count = 0;
	for(int i = 0; i < n; i++){
		string a, b;
		cin >> a >> b;
		bool ok = true;
		for(auto const & x : mp){
			if(x.second == a){
				x.second = b;
				ok = false;
				break;
			}
		}
		if(ok){
			mp[a] = b;
		}
	}
	cout << mp.size();
	for(auto const & x : mp){
		cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}


