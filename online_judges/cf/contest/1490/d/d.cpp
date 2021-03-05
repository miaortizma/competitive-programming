#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

const int MAXN = 100;
const int MAXK = 6;

int st[MAXN + 1][MAXK + 1];
int _log[MAXN + 1];
int pos[MAXN + 1];
int ans[MAXN + 1];
int N, K;

void precalc() {
  cin >> N;
  K = _log[N];
  for (int i = 0; i <= N; ++i) {
    pos[i] = 0;
    ans[i] = 0;
    for (int j = 0; j <= K; ++j) {
      st[i][j] = 0;
    }
  }
  for (int i = 0; i < N; ++i) {
    int temp;
    cin >> temp;
    st[i][0] = -temp;
    pos[temp] = i;
  }
  for (int j = 1; j <= K; j++) {
    for (int i = 0; i + (1 << j) <= N; i++) {
      st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
}

void calc(int L, int R, int d) {
  if (L == R) {
    ans[L] = d;
    return;
  }
  int j = _log[R - L + 1];
  int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
  int in = pos[-minimum];
  ans[in] = d;
  if (L <= in - 1) calc(L, in - 1, d + 1);
  if (in + 1 <= R) calc(in + 1, R, d + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  for (int i = 2; i <= MAXN; i++) {
    _log[i] = _log[i/2] + 1;
  }

  int t;
  cin >> t;


  while (t--) {
    precalc();
    calc(0, N - 1, 0);
    for (int i = 0; i < N; ++i) {
      cout << ans[i] << " ";
    }
    cout << "\n";
    /*
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= K; ++j) {
        cout << st[i][j] << " ";
      }
      cout << "\n";
    }
    */
  }

  return 0;
}
