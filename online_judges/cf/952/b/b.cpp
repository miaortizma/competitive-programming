#include<bits/stdc++.h>
using namespace std;

vector<string> normal = {"great", "cool", "don't touch me", "not bad", "don't think so"};
vector<string> grumpy = {"don't even", "worse", "terrible", "go die in a hole", "no way", "are you serious"};

bool check(string s) {
  for (string ss : normal) {
    if (s == ss) return true;
  }
  return false;
}

int main() {
  string s;
  for (int i = 0; i < 6; ++i) {
    cout << i << "\n";
    fflush(stdout);
    getline(cin, s);
    if (s != "no") {
      if (check(s))
        cout << "normal\n";
      else
        cout << "grumpy\n";
      break;
    }
  }
  fflush(stdout);
  return 0;
}
