#include<bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  if(n == 1) {
    cout << 1;
  } else if(n == 2) {
    cout << 2; 
  } else if(n == 3) {
    cout << 6;
  } else if(n%2 == 0){
    long long A = n * (n - 1) * (n - 2) / 2;
    long long B = n * (n - 1) * (n - 3);
    long long C = (n - 1) * (n - 2) * (n - 3);
    if(n % 3 == 0)
        B /= 3;
    
    cout << max(A, max(B, C));
  } else {
    cout << n * (n - 1) * (n - 2);
  }
  return 0;
}
