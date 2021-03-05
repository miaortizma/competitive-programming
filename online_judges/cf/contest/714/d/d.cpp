#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int arr[4];

int ask() {
  printf("? %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
  fflush(stdout);
  int cnt;
  scanf("%d", &cnt);
  return cnt;
}

int last(int lo, int hi, int i, int val) {
  while (lo < hi) {
    int m = (lo + hi + 1) / 2;
    arr[i] = m;
    int cnt = ask();
    if (cnt != val) {
      hi = m - 1;
    } else {
      lo = m;
    }
  }
  return lo;
}

int first(int lo, int hi, int i, int val) {
  while (lo < hi) {
    int m = (lo + hi) / 2;
    arr[i] = m;
    int cnt = ask();
    if (cnt > val) {
      lo = m + 1;
    } else {
      hi = m;
    }
  }
  return lo;
}

int X1, X2, X3, X4, Y1, Y2, Y3, Y4;

int main() {
  int N;
  scanf("%d", &N);
  // find X1
  arr[1] = 1;
  arr[2] = N;
  arr[3] = N;
  X1 = last(1, N, 0, 2);
  arr[0] = X1 + 1;
  if (ask() == 0) {
    X3 = X1;
    arr[0] = X1;
    Y1 = last(1, N, 1, 2);
    Y3 = last(Y1 + 1, N, 1, 1);
    Y4 = first(Y1 + 1, N, 1, 1);
  } else {
    cout << "@\n";
    X3 = last(X1 + 1, N, 0, 1);
    arr[0] = X3;
    X4 = first(X3, N, 2, 1);
    arr[0] = X1;
    X2 = first(X1, X3 - 1, 2, 1);
    arr[2] = X2;
    Y1 = last(1, N, 1, 1);
    Y2 = first(Y1, N, 1, 1);
  }
  printf("X1: %d X2: %d\n", X1, X2);
  printf("X3: %d X4: %d\n", X3, X4);

  return 0;
}
