#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma


typedef long long ll;
#define PB push_back

struct run {
  ll a, b, i;
  string name;
};

bool cmp(run a, run b) {
  return a.b < b.b;
}

vector<run> v;

int main() {
  ll n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string name;
    ll numa, numb;
    char dot;
    cin >> name;
    cin >> numa >> dot >> numb;
    ll a = numa * 100 + numb;
    cin >> numa >> dot >> numb;
    ll b = numa * 100 + numb;
    run r{a, b, i, name};
    v.PB(r);
  }
  sort(v.begin(), v.end(), cmp);
  ll ans = 1e18;
  vector<string> sol;
  for (int i = 0; i < n; ++i) { 
    int cnt = 0, j = 0;
    ll cur = v[i].a;
    vector<string> cursol;
    cursol.PB(v[i].name);
    while (j < n && cnt < 3) {
      if (v[j].i != v[i].i) {
        cursol.PB(v[j].name);
        cur += v[j].b;
        cnt++;
      }
      j++;
    }
    if (cur < ans) {
      ans = cur;
      sol = cursol;
    }
  }
  int a = ans / 100, b = ans % 100;
  if (b == 0) {
    cout << ans / 100 << ".00" << "\n";
  } else if (b < 10) {
    cout << a << ".0" << b << "\n";
  } else {
    cout << a << "." << b << "\n";
  }
  for (int i = 0; i < 4; ++i) {
    cout << sol[i] << "\n";
  }
  return 0;
}
