#include<bits/stdc++.h>
#define ms(a, v) memset(a, v, sizeof a)

using namespace std;

int T;
int n;
string s;
int arr[7][10000008];
int ndig(int x) {
    if (x == 0)
        return 1;
    int ans = 0;
    while (x > 0) {
        x /= 10;
        ++ans;
    }
    return ans;
}

int tag, num, lim;
int pow1[7] = {10, 100, 1000, 10000, 100000, 1000000, 1000000};

int main() {
    #ifdef LOCAL
        freopen("in.txt","r",stdin);
    #endif // LOCAL
    cin>>T;
    int N = 7;
    while(T--) {
        ++tag;
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            num = 0;
            for (int j = i; j < min(n, i + N); ++j) {
                num += (int) (s[j] -'0');
                arr[j - i][num] = tag;
                num *= 10;
            }
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < pow1[i]; ++j) {
                if (arr[i][j] != tag) {
                    cout << i + 1 << ' ';
                    for (int k = 0; k < i + 1 - ndig(j); ++k)
                        cout << 0;
                    cout << j << '\n';
                    i = 9;
                    break;
                }
            }
        }
    }
    return 0;
}
