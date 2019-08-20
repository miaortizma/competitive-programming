#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int arr[N];

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  
  for (int i = 0; i < n; ++i) {
    
    int j;
    
    for(j = 1; j <= x; ++j)
      if(i - j >= 0 && arr[i - j] <= arr[i])
        break; 
    
    if (j != x + 1)
      continue;

    for(j = 1; j <= y; ++j)
      if(i + j < n && arr[i + j] <= arr[i])
        break;

    if (j != y + 1)
      continue;
    
    cout << i + 1;
    return 0;
  }


}
