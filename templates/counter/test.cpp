#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, tmp, ans = 0;
        scanf("%d", &n);
        int last = -20;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            if (abs(last - tmp) > 10) {
                last = tmp + 10;
                ++ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
