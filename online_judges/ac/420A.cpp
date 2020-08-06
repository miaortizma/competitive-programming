#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#ifdef PAPITAS
	#define DEBUG 1
#else
	#define DEBUG 0
#endif
#define _DO_(x) if(DEBUG) x
//			   A	 B      C	   D      E      F      G      H     I     J      K      L      M     N      O     P      Q      R      S      T     U     V     W     X     Y     Z
bool mirror[] = {true, false, false, false, false, false, false, true, true, false, false, false, true, false, true, false, false, false, false, true, true, true, true, true, true, false};

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	string s;
	cin >> s;
	int n = s.size();
	bool m = true;
	for(int i = 0; i <= n/2; i++){
		if(!mirror[s[i] - 'A'] || s[i] != s[n - 1 - i]){
			m = false;
			break;
		}
	}
	if(n == 1){
		m = mirror[s[0] - 'A'];
	}
	if(m){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}

