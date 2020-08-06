#include<bits/stdc++.h>
using namespace std;

const int N = 200001;
long long C[N][3];
long long ans;

void build() {
  C[2][0] = 1;
  C[2][1] = 2;
  C[2][2] = 1;
  for (int i = 3; i < N; ++i) {
    C[i][0] = 1;
    C[i][1] = i;
    C[i][2] = C[i - 1][1] + C[i - 1][2];
  }
}

unordered_map<int, vector<int>> X, Y;
int n, x, y;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  build();
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    X[x].push_back(y);
    Y[y].push_back(x);
  }
  for (auto const& x : X) {
    vector<int> v = x.second;
    sort(v.begin(), v.end());
    int curr = 1;
    ans += C[v.size()][2];
    for (size_t i = 1; i < v.size(); ++i) {
      if (v[i] == v[i - 1]) {
        ++ curr;
      } else if (curr > 1) {
        ans -= C[curr][2];
        curr = 1;
      }
    }

    if (curr > 1)
      ans -= C[curr][2];
  }

  for (auto const& x : Y) {
    vector<int> v = x.second;
    ans += C[v.size()][2];
  }
  cout << ans;
  return 0;
}
