#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n, ans = 0;
	string s;
	cin >> n  >> s;
	char cur = s[0];
	for(int i = 1; i < n; i++){
		if(s[i] == cur){
			ans++;
		}else{
			cur = s[i];
		}
	}
	cout << ans;
	return 0;
}


