#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

typedef long long ll;
typedef pair<ll, ll> pl;

struct hashing {
  int p, m;
  int n;
  vector<ll> p_pow, h;

  hashing (string const& s, int p = 32, int m = 1e9 + 9) : p(p), m(m) {
    n = s.size();

    p_pow.resize(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
      p_pow[i] = (p_pow[i - 1] * p) % m;

    h.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
      h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
    }
  }

  // 0 indexed
  ll sub(int i, int l) {
    ll cur_h = (h[i + l] + m - h[i]) % m;
    cur_h = (cur_h * p_pow[n - i - 1]) % m;
    return cur_h;
  }
};


int count_palindromes(string &s) {
  //cout << s << "\n";
  int n = s.size();
  hashing h(s, 32, 1001864327), h1(s, 47, 1001265673);
  reverse(s.begin(), s.end());
  hashing rh(s, 32, 1001864327), rh1(s, 47, 1001265673);
  reverse(s.begin(), s.end());
  //set<ll> hs;
  set<pl> hs[26];
  for (int i = 1; i < n; ++i) {
    int lo = 0, hi = min(i, n - i);
    //cout << "i: " << i << " hi: " << hi << "\n";
    int rr = n - i - 1;
    while (lo < hi) {
      int m = (hi + lo + 1) / 2;
      //cout << "m: " << m << "\n";
      pl left{rh.sub(rr + 1, m), rh1.sub(rr + 1, m)};
      pl right{h.sub(i + 1, m), h1.sub(i + 1, m)};
      //cout << left << " " << right << "\n";
      //cout << "equal: " << (left == right) << "\n";
      if (left == right) {
        lo = m;
      } else {
        hi = m - 1;
      }
    }
    //cout << i << " " << lo << "\n";
    if (lo > 0) {
      int cid = s[i] - 'a';
      for (int j = lo; j >= 1; --j) {
        pl cur_h{h.sub(i - j, j * 2 + 1), h1.sub(i - j, j * 2 + 1)};
        if (hs[cid].count(cur_h)) {
          break;
        }
        hs[cid].insert(cur_h);
      }
    }
  }
  ll cnt = 0;
  for (int i = 0; i < 26; ++i) {
    cnt += hs[i].size();
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  string s;
  cin >> n >> s;
  ll ans = count_palindromes(s);
  cout << ans << "\n";

  return 0;
}
