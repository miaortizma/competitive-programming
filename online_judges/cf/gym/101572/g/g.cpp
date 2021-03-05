#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

#define F first
#define S second

const int N = 1e5 + 10;

typedef pair<int, int> pi;
pi score[N];
int last[N], cnt[N];

struct event {
  pi score;
  int id, t;
};

bool comparePi(pi a, pi b) {
  if (a.F == b.F) {
    return a.S < b.S;
  }
  return a.F > b.F;
}

bool compare(event a, event b) { 
  return comparePi(a.score, b.score);
};

priority_queue<event, vector<event>, decltype(&compare)> pq(compare);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  int n, m, a, b;
  cin >> n >> m;

  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    cin >> a >> b;
    pi prev = score[a];
    score[a] = {prev.F + 1, prev.S + b};
    last[a] = i;
    if (a == 1) {
      while (!pq.empty()) {
        event e = pq.top();
        pi pa = e.score;
        if (e.score == score[1] || comparePi(score[1], e.score)) {
          pq.pop();
          if (e.t == last[e.id]) ans--;
        } else {
          break;
        }
      }
    } else {
      if (comparePi(score[a], score[1])) {
        event e{score[a], a, i};
        pq.push(e);
        if (prev == score[1] || comparePi(score[1], prev)) {
          ans++;
        };
      }
    }
    cout << ans + 1 << "\n";
  }
  /*
  while (!pq.empty()) {
    event e = pq.top(); pq.pop();
    pi pa = e.score;
    cout << pa.F << " " << pa.S << "\n";
  }
  */
  return 0;
}
