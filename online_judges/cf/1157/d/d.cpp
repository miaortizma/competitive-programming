#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
 
ll f(ll k){
  return (k) * (k + 1) /2;
}
 
const int N = 1e5;

ll bs[33];
ll arr[N];
 
int main(){
  int n, k;
  cin >> n >> k;
  if (n >= f(k)) {
    if ((k == 2 && n == 4) || (k == 3 && n == 8)) {
      cout << "NO\n";
      return 0;
    } 
    ll s = f(k);
    n -= s;
    for (int i = 0; i < k; ++i)
      arr[i] = 1 + i;
    ll q = n / k;
    n -= k * q;
    for (int i = 0; i < k; ++i)
      arr[i] += q;
    if (n) {
      arr[k - 1] += n;
      if (arr[k - 1] > 2 * arr[k - 2]) {
        arr[k - 1] --;
        arr[k - 2] ++ ;
      }
    }
    cout << "YES\n";
    for (int i = 0; i < k; ++i)
      cout << arr[i] << " ";
  } else {
    cout << "NO\n";
  }
  return 0;
}
