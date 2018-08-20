#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	string s;
	cin >> s;
	int dp[s.size()] = {0};
	int a = 0, b = 0, c = 0;
	for(int i = 1; i < s.size(); i++){
		//AB  = 1 y BA = 2
		
	cout << a << " " <<  b << " " << c << '\n';
		if(s[i] == 'A'){
			if(s[i - 1] == 'B'){
				b++;
				dp[i] = 2;
				if(dp[i - 1] == 1){
					b--;
					c++;
				}
			}
		
		}else if(s[i] == 'B'){
			if(s[i - 1] == 'A'){
				a++;
				dp[i] = 1;
				if(dp[i - 1] == 2){
					a--;
					c++;
				}
			}
		}
	}
	cout << a << " " <<  b << " " << c << '\n';
	if((a > 0  && b > 0) || ( c > 0 && a > 0) || (c > 0 && b > 0)){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}


