#include<bits/stdc++.h>
using namespace std;

int ndigits(int x) {
  if (x == 0)
    return 1;
  int ret = 0;
  while (x) {
    ++ret;
    x /= 10;
  }
  return ret;
}
           // 0  1   2    3     4      5       6        7
int pows[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};


typedef pair<int, int> pii;

void frac(vector<int> fr) {
  int n = fr.size();
  pii ret{1, fr[n - 1]};
  for (int i = fr.size() - 2; i >= 0; --i) {
    ret = {ret.second, fr[i] * ret.second + ret.first};
  }
  printf("%d/%d\n", ret.second, ret.first);
}

void first8(int a, int b) {
  cerr << a << ' ' << b << '\n';
  vector<int> fr;
  fr.push_back(a);
  int nd = ndigits(b);
  int x = pows[nd] / b;
  fr.push_back(x);
  int numerator = pows[nd] - b * x;
  for (int i = 0; i < 6; ++i) {
    if (numerator == 0)
      break;
    x = b / numerator;
    fr.push_back(x);
    int temp = numerator;
    numerator = b - numerator * x;
    b = temp;
  }
  for (int i = 0, n = fr.size(); i < n; ++i) {
    printf("%d ", fr[i]);
  }
  printf("\n"); 
  frac(fr);
}

int main() {
  int N;
  scanf("%d", &N);
  int a, b;
  while (N--) {
    scanf("%d.%d", &a, &b);
    first8(a, b);
  }
  return 0;
}
