#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> sq(vector<int> X) {
  int n = X.size();
  vector<int> ans(n * 2 - 1, 0);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      ans[i + j] = (ans[i + j] + X[i] * X[j]) % 10;
  return ans;
}

bool eq(vector<int> A, vector<int> B) {
  int n = A.size();
  if (B.size() != A.size()) return false;
  for (int i = 0; i < n; ++i)
    if (A[i] != B[i]) return false;
  return true;
}

vector<int> X;
vector<int> A;
int d, s;
bool found = false;

void solve(int i) {
  if (i == s - 1) {
    for (int j = 0; j < 10; ++j) {
      A[s - 1] = j;
      if (eq(sq(A), X)) {
        found = true;
        return;
      }
    }
    A[s - 1] = 0;
    return;
  }
  for (int j = 0; j < 10; ++j) {
    A[i] = j;
    if (X[i] == sq(A)[i])
      solve(i + 1);
    if (found)
      return;
  }
  A[i] = 0;
}
 
int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  string x;
  cin >> x;
  int n = x.size();
  for (int i = 0; i < n; ++i)
    X.push_back(x[i] - '0');
  d = X.size(), s = (d + 1) / 2;
  for (int i = 0; i < s; ++i)
    A.push_back(0);
  if (n % 2 != 0)
    solve(0);
  if (found) {
    for (int i = 0; i < s; ++i) {
      cout << A[i];
    }
  } else {
    cout << -1;
  }
  return 0;
}
