#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum1(ll n) {
  return n * (n + 1) / 2;
}

ll sum2(ll a, ll b) {
  return sum1(b) - sum1(a);
}

ll count(ll n) {
  ll superBlock = 1, power = 9, total = 0;
  ll ans = 0;
  while (total < n) {
    ll toAdd = min(n - total, power);
    ans += sum2(n - total - toAdd, n - total) * superBlock;
    total += toAdd;
    power *= 10;
    ++superBlock;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int q;
  ll x;
  cin >> q;
  while (q--) {
    cin >> x;
    //cout << x << '\n';
    ll l = 1, h = 1e9, m, val = 0;
    while (l < h) {
      m = l + (h - l) / 2;
      val = count(m);
      if (val < x)
        l = m + 1;
      else
        h = m;
    }
    //cout << "l: " <<  l << '\n';
    //cout << count(l) << ' ' << x << '\n';
    ll b = l;
    ll behind = count(b - 1);
    x -= behind;
    ll superBlock = 1, power = 9, total = 0, num = 0;
    while (total + superBlock * power < x) {
      total += superBlock * power;
      num += power;
      power *= 10;
      ++superBlock;
    }
    x -= total;
    l = 1, h = power;
    while (l < h) {
      m = l + (h - l) / 2;
      if (superBlock * m < x)
        l = m + 1;
      else
        h = m;
    }
    num += l;
    int pos = (x - 1) % superBlock;

    /*cout << "will be of " << superBlock << " digits\n";
    cout << "total: " << total << '\n';
    cout << "num: " << l << " of superblock\n";
    cout << "num: " << num << '\n';
    cout << "x: " << x << '\n';
    cout << "pos: " << pos << '\n';*/
    stringstream ss;
    ss << num;
    string nums = ss.str();
    cout << nums[pos] << '\n';
  }
  return 0;
}
