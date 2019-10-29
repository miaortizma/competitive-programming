#include<bits/stdc++.h>
#define ms(a, v) memset(a, v, sizeof a)

typedef long long ll;
int n ,m;
int arr[1000006];
int acum[100000008];

using namespace std;
int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // LOCAL

    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        acum[arr[i]]++;
    }
    for(int i=1;i<100000006;i++){
        acum[i]+=acum[i-1];
    }
    int s;
    for(int i=0;i<m;i++){
        scanf("%d",&s);
        ll ans=0;
        for(int j = 0; j < n; j++){
            if (arr[j] < s) {
                int x = s-arr[j];
                if (x <= 0)
                    continue;
                x = min(x, (int) 1e8);
                ans += acum[x];
                if (arr[j] <= x)
                    ans--;
            }
        }
        printf("%lld\n",ans/2);
    }
    return 0;
}
