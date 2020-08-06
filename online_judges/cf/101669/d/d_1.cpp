#include<bits/stdc++.h>
using namespace std;

int m, n, k, p;

struct row {
  int f, sz;
  set<int> st;
  row(set<int> st) : st(st) {
    f = *(st.begin());
    sz = st.size();
  }
};

vector<row> mat;
bool cmp(const row &lh, const row &rh) { return lh.f > rh.f; }

bool cmp1(const int &lh, const int &rh) { return mat[lh].f > mat[rh].f; }
priority_queue<int, vector<int>, decltype(&cmp1)> pq(cmp1);

void merge(int r, int c, set<int> &rs, set<int> &cs) {
  /*cerr << "rs:\n";
  for (int x : rs) {
    cerr << x << " ";
  }
  cerr << "\n";
  cerr << "cs:\n";
  for (int x : cs) {
    cerr << x << " ";
  }
  cerr << "\n";
  rs.erase(rs.begin());
  cs.erase(cs.begin());*/

  // rs is always smaller than cs
  for (int x : rs) {
    set<int>::iterator it = cs.find(x);
    if (it != cs.end()) cs.erase(it);
    else cs.insert(x);
  }
  /*cerr << "cs:\n";
  for (int x : cs) {
    cerr << x << " ";
  }
  cerr << "\n\n";*/
  mat[c].f = *(cs.begin());
  if (!cs.empty()) pq.push(c);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    //cerr << i << "\n";
    scanf("%d", &k);
    if (k == 0) continue;
    set<int> st;
    for (int j = 0; j < k; ++j) {
      scanf("%d", &p);
      st.insert(p);
    }
    mat.push_back(row(st));
    pq.push(mat.size() - 1);
  }
  int ans = 0;
  while (pq.size() > 1) {
    int r = pq.top(); pq.pop();
    //cerr << "@@@@\n";
    if (mat[pq.top()].f == mat[r].f) {
      int c = pq.top(); pq.pop();
      if (mat[r].st.size() < mat[c].st.size()) swap(r, c);
      merge(r, c, mat[r].st, mat[c].st);
    }
    ++ans;
  }
  if (pq.size() > 0) ++ans;
  cout << ans;
  return 0;
}
