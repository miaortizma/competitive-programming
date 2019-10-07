#include<bits/stdc++.h>
#define ms(a, v) memset(a, v, sizeof a)

typedef long long ll;

int id(char x) {
    return x - 'a';
}


const int MOD = 1e9 + 7;
const int N = 26;

struct matrix {
    int m[N][N], r, c;
    matrix(int r = N, int c = N, bool iden = false) : r(r), c(c) {
        ms(m, 0);
        if (iden)
            for (int i = 0; i < r; ++i) m[i][i] = 1;
    }
    matrix operator * (const matrix &o) const {
        matrix ret(r, o.c);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < o.c; ++j) {
                ll r = 0;
                for (int k = 0; k < c; ++k)
                    r = (r + 1LL * m[i][k] * o.m[k][j]) % MOD;
                ret.m[i][j] = r;
            }
        }
        return ret;
    }
};

matrix pow(matrix X, int n) {
    matrix res = matrix(26,26,true);
    while (n > 0) {
        if (n & 1)
            res = res * X;
        X = X * X;
        n >>= 1;
    }
    return res;
}

using namespace std;

matrix mat, initial(26, 1);
int arr[26];

void printMat(matrix x) {
    for (int i = 0; i < x.r; ++i) {
        for (int j = 0; j < x.c; ++j) {
            cout << x.m[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // LOCAL
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int T, n, k;
    cin >> T;
    string s, a, b;

    while (T--) {
        cin >> s >> k >> n;
        ms(mat.m, 0);
        ms(initial.m, 0);
        for (int i = 0, nn = s.size(); i < nn; ++i)
            initial.m[id(s[i])][0]++;
        for (int i = 0; i < 26; ++i)
            mat.m[i][i] = 1;
        for (int i = 0; i < k; ++i) {
            cin >> a >> b;
            ms(arr, 0);
            int ida = id(a[0]);
            for (int j = 0, nn = b.size(); j < nn; ++j)
                arr[id(b[j])]++;
            for (int j = 0; j < 26; ++j) {
                mat.m[j][ida] = arr[j];
            }
        }
        mat = pow(mat, n);
        initial = mat * initial;
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + initial.m[i][0]) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
