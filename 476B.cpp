#include <bits/stdc++.h>

using namespace std;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(12);
	string orig;
	cin >> orig;
	int cord = 0, n = orig.size();
	for(int i = 0; i < n; i++){
		if(orig[i] == '+'){
			cord++;
		}else{
			cord--;
		}
	}
	string s;
	cin >> s;
	int dp[21] = {0};
	dp[10] = 1;
	for(int i = 0; i < n; i++){
		char x = s[i];
		int dpnew[21] = {0};
		switch(x){
			case '+':{
				for(int j = 0; j < 21; j++){
					if(dp[j] >= 1){
						dpnew[j + 1] += dp[j];
					}
					dp[j] = 0;
				}
				break;
			}
			case '-':{
				for(int j = 0; j < 21; j++){
					if(dp[j] >= 1){
						dpnew[j - 1] += dp[j];
					}
					dp[j] = 0;
				}
				break;
			}
			case '?':{
				for(int j = 0; j < 21; j++){
					if(dp[j] >= 1){
						dpnew[j - 1] += dp[j];
						dpnew[j + 1] += dp[j];
					}
					dp[j] = 0;
				}
				break;
			}
		}
		swap(dpnew, dp);
	}
	int count = 0;
	for(int i = 0; i < 21; i++){
		count += dp[i];
	}
	double ans = dp[cord + 10]/double(count);
	cout << ans;
	return 0;
}
