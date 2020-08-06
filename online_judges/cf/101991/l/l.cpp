#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;
int arr[N];
int bits[25];

bool checkAdd(int x) {
  int i = 0;
  while (x) {
    if (x & 1 && !bits[i]) return true;
    ++i;
    x >>= 1;
  }
  return false;
}

void add(int x) {
  int i = 0;
  while (x) {
    if (x & 1) bits[i] = 1;
    ++i;
    x >>= 1;
  }
}

long long get() {
  long long ans = 0;
  for (int i = 0; i <= 21; ++i) {
    if (bits[i]) ans += 1LL << i; 
  }
  return ans;
}

int main() {
  freopen("looking.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n, greater<int>());
    memset(bits, 0, sizeof bits);
    int i = 0, j = 0;
    while (i < n && j < k) {
      if (checkAdd(arr[i])) {
        add(arr[i]);
        ++j;
      }
      ++i;
    }
    long long ans = get();
    cout << ans << "\n";
  }
  return 0;
}
