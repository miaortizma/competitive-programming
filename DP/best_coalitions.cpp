#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int n, x, a, b;
    while(cin >> n >> x){
        if(n == 0 && x == 0) break;
        int arr[n+1];
        for(int i = 1; i <= n; i++){
            scanf("%d.%d", &a, &b);
            arr[i] = a*100 + b;
        }
        if(arr[x] > 5000){
            cout << "100.00" << '\n';
            continue;
        }
        if(arr[x] == 0 ){
            cout << "0.00\n";
            continue;
        }
        bool dp[n+1][10010];
        memset(dp, false, sizeof(dp));
        dp[0][arr[x]] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 10000; j++){
                dp[i][j] = dp[i-1][j] || dp[i][j];
                if(dp[i-1][j] && i != x){
                    dp[i][j+arr[i]] = true;
                }
            }
        }
        for(int i = 5001; i <= 10000; i++){
            if(dp[n][i] == true){
                printf("%.2f\n", (double)arr[x]*100/i);
                break;
            }
        }
    }
	return 0;
}
