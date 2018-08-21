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
	cin >> n;
	string s;
	cin >> s;
	int l = 0;
	int r = n - 1;
	bool X = false, Y = false;
	int fr = -1, fl = -1;
	while(l < n){
		if((s[l] == '.' && !X ) || s[l] == 'R'){
			if(s[l] == 'R' && !X){
				fl = l;
				X = true;
			}
			l++;
		}else{
			break;
		}
	}
	while(r >= 0){
		if((s[r] == '.' && !Y) || s[r] == 'L'){
			if(s[r] == 'L' && !Y){
				fr = r;
				Y = true;
			}
			r--;
		}else{
			break;
		}
	}
	fl++;
	fr++;
	l++;
	r++;
	if(X){
		if(Y){
			cout << fl << ' ' << r;
		}else{
			cout << fl << ' ' << l;	
		}
	}else if(Y){
		cout << fr << ' ' << r;
	}
	return 0;
}


