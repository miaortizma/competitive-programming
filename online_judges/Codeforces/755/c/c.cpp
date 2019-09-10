#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e4 + 1;
int sz[N], id[N];
 
void init(int n) {
  for (int i = 1; i <= n; ++i) {
    sz[i] = 0;
    id[i] = i;
  }
}
 
int root(int i) {
  while(i != id[i]){
    id[i] = id[id[i]];
    i = id[i];
  }
  return i;
}
 
 
void merge(int x, int y) {
  x = root(x); 
  y = root(y);
  if (x == y)
    return;
  if (sz[x] < sz[y])
    swap(x, y);
  if (sz[x] == sz[y])
    ++sz[x];
  id[y] = x;    
}
 
int main() {
  int n, tmp;
  cin >> n;
  init(n);
  for (int i = 1; i <= n; ++i) {
    cin >> tmp;
    merge(i, tmp);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (id[i] == i)
        ++ans;
  
  cout << ans;
  return 0;    
}
