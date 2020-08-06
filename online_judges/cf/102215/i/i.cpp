#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int paint(int a, int b) {
  if (a <= b) {
    return 0;
  } else if (a == b + 1) {
    return 3;
  } else {
    int turn = 3 * (a - b) + 2 * max(0, a - 2 * b);
    if (a - 2 * b > 0) {
      return turn + paint(a - 2 * b, b);
    } else {
      return turn;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int a, b;
  cin >> a >> b;
  cout << paint(a, b);
  return 0;
}
