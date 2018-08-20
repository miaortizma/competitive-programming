#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	int m, s;
	cin >> m >> s;
	int sum = 1;
	char ans[m];
	ans[0] = '1';
	
	for(int i = 0; i < m; i++){
	
	}
	if(sum == s){
		for(int i = 0; i < m; i++){
			cout << ans[i];
		}
		cout << ' ';
		for(int i = 0; i < m; i++){
			cout << ans[m - 1 - i];
		}
	}else if(m == 1 && s == 0){
		 
	}
	return 0;
}


