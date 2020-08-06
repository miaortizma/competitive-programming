#include<bits/stdc++.h>
using namespace std;

string s;
const int N = 110;
int n;
bool angry[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'A')
        angry[i] = true;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (angry[i]) {
        int j = i;
        while (j + 1 < n && !angry[j + 1]) {
          j++;
        }
        ans = max(ans, j - i);
      } 
    }
    memset(angry, false, sizeof angry);
    cout << ans << "\n";
  }
  return 0;
}
