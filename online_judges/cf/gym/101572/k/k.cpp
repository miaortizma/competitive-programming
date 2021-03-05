#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define PB push_back
#define F first
#define S second

const int N = 1e5 + 10;

typedef pair<int, int> pi;


int m;
int C[3], S[3];
vector<pair<int, pi>> v;
vector<int> boat;

bool can(int posb) {
  int CC[3];
  for (int i = 0; i < 3; ++i) {
    CC[i] = C[i];
  }
  for (int i = 0; i < m; ++i) {
    bool ok = false;
    for (int j = 0; j < 6; ++j) {
      pi pa = v[j].S;
      bool ge = v[j].F * boat[i] >= posb;
      bool left = true;
      if (pa.F == pa.S) {
        left = CC[pa.F] - 2 >= 0;
      } else {
        left = CC[pa.F] - 1 >= 0 && CC[pa.S] - 1 >= 0;
      }
      if (ge && left) {
        CC[pa.F] -= 1;
        CC[pa.S] -= 1;
        ok = true;
        break;
      }
    }
    if (!ok) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  for (int i = 0; i < 3; ++i) {
    cin >> C[i];
  }
  for (int i = 0; i < 3; ++i) {
    cin >> S[i];
  }
  m = (C[0] + C[1] + C[2]) / 2;
  boat.resize(m);
  for (int i = 0; i < m; ++i) {
    cin >> boat[i];
  }

  sort(boat.rbegin(), boat.rend());

  v.PB({S[0] + S[0], {0, 0}});
  v.PB({S[0] + S[1], {0, 1}});
  v.PB({S[0] + S[2], {0, 2}});
  v.PB({S[1] + S[1], {1, 1}});
  v.PB({S[1] + S[2], {1, 2}});
  v.PB({S[2] + S[2], {2, 2}});

  sort(v.begin(), v.end());

  int lo = 1, hi = 2 * 1e8 + 1;

  while(lo < hi) {
    int m = (lo + hi + 1) / 2;
    if (can(m)) {
      lo = m;
    } else {
      hi = m - 1;
    }
  }

  while (lo < hi) {
    int m = (lo + hi) / 2;
    if (can(m)) {
      hi = m;
    } else {
      lo = m + 1;
    }
  }


  cout << lo;

  return 0;
}
