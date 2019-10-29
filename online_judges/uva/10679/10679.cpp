#include<bits/stdc++.h>
using namespace std;

const int K = 52;

bool in[1010];

int h(char ch) {
  if (ch >= 'A' && ch <= 'Z') {
    return ch - 'A';
  } else {
    return 26 + ch - 'a';
  }
}

struct Vertex {
    int next[K];
    bool leaf = false;
    vector<int> id;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s, int id) {
    int v = 0;
    for (char ch : s) {
        int c = h(ch);
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf = true;
    t[v].id.push_back(id);
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = h(ch);
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
} 

void traverse(string const& s) {
  int v = 0;
  for (char ch : s) {
    int c = h(ch);
    if (t[v].next[c] == -1) {
      go(v, ch);
      v = t[v].go[c];
    } else {
      v = t[v].next[c];
    }
    if (t[v].leaf) {
      for (int i : t[v].id) {
        in[i] = true;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int k, Q;
  string T, q;
  cin >> k;
  while (k--) {
    cin >> T >> Q;
    for (int i = 0; i < Q; ++i) {
      cin >> q;
      add_string(q, i);
    }
    traverse(T);
    for (int i = 0; i < Q; ++i) {
      if (in[i])
        cout << "y\n";
      else
        cout << "n\n";
    }
    memset(in, false, sizeof in);
  }
  return 0;
}
