#include<bits/stdc++.h>
#define ms(a, v) memset(a, v, sizeof a)

using namespace std;

//Debuggin Template
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef DEBUG
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "


typedef long long ll;
const ll MOD = 4300000013;
const int N = 1e5 + 10;

int T, n, q, l, r, d, b;
ll ans = 1, ansN = 0;
char type;

int BIT[N], arr[N];
ll f[N], finv[N], inv[N];
unordered_map<int, int> cnt;

ll multp(ll a, ll b) {
    if (a > b)
        swap(a, b);
    ll ret = 0;
    while (b) {
        if (b & 1)
            ret = (ret + a) % MOD;
        a = (a * 2LL) % MOD;
        b >>= 1;
    }
    return ret;
}

void add(int i, int x) {
    int oldV = arr[i], newV = arr[i] + x;
    if (oldV == 0) {
        if (ansN > 0)
            ans = multp(ans, finv[ansN]);
        ++ansN;
        ans = multp(ans, f[ansN]);
    }

    if (oldV > 0) {
        ans = multp(ans, f[cnt[oldV]]);
        --cnt[oldV];
        ans = multp(ans, finv[cnt[oldV]]);
    }

    ans = multp(ans, f[cnt[newV]]);
    ++cnt[newV];
    ans = multp(ans, finv[cnt[newV]]);

    arr[i] += x;
    for (; i < N; i += i & - i)
        BIT[i] += x;
}

int sum1(int i) {
    int ret = 0;
    for (; i > 0; i -= i & -i)
        ret += BIT[i];
    return ret;
}

int sum2(int l, int r) { return sum1(r) - sum1(l - 1); }

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
    #endif // LOCAL
    f[0] = finv[0] = inv[1] = finv[1] = 1;
    for (int i = 1; i < N; ++i) {
        f[i] = multp(f[i-1], i);
        if (i > 1) {
            inv[i] = (MOD - multp(MOD/i,inv[MOD % i]) % MOD) % MOD;
            finv[i] = multp(finv[i-1], inv[i]);
        }
    }

    scanf("%d", &T);
    while (T--) {
        scanf("%d %d\n", &n, &q);
        ms(BIT, 0);
        ms(arr, 0);
        cnt.clear();
        ans = 1;
        ansN = 0;
        for (int i = 0; i < q; ++i) {
            scanf("%c", &type);

            if (type == 'U') {

                scanf("%d %d\n", &d, &b);
                add(d, b);

            } else if (type == 'W') {

                scanf("\n");
                printf("%lld\n", ans);

            } else if (type == 'Q') {

                scanf("%d %d\n", &l, &r);
                printf("%d\n", sum2(l, r));

            }
        }
    }
    return 0;
}
