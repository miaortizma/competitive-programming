#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma

int main() {
  int n;
  scanf("%d", &n);
  int cur = 1, depth = 0;
  // get depth
  printf("1\n");
  fflush(stdout);
  scanf("%d", &depth);
  if (depth == 0) {
    printf("! 1\n");
    fflush(stdout);
  } else {
    for (int i = 0; i < depth; ++i) {
      printf("%d\n",  2 * cur);
      fflush(stdout);
      int d;
      scanf("%d", &d);
      if (d == depth - (i + 1)) {
        cur = 2 * cur;
      } else {
        cur = 2 * cur + 1;
      }
    }
    printf("! %d\n", cur);
    fflush(stdout);
  }
  return 0;
}
