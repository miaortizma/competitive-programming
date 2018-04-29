#include<bits/stdc++.h>
using namespace std;

const int NMAX = 5010;
int dp[NMAX][NMAX];
int T, n, m;
string A, B;

//1-indexed
char get(string A, int i){
    if(i == 0 || i == A.size() + 1){
        return '0';
    }else{
        return A[i-1];
    }
}

int cost2(char a, char b){
    if(a == '0' || b == '0') return 0;
    return (a==b)?1:0;
}

int cost3(char a,char b, char c){
    return cost2(a,b) + cost2(b,c);
}

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m >> A >> B;
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i < m; i++){
            if(B[i] == B[i-1]) dp[0][1]++;
        }
        for(int j = 1; j <= m+1; j++){
            dp[1][j] = dp[0][1] + cost3(get(B,j-1), get(A,1), get(B,j)) - cost2(get(B,j-1), get(B,j));
        }

        for(int i = 2; i <= n; i++){
            int val = dp[i-1][1];
            dp[i][1] = dp[i-1][1] + cost3(get(A,i-1),get(A,i),get(B,1));
            for(int j = 2; j <= m+1; j++){
                cout << "i: " << i << " j:" << j << '\n';
                cout << "case 1:\n";
                cout << get(A,i-1) << ',' << get(A,i) << ',' << get (B,j) << '-' << get(A,i-1) << ',' << get(B,j) << '\n';
                cout << "case 2:\n";
                cout << get(B,j-1) << ',' << get(A,i) << '\n';
                int a = dp[i-1][j] + cost3(get(A,i-1), get(A,i), get(B,j)) - cost2(get(A,i-1), get(B,j));
                int b = val + cost3(get(B,j-1), get(A,i), get(B,j));
                dp[i][j] = min(a,b);
                val = min(val, dp[i-1][j]);
            }
        }
        int ans = dp[n][1];
        cout << "m+1:" << m+1 << '\n';
        cout << "n:" << n << '\n';
        for(int j = 1; j <= m+1; j++){
            for(int i = 1; i <= n; i++){
                //cout << "i:" << i << " j: " << j << '\n';
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }
        for(int j = 2; j <= m+1; j++){
            ans = min(ans, dp[n][j]);
        }
        cout << ans << '\n';
    }
    return 0;
}
