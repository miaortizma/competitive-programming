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
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n, k;
	string s;
	cin >> n >> k >> s;
	int len = n;
	for(int i = 1; i < n; i++){
		bool ok = true;
		for(int j = 0; j < n - i; j++){
			if(s[i + j] != s[j]){
				ok = false;
			}
		}
		if(ok){
			len = i;
			break;
		}
	}
	for(int i = 0; i < k; i++){
		if(i == 0){
			for(int j = 0; j < n; j++){
				cout << s[j];
			}
		}else{
			for(int j = n - len; j < n; j++){
				cout << s[j];
			}
		}
	}
	return 0;
}

