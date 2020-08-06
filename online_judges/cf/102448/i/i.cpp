#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int S, N, M, val;

struct coord {
  int x, y, id;
  coord(int x, int y) : x(x), y(y) {
    id = x * M + y;
  }

  bool valid() {
    return 0 <= x && x < N && 0 <= y && y < M;
  }
};

const int MAX_N = 1e6 + 100;


int arr[MAX_N], sz[MAX_N];
map<int, vector<coord>> mp;

int root(int i) {
  while(arr[i] != i) {
    arr[i] = arr[arr[i]];
    i = arr[i];
  }
  return i;
}

int ans;
bool found_ans;

void un(int x, int y) {
  x = root(x); y = root(y);
  if (x == y) return;
  if (sz[x] < sz[y]) swap(x, y);
  sz[x] += sz[y];
  if (sz[x] >= S) found_ans = true;
  arr[y] = x;
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> S >> N >> M;
  vector<int> depths[N];
  vector<int> values(N * M);

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> val;
      depths[i].push_back(val);
      mp[val].push_back(coord(i, j));
      int id_ = i * M + j;
      values[id_] = val;
      arr[id_] = id_;
      sz[id_] = 1;
    }
  }

  sort(values.rbegin(), values.rend());
  ans = values[0];
  if (S != 1) {
    int last = values[0] - 1;
    const int NN = N * M;
    for (int i = 0; i < NN; ++i) {
      if (values[i] != last) {
        last = values[i];
        //cout << last << "\n";
        for (coord C : mp[last]) {
          for (int i = 0; i < 4; ++i) {
            coord O{C.x + dx[i], C.y + dy[i]};
            if (O.valid() && depths[O.x][O.y] >= last) {
              un(C.id, O.id);
            }
          }
          //cout << C.x << " " << C.y << "\n";
        }
      }
      if (found_ans) {
        ans = last;
        break;
      }
    }
  }
  cout << ans << "\n";

  return 0;
}
