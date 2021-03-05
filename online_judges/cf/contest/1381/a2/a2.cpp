#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

char contrary(char x) {
  return x == '0' ? '1' : '0';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<int> moves;

    bool op = false;
    int l = 0, r = n - 1;

    for (int i = n - 1; i >= 0; --i) {
      char want = contrary(b[i]);
      char have;
      if (op) {
        have = contrary(a[r]);
      } else {
        have = a[l];
      }
      if (have == want) {
        moves.push_back(i + 1);
      } else {
        moves.push_back(1);
        moves.push_back(i + 1);
      }
      if (op) {
        --r;
      } else {
        l++;
      }
      op = !op;
    }
    cout << moves.size() << " ";
    for (auto x : moves) {
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}
