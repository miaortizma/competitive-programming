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
	int n;
	string s;
	cin >> n >> s;
	int sea = 0, san = 0;
	for(int i = 1; i < n; i++){
		if(s[i] == 'F' && s[i-1] == 'S'){
			//cout << "<" << i << '\n';
			sea++;
		}else if(s[i] == 'S' && s[i-1] == 'F'){
			//cout << ">" << i << '\n';
			san++;
		}
	}
	if(sea > san){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}

