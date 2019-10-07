#include<bits/stdc++.h>
using namespace std;

int A[5], B[5], l, u, n, m;

void setDigits(int arr[], int x) {
  int i = 0;
  while (x) {
    arr[i++] = x % 10;
    x /= 10;
  }
}
     //i  mask
int dp[6][2][2][1030], vis[6][2][2][1030], tag;

bool bitOn(int mask, int i) { return (mask & (1 << i)); }

int go(int i, bool L, bool U, int mask) {
  if (i == -1 && mask)
    return 1;
  if (vis[i][L][U][mask] == tag)
    return dp[i][L][U][mask];
  int low = 0, high = 9;
  if (L) low = A[i];
  if (U) high = B[i];
  int ret = 0;
  for (int j = low; j <= high; ++j) {
    if (!bitOn(mask, j)) {
      int nmask = mask | (1 << j);
      bool nL = L && (j == A[i]), nU = U && (j == B[i]);
      if (L && j == 0 && i > n)
        nmask = mask;
      ret += go(i - 1, nL, nU, nmask);
    }
  }
  vis[i][L][U][mask] = tag;
  return dp[i][L][U][mask] = ret;
}

int main() {
  while (scanf("%d %d", &l, &u) == 2) {
    ++tag;
    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);
    setDigits(A, l);
    setDigits(B, u);
    n = m = 4;
    while (A[n] == 0)
      --n;
    while (B[m] == 0)
      --m;
    int ans = go(m, true, true, 0);
    printf("%d\n", ans);
  }
  return 0;
}
