#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

map<string, int> code;

const int TN = 1e5 + 10, PN = 1e4 + 10;

int T[TN], P[PN];

int solve(int n, int m) {
  string tmp;
  for (int i = 0; i < n; ++i) {
    cin >> tmp;
    T[i] = code[tmp];
  }
  for (int i = 0; i < m; ++i) {
    cin >> tmp;
    P[i] = code[tmp];
  }
  /*
  for (int i = 0; i < n; ++i) {
  }
  cout << "\n";
  for (int i = 0; i < m; ++i) {
    cout << P[i] << " ";
  }
  cout << "\n\n";
  */

  vector<int> pi(m, 0);
  for (int i = 1, k = 0; i < m; ++i) {
    while (k && P[k] != P[i]) k = pi[k - 1];
    if (P[k] == P[i]) ++k;
    pi[i] = k;
  }

  for (int shift = 0; shift < 12; ++shift) {
    for (int i = 0, k = 0; i < n; ++i) {
      while (k && P[k] != (T[i] + shift) % 12 ) k = pi[k - 1];
      if (P[k] == (T[i] + shift) % 12) ++k;
      if (k == m) {
        //cout << shift << " " << i - k + 1 << "\n";
        cout << "S\n";
        return 0;
      }
    }
  }

  cout << "N\n";
  return 0;
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, m;

  code["A"] = 0;

  code["A#"] = 1;
  code["Bb"] = 1;

  code["B"] = 2;
  code["Cb"] = 2;

  code["B#"] = 3;
  code["C"] = 3;

  code["C#"] = 4;
  code["Db"] = 4;

  code["D"] = 5;

  code["D#"] = 6;
  code["Eb"] = 6;

  code["E"] = 7;
  code["Fb"] = 7;

  code["E#"] = 8;
  code["F"] = 8;

  code["F#"] = 9;
  code["Gb"] = 9;

  code["G"] = 10;

  code["G#"] = 11;
  code["Ab"] = 11;

  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    solve(n, m);
  }
  return 0;
}
