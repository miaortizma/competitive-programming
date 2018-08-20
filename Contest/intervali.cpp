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

typedef pair<int,int> pii;


int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int N, a, b;
    cin >> N;
    pii arr[N];
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        arr[i] = pii(a, b);
    }
    vector<int> dp[N+1];
    sort(arr, arr + N);
    for(int i = 0; i < N; i++){
        dp[0].push_back(1);
    }
    for(int i = 1; i <= N; i++){
        dp[i].push_back(1);
        for(int j = 1; j <= N; j++){
            if(arr[j-1].first > arr[i-1].first) break;
            dp[i].push_back(max(dp[i-1][j], dp[i][j-1]));
            if(arr[j-1].second <= arr[i-1].first){
                dp[i][j] = dp[i-1][j] + 1;
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j < dp[i].size(); j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << dp[N][N];
	return 0;
}
