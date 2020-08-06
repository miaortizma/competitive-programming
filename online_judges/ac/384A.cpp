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
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		bool a = i%2 == 0;
		for(int j = 0; j < n; j++){
			if(a){
				ans++;
			}
			a = !a;
		}
	}
	cout << ans << '\n';
	for(int i = 0; i < n; i++){
		bool a = i%2 == 0;
		for(int j = 0; j < n; j++){
			if(a){
				cout << 'C';
			}else{
				cout << '.'; 
			}
			a = !a;
		}
		cout << '\n';
	}
	return 0;
}

