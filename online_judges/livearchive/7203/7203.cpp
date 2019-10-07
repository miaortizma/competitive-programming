#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int num[19], n;
int used[10];

int free(int x) {
  for (int i = x - 1; i >= 0; --i) {
    if (used[i] < 2)
      return i;
  }
  return -1;
}

int main() {
  ll U;
  while (scanf("%lld", &U) == 1) {
    memset(used, 0, sizeof used);
    n = 0;
    while (U) {
      num[n++] = U % 10;
      U /= 10;
    }
    for (int i = n - 1; i >= 0; --i) {
      used[num[i]]++;
      if (used[num[i]] == 3) {
        while (i < n && free(num[i]) == -1) {
          used[num[i]]--;
          ++i;
        }
        if (free(num[i]) == 0 && i == n - 1) {
          used[num[i]]--;
          num[i] = 0;
        } else {
          used[num[i]]--;
          num[i] = free(num[i]);
          used[num[i]]++;
        }
        --i;
        while (i >= 0) {
          num[i] = free(10);
          used[num[i]]++;
          --i;
        }
      }
    }
    int i = n - 1;
    while (num[i] == 0) {
      --i;
    }
    while (i >= 0) {
      cout << num[i];
      --i;
    }
    cout << '\n';
  }
  return 0;
}
