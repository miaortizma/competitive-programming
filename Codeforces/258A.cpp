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

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	string s;
	cin >> s;
	int i;
	for(i = 0; i < s.size(); i++){
		if(s[i] == '0') break;
	}
	if(i == s.size()){
		for(int i = 0; i < s.size() - 1; i++){
			cout << s[i];
		}
	}else{
		for(int j = 0; j < s.size(); j++){
			if(j != i) cout << s[j];
		}
	}
	return 0;
}

