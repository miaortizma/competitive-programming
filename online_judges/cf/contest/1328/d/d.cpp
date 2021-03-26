#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int MAXN = 2 * 1e5;
int arr[MAXN];
int color[MAXN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    int cur = 0, last = arr[0];
    color[0] = cur + 1;
    for (int i = 1; i < n; ++i) {
      if (arr[i] != last) {
        cur = (cur + 1) % 2;
        last = arr[i];
      }
      color[i] = cur + 1;
    }
    if (color[n - 1] == color[0] && arr[n - 1] != arr[0]) {
      bool flip = false;
      int j = 0;
      for (int i = n - 1; i >= 1; --i) {
        if (arr[i] == arr[i - 1]) {
          flip = true;
          j = i;
          cur = color[i] % 2;
          last = arr[i];
          break;
        }
      }
      if (flip) {
        for (int i = j; i < n; ++i) {
          if (arr[i] != last) {
            cur = (cur + 1) % 2;
            last = arr[i];
          }
          color[i] = cur + 1;
        }
      } else {
        color[n - 1] = 3;
      }
    }
    bool colors[4];
    memset(colors, false, sizeof colors);
    for (int i = 0; i < n; ++i) {
      colors[color[i]] = true;
    }
    for (int i = 3; i >= 1; --i) {
      if (colors[i]) {
        cout << i << "\n";
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << color[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
