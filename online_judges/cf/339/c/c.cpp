#include<bits/stdc++.h>
using namespace std;

vector<int> v;
stack<int> ans;
int m;
bool done;

bool dfs(int k, int p, int l) {
  if (l == m) {
    done = true;
    ans.push(p);
    return true;
  }
  for (int val : v) {
    if (val > k && val != p) {
      if (dfs(val-k,val,l+1)) {
        ans.push(p);
        return true;
      }
    }
  }

  return false;
} 

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  string s;
  cin >> s >> m;

  for (int i = 1; i <= 10; ++i) {
    if (s[i-1] == '1') {
      v.push_back(i);
    }
  }
  dfs(0, 0, 0);
  if (done) {
    cout << "YES\n";
    ans.pop();
    while (!ans.empty()) {
      cout << ans.top() << ' ';
      ans.pop();
    }
  } else {
    cout << "NO";
  }
  return 0;
}
