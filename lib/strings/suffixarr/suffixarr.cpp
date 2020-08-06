#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

struct SuffixArray {
  string str;
  int n;
  vector<int> order;

  SuffixArray (string s) {
    s += "$";
    str = s;
    n = str.length();
    order = vector<int>(n);
  };

  void build() {
    vector<pair<pii, int>> T(n);
    vector<pair<char, int>> ord0(n);
    for (int i = 0; i < n; ++i) ord0[i] = {str[i], i};
    sort(ord0.begin(), ord0.end());

    int last_class = 0;
    order[last_class] = ord0[0].second;
    for (int i = 1; i < n; ++i) {
      if (ord0[i - 1].first != ord0[i].first) ++last_class;
      order[ord0[i].second] = last_class;
    }

    for (int k = 1; k < n; k <<= 1) {
      for (int i = 0 ; i < n; ++i) T[i] = {{order[i], order[(i + k) % n]}, i};
      sort(T.begin(), T.end());

      last_class = 0;
      order[last_class] = T[0].second;
      for (int i = 1; i < n; ++i) {
        if (T[i - 1].first != T[i].first) ++last_class;
        order[T[i].second] = last_class;
      }
    }

    for (int i = 0 ; i < n; ++i) {
      printf("%d ", T[i].second);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  SuffixArray suffixArray(s);
  suffixArray.build();
}


