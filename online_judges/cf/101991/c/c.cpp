#include<bits/stdc++.h>
using namespace std;

const int N = 110;

struct cost {
  int small, medium, large;

  cost() : small(0), medium(0), large(0) {}
  cost(int small, int medium, int large) : small(small), medium(medium), large(large) {}
} costs[N];


int main() {
  freopen("coffee.in", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T, c, p, s, m, l;
  string name, person, size;
  cin >> T;
  while (T--) {
    cin >> c >> p;
    map<string, int> coffe;
    int I = 0;
    for (int i = 0; i < c; ++i) {
      cin >> name >> s >> m >> l;
      costs[I] = {s, m, l};
      coffe[name] = I++;
    }
    int fee = 100 / p;

    for (int i = 0; i < p; ++i) {
      cin >> person >> size >> name;
      cout << person << " ";
      int c = 0;
      if (size == "small") {
        c = costs[coffe[name]].small + fee;
      } else if (size == "medium") {
        c = costs[coffe[name]].medium + fee;
      } else {
        c = costs[coffe[name]].large + fee;
      }
      if (c % 10 == 4 || c % 10 == 9) c++;
      if (c % 10 == 6 || c % 10 == 1) c--;
      cout << c << "\n";
    }
  }
  return 0;
}
