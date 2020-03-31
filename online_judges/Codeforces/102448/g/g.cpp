#include<bits/stdc++.h>
using namespace std;
// By Miguel Ortiz https://github.com/miaortizma


typedef long long ll;

const int N = 5 * 1e4;

map<string, int> userId; 
string handle[N];
ll userScore[N];

map<string, ll> problemScore;


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int C, P, S;
  string candidate, problem, verdict;
  ll score;
  cin >> C >> P >> S;
  for (int i = 0; i < C; ++i) {
    cin >> candidate;
    userId[candidate] = i;
    handle[i] = candidate;
  }
  for (int i = 0; i < P; ++i) {
    cin >> problem >> score;
    problemScore[problem] = score;
  }
  for (int i = 0; i < S; ++i) {
    cin >> candidate >> problem >> verdict;
    if (verdict == "AC") {
      if (userId.count(candidate) != 0 && problemScore.count(problem) != 0) {
        userScore[userId[candidate]] += problemScore[problem];
      }
    }
  }

  for (int i = 0; i < C; ++i) {
    cout << handle[i] << " " << userScore[i] << "\n";
  }
  return 0;
}
