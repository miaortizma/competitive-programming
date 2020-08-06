#include<bits/stdc++.h>
using namespace std;

bool reachable[3000];
vector<int> reached;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n, m, tmp;
  cin >> n >> m;
  if (n > m)
    reachable[0] = true;
  
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    if (reachable[0])
      continue;
    tmp %= m;
    vector<int> to_add;
    if (!reachable[tmp]) {
      to_add.push_back(tmp);
      reachable[tmp] = true;
    }
    for (int x : reached) {
      int val = (x + tmp) % m;
      if (!reachable[val]) {
        to_add.push_back(val);
        reachable[val] = true;
      }
    }
    reached.insert(reached.end(), to_add.begin(), to_add.end());
  } 

  if (reachable[0])
    cout << "YES";
  else
    cout << "NO";
  
  return 0;
}
