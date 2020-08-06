#include<bits/stdc++.h>
using namespace std;

bool check(int F[4], vector<int> C ) {
  for (int i = 0; i < 4; ++i) {
    if(F[i] != C[i]) 
      return false;
  }

  return true;
}

bool checkIn(int minVal, int maxVal, int val) {
  return minVal <= val && val <= maxVal;
}

int minX, minY, maxX, maxY;
int q, n, x, y;
bool posb;

int main() {
  cin >> q;
  while(q--) {
    cin >> n;

    minX = minY = -1e5;
    maxX = maxY = 1e5;
    posb = true;

    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      int F[4];
      
      for (int i = 0; i < 4; ++i)
        cin >> F[i];
      
      // check - x
      if(F[0] && !F[2]) { // left
        if (maxX <= x || minX <= x) {
          maxX = min(maxX, x);
        } else {
          posb = false;
        }
      } else if (!F[0] && F[2]) { // right
        if (x <= minX || x <= maxX) {
          minX = max(minX, x);
        } else {
          posb = false;
        }
      } else if(!F[0] && !F[2]) { // none
        if (checkIn(minX, maxX, x)) {
          minX = maxX = x;
        } else {
          posb = false;
        }
      }
      // check - y
      if(F[1] && !F[3]) { // up
        if (y <= minY || y <= maxY) {
          minY = max(minY, y);
        } else {
          posb = false;
        }
      } else if (!F[1] && F[3]) { // down
        if (maxY <= y || minY <= y) {
          maxY = min(maxY, y);
        } else {
          posb = false;
        }
      } else if(!F[1] && !F[3]) { // none
        if (checkIn(minY, maxY, y)) {
          minY = maxY = y;
        } else {
          posb = false;
        }
      }
    }
    if (posb && minX <= maxX && minY <= maxY) {
      cout << 1 << ' ' << minX << ' ' << minY << '\n';
    } else {
      cout << 0 << '\n';
    }
  }
  return 0;
}