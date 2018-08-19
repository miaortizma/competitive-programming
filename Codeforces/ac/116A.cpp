#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n;
	int c = 0, ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		c -=a;
		c +=b;
		ans = max(c, ans);
	}
	cout << ans;
	return 0;
}


