#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int A, B, C;
int BA, BB, BC;
int ans;

int dist(int a, int b, int c) {
  int d = abs(A - a) + abs(B - b) + abs(C - c);
  return d;
}

void minDist(int a) {
  int bb = B % a, cc = C % a;
  int b = B - bb, c = C - cc;
  if (a - bb < bb) {
    b = B + (a - bb);
  }
  if (a - cc < cc) {
    c = C + (a - cc);
  }
  int d = dist(a, b, c);
  if (d < ans) {
    ans = d;
    BA = a;
    BB = b;
    BC = c;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> A >> B >> C;
    ans = 10 * A;
    for (int j = 1; j < 2 * A + 10; ++j) {
      minDist(j);
    }
    cout << ans << "\n";
    cout << BA << " " << BB << " " << BC << "\n";
  }
  return 0;
}
