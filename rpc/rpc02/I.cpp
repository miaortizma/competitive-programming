#include<bits/stdc++.h>
#define ms(a, v) memset(a, v, sizeof a)

typedef long long ll;


using namespace std;

int dp[30][130][2];
string ans[30][130][2];
map<int, int> cost;
int pp=-1;
string solve(int ind,int n, int flag) {
    if(ind==pp){
        if(n<0){
            return "";
        }
        return "#";
    }
    if(dp[ind][n][flag]!=-1)
        return ans[ind][n][flag];
    if(flag==1){
        string x=solve(ind+1,n-cost[0],1);
        if(x!="#"){
            dp[ind][n][flag]=1;
            ans[ind][n][flag]="0"+x;
            return ans[ind][n][flag];
        }
    }
    for(int i=1;i<10;i++){
        string x=solve(ind+1,n-cost[i],1);
        if(x!="#"){
            dp[ind][n][flag]=1;
            ans[ind][n][flag]=to_string(i)+x;
            return ans[ind][n][flag];
        }
    }
    dp[ind][n][flag]=0;
    ans[ind][n][flag]="#";
    return "#";
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // LOCAL
    int T, n;
    cost[8] = 7;
    cost[0] = cost[6] = cost[9] = 6;
    cost[2] = cost[3] = cost[5] = 5;
    cost[4] = cost[7] = 4;
    cost[1] = 2;
    string res = "";
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (pp = 1; pp < 30; ++pp) {
            ms(dp, -1);
            for (int i = 0; i < 30; ++i) {
                for (int j = 0; j < 129; ++j) {
                    ans[i][j][0] = ans[i][j][1] = "";
                }
            }
            string x = solve(0, n, 0);
            if (x != "#") {
                cout << x << "\n";
                break;
            }
        }
    }
    return 0;
}
