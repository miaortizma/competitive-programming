#include<bits/stdc++.h>
#define x(t) get<0>(t)
#define y(t) get<1>(t)
#define d(t) get<2>(t)

using namespace std;

typedef tuple<int, int, int> state;
map<state, double> dp;
map<state, bool> vis;

vector<int> int2v(int x) {
  vector<int> X;
  for (int i = 0; i < 5; ++ i) {
    int curr = 0;
    for (int j = 0; j < 3; ++ j) {
      if (x & (1 << (3 * i + j)))
        curr += 1 << j;
    }
    X.push_back(curr);
  }  

  return X;
};

int v2int(vector<int> X) {
  sort(X.rbegin(), X.rend());
  int ans = 0;
  for (int i = 0; i < (int) X.size(); ++ i) {
    int val;
    if (i < X.size())
      val = X[i];
    else
      val = 0;
    int j = 0;
    while(val) {
      ans += (val & 1) << (3 * i + j);
      ++ j;
      val >>= 1;
    }
  }
  
  return ans;
}

int deep = 100;

double go(state current) {

  if (vis[current])
    return dp[current];

  int a = x(current), b = y(current), d = d(current);
  
  vector<int> A = int2v(a);
  vector<int> B = int2v(b);
  
  int As = 0, Bs = 0, n = 0, m = 0;

  for (int i = 0; i < (int) A.size(); ++i) {
    if (A[i]) {
      As += A[i];
      ++ n;
    } else {
      break;
    } 
  }

  for (int i = 0; i < (int) B.size(); ++i) {
    if (B[i]) {
      Bs += B[i];
      ++ m;
    } else {
      break;
    }
  }
 
  if (d < Bs)
    return 0.0;
  
  if (Bs == 0 || (As == 0 && d >= Bs))
    return 1.0;
  
  double nn = n + m;
  double ans = 0.0;

  for (int i = 0; i < n; ++i) {
    -- A[i];
    state recur{v2int(A), b, d -1};
    ans +=  go(recur) / nn;
    ++ A[i];
  }

  for (int i = 0; i < m; ++i) {
    -- B[i];
    state recur{a, v2int(B), d - 1};
    ans += go(recur) / nn;
    ++ B[i];
  }
  
  vis[current] = true;  
  return dp[current] = ans;
}

int main() {
  cout << fixed << setprecision(12);

  int n, m, d, tmp;
  cin >> n >> m >> d;

  vector<int> A, B;

  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    A.push_back(tmp);
  }

  for (int i = 0; i < m; ++i) {
    cin >> tmp;
    B.push_back(tmp);
  }
    
  state current{v2int(A), v2int(B), d};
  double ans = go(current);
  
  cout << ans << '\n';

  return 0;
 }

