#include<bits/stdc++.h>
using namespace std;

int day[7] = {0, 1, 2, 0,  2, 1, 0};

int maxWeeks(int arr[3]) {
  int ret = 0;
  int mm = min(arr[0] / 3, min(arr[1] / 2, arr[2] / 2));
  ret += 7 * mm;
  arr[0] -= mm * 3;
  arr[1] -= mm * 2;
  arr[2] -= mm * 2;
  for (int i = 0; i < 7; ++i) {
    if (!arr[day[i]])
      break;
    ++ret;
    --arr[day[i]];
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(NULL);
  int arr[3];
  for (int i = 0; i < 3; ++i)
    cin >> arr[i];
  int ans = 0;
  for (int i = 0; i < 7; ++i) {
    int days = 0;
    int brr[3] = {arr[0], arr[1], arr[2]};
    int j;
    for (j = i; j < 7; ++j) {
      if (!brr[day[j]])
        break;
      --brr[day[j]];
      ++days;
    }
    if (j == 7)
      days += maxWeeks(brr);
    ans = max(ans, days);
  }
  cout << ans;
  return 0;
}
