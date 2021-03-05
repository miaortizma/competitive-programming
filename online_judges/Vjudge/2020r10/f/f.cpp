#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma


const int N = 1010;
int n;
int ne[N];
int vis[N];


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> ne[i];
  }
  int flag = 1;
  for (int i = 1; i <= n; ++i) {
    int cur = i;
    while (vis[cur] != flag) {
      vis[cur] = flag;
      cur = ne[cur];
    }
    cout << cur << " ";
    flag++;
  }


  return 0;
}
