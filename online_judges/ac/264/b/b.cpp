#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int arr[N], low[N];
int n, ans = 1;

map<int, int> lis;

void sieve(int n) {
  for (int i = 1; i <= n; ++i) {
    if (i % 2 == 0)
      low[i] = 2;
    else
      low[i] = i;
  }
  
  for (int i = 3; i * i <= n; i += 2)
    if (low[i] == i)
      for (int j = i * i; j <= n; j += i)
        low[j] = min(low[j], i);

}

vector<int> factorize(int x) {
  vector<int> res;

  while (x != 1) {
    int factor = low[x];
    if (res.empty() || res[res.size() - 1] != factor)
      res.push_back(factor);
    x /= factor;
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  
  sieve(arr[n - 1]);
  
  int i = 0;
  if (arr[0] == 1)
    ++i;
  
  for(; i < n; ++i) {
    vector<int> factors = factorize(arr[i]);
    int best = 0;
    for (size_t j = 0; j < factors.size(); ++j)
      best = max(best, lis[factors[j]]);
    
    for (size_t j = 0; j < factors.size(); ++j)
      lis[factors[j]] = best + 1;
    
    ans = max(ans, best + 1);
  }
  
  cout << ans;

  return 0;
}
