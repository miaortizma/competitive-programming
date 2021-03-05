#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int I = 0, id;
    stack<int> zeros, ones; 
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        if (ones.empty()) {
          id = ++I;
          zeros.push(id);
        } else {
          id = ones.top(); ones.pop();
          zeros.push(id);
        }
      } else {
        if (zeros.empty()) {
          id = ++I;
          ones.push(id);
        } else {
          id = zeros.top(); zeros.pop();
          ones.push(id);
        }
      }
      ans.push_back(id);
    }
    cout << I << "\n";
    for (int i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}
