#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma


int dist(vector<int> v, int m) {
  int S = 0;
  for (auto x : v) {
    S += abs(x - m);
  }
  return S;
}

void solve() {
  int S, A, F;
  cin >> S >> A >> F;
  vector<int> X(F);
  vector<int> Y(F);
  for (int i = 0; i < F; ++i) {
    cin >> X[i] >> Y[i];
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  int x, y;
  if (F & 1) {
    x = X[F / 2];
    y = Y[F / 2];
  } else {
    int a = F / 2;
    int b = (F / 2) - 1;
    int A = dist(X, X[a]) + dist(Y, Y[a]);
    int B = dist(X, X[b]) + dist(Y, Y[b]);
    if (A < B) {
      x = X[a];
      y = Y[a];
    } else {
      x = X[b];
      y = Y[b];
    }
  }
  cout << "(Street: " << x << ", Avenue: " << y << ")\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while(T--) {
    solve();
  }
  return 0;
}
