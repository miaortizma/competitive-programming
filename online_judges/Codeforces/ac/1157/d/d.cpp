#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll f(ll k){
	return k * (k + 1) /2;
}

int bit[32];

int main(){
	int n, k;
	cin >> n >> k;
  for(int i = 0; i < 31; ++i)
    bit[i] = (1 << (i)) - 1;
  
  if(k < 31){
    if(f(k) <= n && n <= bit[k]){
        cout << "YES\n";
        for(int i = 1; i <= k - 1; ++i){
            cout << i << ' ';
        }
        cout << n - f(k - 1) << '\n';
    } else{
        cout << "NO\n";
    }
  } else if (f(k) <= n) {

  }
	return 0;
}
