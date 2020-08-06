#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;

struct node {
  map<char, int> m;
  int cnt;
  node(int cnt) : cnt(cnt) {}
};

vector<node> T;

int getCount(string s) {
  int v = 0;
  for (char c : s) {
    if (T[v].m.count(c)) {
      v = T[v].m[c];
    } else {
      return 0;
    }
  }
  return T[v].cnt;
}

void add(string s) {
  int v = 0;
  for (char c : s) {
    if (T[v].m.count(c)) {
      v = T[v].m[c];
    } else {
      T.push_back(node(0));
      T[v].m[c] = T.size() - 1;
      v = T.size() - 1;
    }
  }
  T[v].cnt++;
  //cerr << "added: "  << s << "\n";
  //cerr << getCount(s) << "\n";
}

map<char, int> mmap;
vector<char> rmap = {'S', 'E', 'T'};

char other(char a, char b) {
  bool u[3];
  memset(u, false, sizeof u);
  u[mmap[a]] = true;
  u[mmap[b]] = true;
  for (int i = 0; i < 3; ++i) {
    if(!u[i]) return rmap[i];
  }
  return '.';
}

int main() {
  T.push_back(node(0));
  mmap['S'] = 0;
  mmap['E'] = 1;
  mmap['T'] = 2;
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> k;
  vector<string> v;
  string s;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    v.push_back(s);
    add(s);
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      string match = "";
      string &a = v[i], &b = v[j];
      for (int p = 0; p < k; ++p) {
        if (a[p] == b[p]) {
          match += a[p];
        } else {
          match += other(a[p], b[p]);
        }
      }
      int c = getCount(match);
      //cerr << a << " " << b << " match: " << match << " c:" << c << "\n";
      if (a == b) {
        ans += c - 2;
      } else {
        ans += c;
      }
    }
  }
  cout << ans / 3 << "\n";
  return 0;
}
