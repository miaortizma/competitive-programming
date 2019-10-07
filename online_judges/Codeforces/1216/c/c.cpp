#include<bits/stdc++.h>

using namespace std;

struct pt {
  int x, y;
  pt(int x, int y) : x(x), y(y) {}
  pt operator+(pt p) {return {x+p.x, y+p.y};}
  pt operator-(pt p) {return {x-p.x, y-p.y};}
};

struct box {
  pt A, B;
  box(pt A, pt B) : A(A), B(B) {}
};

bool between(int x1, int x2, int y1, int y2) {
  return x1 <= y1 && y2 <= x2;
}

bool inside(box X, box Y) {
  //cout << "in\n";
  //cout << Y.A.x << ' ' << Y.B.x << ' ' << X.A.x << ' ' << X.B.x << '\n';
  if (!between(Y.A.x, Y.B.x, X.A.x, X.B.x))
    return false;
  //cout << "1\n";
  //cout << Y.A.y << ' ' << Y.B.y << ' ' << X.A.y << ' ' << X.B.y << '\n';
  if (!between(Y.A.y, Y.B.y, X.A.y, X.B.y))
    return false;
 // cout << "inside!\n";
  return true;
}

bool cover(box W, box B1, box B2) {
  if (between(B1.A.x, B1.B.x, W.A.x, W.B.x)) {
    int l = max(W.A.y, B1.A.y), r = min(W.B.y, B1.B.y);
    if (l <= r && l == W.A.y && r <= W.B.y) {
      pt a{W.A.x,r}, b{W.B.x, W.B.y};
      box t(a, b);
      if (inside(t, B2)) 
        return true;
    }
  }
  if (between(B1.A.y, B1.B.y, W.A.y, W.B.y)) {
    int l = max(W.A.x, B1.A.x), r = min(W.B.x, B1.B.x);
    if (l <= r && l == W.A.x && r <= W.B.x) {
      pt a{r, W.A.y}, b{W.B.x, W.B.y};
      box t(a, b);
      if (inside(t, B2)) 
        return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int arr[4];
  for (int i = 0; i < 4; ++i)
    cin >> arr[i];
  pt w1{arr[0], arr[1]}, w2{arr[2], arr[3]};  
  box white(w1, w2);
  for (int i = 0; i < 4; ++i)
    cin >> arr[i];
  pt b1{arr[0], arr[1]}, b2{arr[2], arr[3]};
  box black1(b1, b2);
  for (int i = 0; i < 4; ++i)
    cin >> arr[i];
  pt b3{arr[0], arr[1]}, b4{arr[2], arr[3]};
  box black2(b3, b4);
  if (inside(white, black1) || inside(white, black2) || cover(white, black1, black2) || cover(white, black2, black1)) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
