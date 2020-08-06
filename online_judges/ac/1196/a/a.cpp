#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main() {
  ll q, A[3], B = 0, C = 0;
  cin >> q;
  while(q--) {
    cin >> A[0] >> A[1] >> A[2];
    sort(A, A + 3);
    //cout << A[0] << A[1] << A[2] << '\n';
    B = A[0];
    C = A[1];
    ll c = C - B;
    if(A[2] >= c) {
      B += c;
      A[2] -= c;
      ll left = A[2] / 2;
      cout <<  B + left << '\n';
    } else {
      cout << B + A[2];
    }

  }
  return 0;
}
