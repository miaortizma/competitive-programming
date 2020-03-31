#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma


bool numeric(char c) {
  return '0' <= c && c <= '9';
}

bool Numeric(string x) {
  if (x.size() > 1) return true;
  return numeric(x[0]);
}

bool cmple(string a, string b) {
  if (Numeric(a) && Numeric(b)) {
    int A = atoi(a.data()), B = atoi(b.data());
    return B < A;
  }
  if (a.size() > 1) {
    return false;
  }
  return b < a;
}

struct file {
  vector<string> v;
  file(string s) {
    int n = s.size();
    string lastNumeric = "";
    for (int i = 0; i < n; ++i) {
      if (!numeric(s[i])) {
        if (lastNumeric != "") {
          //cout << lastNumeric << "\n";
          v.push_back(lastNumeric);
          lastNumeric = "";
        }
        //cout << s[i] << "\n";
        stringstream sss;
        sss << s[i];
        string ss;
        sss >> ss;
        v.push_back(ss);
      } else {
        lastNumeric += s[i];
      }
    }
    if (lastNumeric != "") {
      //cout << lastNumeric << "\n";
      v.push_back(lastNumeric);
    }
    //cout << "@@@@@\n";
  }

  bool le(file b) {
    size_t i = 0;
    vector<string> vb = b.v;
    while (i < v.size() && i < vb.size()) {
      if (cmple(v[i], vb[i])) {
        return true;
      } else if (v[i] != vb[i]) {
        return false;
      }
      ++i;
    }

    // all equal until now
    return vb.size() < v.size();
  }
};


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  string s, p;
  cin >> n >> s;
  file f{s};
  file ff{"X52Y"}, bb{"32"};
  for (int i = 0; i < n; ++i) {
    cin >> p;
    file b{p};
    if (f.le(b)) {
      cout << "-\n";
    } else {
      cout << "+\n";
    }
  }

  return 0;
}
