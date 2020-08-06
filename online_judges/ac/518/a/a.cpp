#include<bits/stdc++.h>
using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  ++a[n - 1];
  for (int i = n - 1; i >= 0; --i) {
    if(a[i] > 'z') {
      a[i] = 'a';
      ++a[i-1];
    }
  }
  if (a < b)
    cout << a;
  else
    cout << "No such string";
  return 0;
}
