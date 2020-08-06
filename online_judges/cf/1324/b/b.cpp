#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma
const int N = 5010;
int first[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, tmp;
    cin >> n;
    memset(first, -1, sizeof first);
    bool palindrome = false;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      if (first[tmp] == -1) {
        first[tmp] = i;
      } else {
        if (i - first[tmp] > 1) palindrome = true;
      }
    }
    if (palindrome) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
