#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5;
int seql, seqlt;
int arr[N], sz[N], idd[N], l[N];

int root(int i) {
  while (idd[i] != i) {
    idd[i] = idd[idd[i]];
    i = idd[i];
  }

  return i;
}

void merge(int x, int y) {
  x = root(x), y = root(y);
  if (x == y)
    return;
  if (sz[x] < sz[y])
    swap(x, y);
  idd[y] = x;
  sz[x] += sz[y];
  seql = max(seql, sz[x]);
}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k, tmp;
  cin >> n >> k;
  vector<pii> seq;
  for (int i = 0; i < n; ++i) {
    idd[i] = i;
    sz[i] = 1;
    cin >> arr[i];
    seq.push_back(pii({arr[i], i}));
  }
  sort(seq.rbegin(), seq.rend());
  long long ans = 0;
  for (int i = 1; i < n; ++i) {
    int j = seq[i].second;
    if (seq[i-1].first > seq[i].first)
      seqlt = seql;
    if (seqlt >= k)
      ans += arr[j];
    cout << arr[j] << ' ' << seqlt << '\n';
    
   
    if (j+1 < n && arr[j+1] >= arr[j]) 
      merge(j, j+1);
    if (j-1 >= 0 && arr[j-1] >= arr[j])
      merge(j, j-1);
  }
  long long test = 0;
  for (int i = n - 1; i >= 0; --i) {
    test += seq[i].first;
    if (test == -15675370) {
      cout << "sz:" << n - i << '\n';
      break;
    }
  }
  cout << seql << '\n';
  cout << ans;
  return 0;
}
