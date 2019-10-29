#include<bits/stdc++.h>
using namespace std;

int arr[380];

int main() {
  int n, tmp;
  cin >> n;
  int ans = 0;
  vector<int> dirty;
  int dirtyS = 0;

  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    arr[tmp] = 1;
  } 

  for (int i = 1; i <= 365; ++i) {
    if (arr[i]) {
      dirty.push_back(i);
      ++ dirtyS;
    }


    if (dirtyS + dirty.size() >= 20) {
      ++ ans;
      dirty.clear();
      dirtyS = 0;
    }
    
    dirtyS += dirty.size();
  }

  if (dirtyS)
    ++ ans;

  cout << ans << '\n';

  return 0;
}
