#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5;
int arr[N];
int n;

bool can(int m) {
  for (int i = 1; i <= m; ++i)
    if(arr[i - 1] * 2 > arr[n - m + i - 1])
      return false;
  
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  sort(arr, arr + n);
  
  int l = 0;
  int h = n / 2;
  
  while (l < h) {
    int m = l + (h - l + 1) / 2;
    if (can(m))
      l = m;
    else
      h = m - 1;
  }
  
  cout << n - l;
 
  return 0;
}
