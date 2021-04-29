#include <bits/stdc++.h>

using namespace std;

string ltrim(const string&);
string rtrim(const string&);

/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */


inline int c2i(char x) {
  if (x == 'A') {
    return 0;
  }
  if (x == 'T') {
    return 1;
  }
  if (x == 'C') {
    return 2;
  }
  if (x == 'G') {
    return 3;
  }
  return -1;
}

map<int, char> i2c;

int CNT_GENE[4];

int N;

int EXCESS[4];
int CUR[4];

bool test(const string& gene, int k) {
  for (int i = 0; i < 4; ++i) {
    CUR[i] = 0;
  }
  for (int i = 0; i < k - 1; ++i) {
    CUR[c2i(gene[i])]++;
  }
  for (int i = 0; i <= N - k; ++i) {
    int l = i;
    int r = i + k - 1;
    CUR[c2i(gene[r])]++;
    // check
    bool ok = true;
    for (int j = 0; j < 4; ++j) {
      ok &= CUR[j] >= EXCESS[j];
    }
    if (ok) return true;
    CUR[c2i(gene[l])]--;
  }
  return false;
}

int steadyGene(string gene) {
  i2c[0] = 'A';
  i2c[1] = 'T';
  i2c[2] = 'C';
  i2c[3] = 'G';

  N = gene.size();
  // count excess
  int have = N / 4;
  for (int i = 0; i < N; ++i) {
    CNT_GENE[c2i(gene[i])]++;
  }

  bool zero = true;

  for (int i = 0; i < 4; ++i) {
    EXCESS[i] = max(0, CNT_GENE[i] - have);
    if (EXCESS[i] != 0) zero = false;
    //cout << i2c[i] << " " << EXCESS[i] << "\n";
  }

  if (zero) {
    return 0;
  }

  //cout << test(gene, 5);
  //return 5;

  // find smallest length with binary search

  int l = 0, h = N;
  while (l < h) {
    int m = (l + h) / 2;
    //cout << m << " " << (test(gene, m) ? "Yes" : "No") << "\n";
    if (!test(gene, m)) {
      l = m + 1;
    }
    else {
      h = m;
    }
  }

  return l;
}

int main()
{
  int n;
  string gene;
  cin >> n >> gene;

  int result = steadyGene(gene);
  cout << result;

  return 0;
}
