#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 510;
int n, I;
map<string, int> SID;

vector<int> adj[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    SID[s] = I++;
  }
  int k;
  for (int i = 0; i < n; ++i) {
    cin >> s >> k;

  }
  return 0;
}
