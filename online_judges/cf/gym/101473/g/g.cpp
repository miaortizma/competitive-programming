#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int N = 310;

int M[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int L, C;
  cin >> L >> C;
  vector<int> Lid, Cid;
  Lid.resize(L);
  Cid.resize(C);
  bool ok = true;
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> M[i][j];
    }
    Lid[i] = (M[i][0] - 1) / C;
    for (int j = 0; j < C; ++j) {
      if ((M[i][j] - 1) / C != Lid[i]) {
        ok = false;
      }
    }
    for (int j = 0; j < C; ++j) {
      int cid = M[i][j] - C * Lid[i] - 1;
      if (i == 0) {
        Cid[j] = cid;
      } else {
        if (cid != Cid[j]) {
          ok = false;
        }
      }
    }
  }
  if (!ok) {
    cout << "*";
    return 0;
  }
  int ans = 0;
  for (int i = 0; i < L; ++i) {
    if (Lid[i] != i) {
      for (int j = i + 1; j < L; ++j) {
        if (Lid[j] == i) {
          swap(Lid[i], Lid[j]);
          ans++;
        }
      }
    }
    //cout << Lid[i] << " ";
  }
  //cout << "\n";
  /*
  for (int i = 0; i < C; ++i) {
    cout << Cid[i] << " ";
  }
  cout << "\n";
  */
  for (int i = 0; i < C; ++i) {
    if (Cid[i] != i) {
      for (int j = i + 1; j < C; ++j) {
        if (Cid[j] == i) {
          swap(Cid[i], Cid[j]);
          ans++;
        }
      }
    }
    //cout << Cid[i] << " ";
  }
  //cout << "\n";
  cout << ans << "\n";

  return 0;
}
