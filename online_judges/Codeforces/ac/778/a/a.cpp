#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 10;

string t, p;
int arr[N], n, tmp;

bool can(string text, int t) {
  int j = 0;
  
  for (int i = 0; i < n; ++i) {
    if (arr[i] > t && text[i] == p[j])
     ++j;
    
    if (j == p.size())
      return true;
  }
  
  return false;
}

int main() {
  cin >> t >> p;
  n = t.size();
  for (int i = 1; i <= n; ++i) {
    cin >> tmp;
    arr[tmp - 1] = i;
  } 
  
  int l = 0, h = n - p.size();
  while(l < h) {
    int m = l + (h - l + 1) / 2;
    if (can(t, m))
      l = m;
    else 
      h = m - 1;
  }

  cout << l;
  return 0;
}
