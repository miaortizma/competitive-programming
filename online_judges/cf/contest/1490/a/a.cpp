#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 50;
int arr[N];

bool f(int a, int b) {
  return (max(a, b) * 1.0 / min(a, b)) > 2;
}

int solve(int a, int b) {
  int ret = 0;
  if (a > b) swap(a, b);
  while (f(a, b)) {
    a = min(a * 2, b);
    //cerr << a << " " << b << "\n";
    ret += 1;
  }
  //cerr << "\n";
  return ret;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (f(arr[i], arr[i + 1])) {
        ans += solve(arr[i], arr[i + 1]);
      }
    }
    cout << ans << "\n";

  }
  return 0;
}
