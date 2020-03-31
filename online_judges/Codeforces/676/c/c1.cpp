#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 1e5 + 10;
int rnk[N], id[N];
int n, k;
string s;

void init() {
  for (int i = 0; i < n; ++i) {
    rnk[i] = 0;
    id[i] = i;
  }
}

int root(int i) {
  while (id[i] != i) {
    id[i] = id[id[i]]; // path compression
    i = id[i];
  }
  return i;
}

void merge(int x, int y) {
  x = root(x), y = root(y);
  if (x == y) return;
  //cerr << "merge: " << x << " " << y << "\n";
  if (rnk[x] > rnk[y]) swap(x, y);
  // add x to y
  if (rnk[x] == rnk[y]) rnk[y]++;
  id[x] = y;
}

int ans;

void solve(char c) {
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (s[i] == c) {
      if (k == 0) continue;
      if ((int) q.size() == k) q.pop();
      q.push(i);
    }
    int le;    
    if (q.size() == 0) {
      le = root(i);
    } else {
      int v = q.front();
      if (v == 0) {
        le = v;
      } else if (s[v - 1] != s[v]) {
        le = root(v - 1);
      } else {
        le = v;
      }
    }
    //cerr << c << "\n";
    //cerr << i << " " << le << " " << q.front() <<  "\n";
    ans = max(ans, i - le + 1);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);

  cin >> n >> k >> s;
  init();
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      merge(i, i - 1);
    }
  }
  solve('a');
  solve('b');
  cout << ans << "\n";
  return 0;
}
