#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6;

int A[N], B[N];
bool candidate[N];

string s;
int a, b, n;

int modmul(int x, int y, int m) {
  return ((x % m) * (y % m)) % m;
}

int modsum(int x, int y, int m) {
  return ((x % m) + (y % m)) % m;
}

int val(int i) {
  return s[i] - '0';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> s >> a >> b;
  n = s.size();

  // find parts divisible by a from left to right

  int cur = 0;
  for (int i = 0; i < n - 1; ++i) {
    cur = modmul(cur, 10, a);
    cur = modsum(cur, val(i), a);
    A[i] = cur;
    
    if (cur == 0 && i + 1 < n && val(i + 1) != 0)
      candidate[i] = true; 
  }

  cur = 0;
  int pow_ = 1;
  bool found = false;
  
  // find parts divisible by b from right to left

  for (int i = n - 1; i > 0; --i) {
    int add = modmul(val(i), pow_, b);
    cur = modsum(add, cur, b);
    if (cur == 0 && candidate[i - 1]) {
      found = true;
      cout << "YES\n";
      for (int j = 0; j < i; ++j)
        cout << s[j];
      cout << '\n';
      for (int j = i; j < n; ++j)
        cout << s[j];
      
      break;
    }

    pow_ = modmul(pow_, 10, b);
  }

  if (!found)
    cout << "NO";

  return 0;
}
