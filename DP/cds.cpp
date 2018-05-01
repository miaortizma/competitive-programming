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

int dp[21][1000];
int choose[21][1000];

vector<int> getSolution(int n, int w, int arr[]){
	int cur = choose[n][w];
	int i = n-1;
	//cout << "get solution: \n";
	vector<int> solution;
	while(cur != 0 && i >= 0){
		while(cur != arr[i] && i >= 0){
			i--;
		}
		solution.push_back(arr[i]);
		cur = choose[i][w - arr[i]];
		w -= arr[i];
		i--;
	}
	return solution;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int W, n;
	while(cin >> W >> n){
		memset(dp, 0, sizeof(dp));
		int arr[n];
		for(int i = 0; i < n; i++) cin >> arr[i];
		
		for(int i = 1; i <= n; i++){
			int val = arr[i-1];
			for(int j = 1; j <= W; j++){
				dp[i][j] = dp[i-1][j];
				choose[i][j] = choose[i-1][j];
				if(j - val >= 0 && dp[i-1][j-val] + val >= dp[i][j]){
					dp[i][j] = dp[i-1][j-val] + val;
					choose[i][j] = val;
				}
			}
		}
		/*for(int j = 1; j <= W; j++){
			for(int i = 1; i <= n; i++){
				cout << choose[i][j] << ' ';	
			}
			cout << '\n';
		}*/
		vector<int> solution = getSolution(n,W, arr);
		for(int i = solution.size() - 1; i >= 0; i--){
			cout << solution[i] << ' ';
		}
		cout << "sum:" << dp[n][W] << '\n';
	}
	return 0;
}

