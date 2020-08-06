#include<bits/stdc++.h>
using namespace std;

const int N = 3000;
int count_[N + 1];

int sieve(int n) {
  
  for (int i = 2; i <= n; ++i)
    if (count_[i] == 0)
      for (int j = 2 * i ; j <= n; j += i)
        ++count_[j];
 
  int ans = 0;
  for (int i = 6; i <= n; ++i)
    if (count_[i] == 2)
      ++ans;

  return ans;
}



int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n;
  cin >> n;

  cout << sieve(n);

  return 0;
}
