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

set<int> test;

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n, m;
	string s;
	cin >> n >> m;
	bool check = true;
	
	for(int i = 0; i < n; i++){
		cin >> s;
		int a, b;
		for(int j = 0; j < m; j++){
			if(s[j] == 'G' ){
				a = j;
			}else if(s[j] == 'S'){
				b = j;
			}
		}
		if(b < a){
			check = false;
		}
		test.insert(b - a);
	}
	
	if(check){
		cout << test.size();
	}else{
		cout << -1;
	}
	return 0;
}

