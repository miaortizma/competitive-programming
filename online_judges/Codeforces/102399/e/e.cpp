#include<bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, s;
  scanf("%d %d", &n, &s);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", s * i);
  }
  return 0;
}
