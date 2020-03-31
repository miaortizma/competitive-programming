#include<bits/stdc++.h>
using namespace std;

bool inA[256], inB[256];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int q;
  cin >> q;
  while (q--) {
    string a, b;
    cin >> a >> b;
    for (char c : a)
      inA[c] = true;
    for (char c : b)
      inB[c] = true;
    bool ok = false;

    for (int i = 'a'; i <= 'z'; ++i) {
      if (inA[i] && inB[i])
        ok = true;
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
    memset(inA, false, sizeof inA);
    memset(inB, false, sizeof inB);
  }
  return 0;
}
