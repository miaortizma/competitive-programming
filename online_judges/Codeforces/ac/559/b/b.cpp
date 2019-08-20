#include<bits/stdc++.h>
using namespace std;

string smallest(string s) {
  int n = s.size();
  if(n & 1)
    return s;
  string A = smallest(s.substr(0, n / 2)), B = smallest(s.substr(n / 2, n / 2));
  if (A < B)
    return A + B;
  else
    return B + A;
}

int main() {
  string a, b;
  cin >> a >> b;
  if (smallest(a) == smallest(b))
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
