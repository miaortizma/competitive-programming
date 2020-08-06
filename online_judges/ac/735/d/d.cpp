#include<bits/stdc++.h>
using namespace std;

bool prime(int n) {
  if(n == 2)
    return true;
  if(n % 2 == 0)
    return false;
  for (long long j = 3; j * j <= n; j += 2) {
    if(n % j == 0) {
      return false;
    }
  }
  
  return true;
}

int main() {
  int n;
  cin >> n;
  if (prime(n)) {
    cout << 1;
  } else if (n % 2 == 0) {
    cout << 2;
  } else if (prime(n - 2)) {
    cout << 2;
  } else {
    cout << 3;
  }
  return 0;
}
