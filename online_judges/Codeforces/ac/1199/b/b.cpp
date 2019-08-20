#include<bits/stdc++.h>
using namespace std;

int main() {
  double H, L;
  cin >> H >> L;
  double x = H, y = 2.0 * L;
  double ans = (y * y) / (8.0 * x) + x / 2.0 - x;
  printf("%.13f", ans);
  return 0;
}
