#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exgcd(int a, int b, int & x, int & y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int x0, y0, g = exgcd(b, a % b, x0, y0);
  x = y0;
  y = x0 - a / b * y0;
  return g;
}

void pexgcd(int a, int b) {
  int x, y;
  cout << exgcd(a, b, x, y) << " = "<< x << " * " << a <<  " + " << y << " * " << b << "\n";
}

int main() {
  int a, b;
  cin >> a >> b;
  pexgcd(a, b);
  return 0;
}


// phi(p^k) = p^k - p^(k - 1)
// phi(2 ^ 2) = 2 ^ 2 - 2
