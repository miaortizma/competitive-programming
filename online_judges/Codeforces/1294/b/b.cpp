#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
//
#define x first
#define y second
typedef pair<int, int> pii;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    pii arr[n];
    for (int j = 0; j < n; ++j) {
      int x, y;
      cin >> x >> y;
      arr[j] = pii(x, y);
    }
    sort(arr, arr + n);
    int lx = 0, ly = 0;
    string s = "";
    bool factible = true;
    for (int j = 0; j < n; ++j) {
      if (ly > arr[j].y) {
        factible = false;
        break;
      } else {
        int us = arr[j].y - ly;
        int rs = arr[j].x - lx;
        for (int k = 0; k < rs; ++k) {
          s += "R";
        }
        for (int k = 0; k < us; ++k) {
          s += "U";
        }
        lx = arr[j].x;
        ly = arr[j].y;
      }
    }
    if (factible) {
      cout << "YES\n";
      cout << s << "\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
