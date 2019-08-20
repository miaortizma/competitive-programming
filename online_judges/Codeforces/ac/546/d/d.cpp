#include<bits/stdc++.h>
using namespace std;

const int N = 5000000;
vector <int> primes;
bool is_composite[N + 1];
int prime_powers[N + 1], prefix[N + 1];
int t, a, b, composite;

void sieve() {
  for (int i = 2; i <= N; ++i) {
    if (!is_composite[i]) { 
      primes.push_back(i);
      prime_powers[i] = 1;
    }
    
    for (int j = 0; j < primes.size() && i * primes[j] <= N; ++j) {
      int p = primes[j];
      is_composite[i * p] = true;
      prime_powers[i * p] = prime_powers[i] + 1;
      if(i % p == 0) break;
    }
    
    prefix[i] = prefix[i - 1] + prime_powers[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, a, b;
  sieve();
  cin >> t;
  while(t--) {
    cin >> a >> b;
    int ans = prefix[a] - prefix[b];
    cout << ans << '\n';
  }
  return 0;
}
