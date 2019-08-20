#include<bits/stdc++.h>
using namespace std;

long long n, m, k;

bool less_(long long mm) {
  long long ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += min((mm - 1) / i, m);
  
  return ans < k;
}

int main() {
  
  cin >> n >> m >> k;
  
  if (n > m) {
    n ^= m;
    m ^= n;
    n ^= m; 
  }
  
  long long l = 1, h = n * m;
  while (l < h) {
    long long mm = l + (h - l + 1) / 2;
    if (less_(mm))
      l = mm;
    else
      h = mm - 1;
  }
  
  cout <<  l;

  return 0;
}
