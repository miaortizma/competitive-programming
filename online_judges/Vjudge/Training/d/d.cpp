#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
int a, b, k;
int lp[N + 1];
vector<int> pr;

bool f(int m) {
  //cerr << "test: " << m << "\n";
  int l = a, r = a + m - 1;
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    if (lp[a + i] == a + i)
      cnt++;
    //cerr << a + i << " ";
  }
  //cerr << "\n cnt:" << cnt << "\n";
  if (cnt < k)
    return false;
  while (r < b) {
    if (lp[l] == l)
      cnt--;
    l++;
    ++r;
    if (lp[r] == r)
      cnt++;
    //cerr << "l: " << l << " r: " << r  << " cnt: " << cnt << "\n";
    if (cnt < k)
      return false;
  }
  //cerr << "true\n";
  return true;
}

void sieve() {
  for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
      lp[i * pr[j]] = pr[j];
  }
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> a >> b >> k;
  int l = 1, h = b - a + 1;
  sieve();
  while (l < h) {
    int m = l + (h - l) / 2;
    if (f(m))
      h = m;
    else
      l = m + 1;
  }
  if (!f(l))
    cout << -1;
  else
    cout << l;
  
  return 0;
}
