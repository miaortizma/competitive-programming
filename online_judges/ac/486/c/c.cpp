#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int arr[N];
int vis[N];

int n, p, S, flag, left_, right_;

int steps(int side, int direction) {
  int cS = 0;
  int i = p;
  ++flag;
  int ans = 0;
  int cleanLeft = left_, cleanRight = right_;
  if (side) {
    cleanRight = n - 1 - left_;
    cleanLeft = n - 1 - right_;
  }
 
  while(true) {
    // change position
    if ( ((side && i >= n / 2) || (!side && i < n / 2)) && vis[i] != flag ) {
      vis[i] = flag;
      cS += arr[i];
    }

    if (cS == S)
      break;

    // change direction 
    
    if (direction && i == cleanRight)
      direction = -1;

    if (direction == -1 && i == cleanLeft)
      direction = 1;

    i = (i + n + direction) % n;
    ++ans;
  }
  
  return ans + S;
}

int main() {
  string s;
  cin >> n >> p >> s;
  --p;

  for (int i = 0; i < n / 2; ++i) {
    int dist = abs(s[i] - s[n - 1 - i]);
    dist = min(dist, 26 - dist);
    S += dist;
    arr[i] = arr[n - 1 - i] = dist;
  }

  left_ = 0;
  right_ = n / 2 - 1;
  
  while (arr[left_] == 0 && left_ < n / 2)
    ++left_;
  
  while (arr[right_] == 0 && right_ >= 0)
    --right_;

  int ans = min({steps(0, -1), steps(0, 1), steps(1, -1), steps(1, 1)});
  
  cout << ans << '\n';
  
  return 0;
}
