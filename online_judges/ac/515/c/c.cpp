#include<bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    int tmp = s[i] - '0';
    if (tmp > 1) {
      if (tmp == 4) {
        v.push_back(3);
        v.push_back(2);
        v.push_back(2);
      } else if (tmp == 6) {
        v.push_back(5);
        v.push_back(3);
      } else if (tmp == 8) {
        v.push_back(7);
        v.push_back(2);
        v.push_back(2);
        v.push_back(2);
      } else if (tmp == 9) {
        v.push_back(7);
        v.push_back(3);
        v.push_back(3);
        v.push_back(2);
      } else {
        v.push_back(tmp);
      }
    }    
  }
  sort(v.rbegin(), v.rend());

  for (int x : v)
    cout << x;
  
  return 0;
}
