#include<bits/stdc++.h>
using namespace std;
mt19937 rng;
string s = "";

bool check(char a, char b) {
  string ans;
  cout << "? " << a << ' ' << b << '\n';
  cin >> ans;
  return ans == "<";
}

void quicksort(int i, int j) {
  if (i >= j) return;
  int m = uniform_int_distribution<int>(i, j)(rng);
  vector<char> left, right;
  string ans;
  for (int k = i; k <= j; ++k) {
    if (k == m)
      continue;
    if (check(s[k], s[m]))
      left.push_back(s[k]);
    else
      right.push_back(s[k]);
  }
  int l = left.size();
  s[i+l] = s[m];
  for (int k = i; k < i + l; ++k)
    s[k] = left[k - i];
  for (int k = i + l + 1; k <= j; ++k)
    s[k] = right[k - (i + l + 1)];
  quicksort(i, i + l - 1);
  quicksort(i + l + 1, j);
}

void mergesort(int i, int j) {
  if (i >= j) return;
  if (j - i == 1) {
    if (!check(s[i], s[j]))
      swap(s[i], s[j]);
    return;
  }
  int m = i + (j - i) / 2;
  //cout << m << ' ' << i << ' ' << j << '\n';
  mergesort(i, m);
  mergesort(m + 1, j);
  int p = i, q = m + 1;
  string ans = "";
  while (p < m + 1 && q < j + 1) {
    if (check(s[p], s[q])) {
      ans += s[p];
      ++p;
    } else {
      ans += s[q];
      ++q;
    }
  }
  while (p < m + 1)
    ans += s[p++];
  while (q < j + 1)
    ans += s[q++];
  for (int k = i; k <= j; ++k)
    s[k] = ans[k - i];
}

int main() { 
  int N, Q;
  cin >> N >> Q;
  for (int i = 0; i < N; ++i) s += (char) ('A' + i);
  mergesort(0, N - 1);
  cout << "! " << s << endl;
}
