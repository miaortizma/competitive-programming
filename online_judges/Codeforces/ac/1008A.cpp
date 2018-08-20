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

char vow[] = {'a', 'o', 'u', 'i', 'e'};

bool vowel(char x){
	for(int i = 0; i < 5; i++){
		if(x == vow[i]) return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	string s;
	cin >> s;
	int n = s.size();
	bool mustvow = false;
	bool posb = true;
	for(int i = 0; i < n; i++){
		bool v = vowel(s[i]);
		//cout << v << ' ';
		if(mustvow){
			if(!v){
				posb = false;
			}else{
				mustvow = false;
			}
		}else if(!v && s[i] != 'n'){
			mustvow = true;
		}
	}
	if(posb && !mustvow){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}


