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
	int T;
	cin >> T;
	while(T--){
		ll x, n;
		cin >> x >> n;
		ll ind = (x-1)/(n-1);
		ll rem = (x-1)%(n-1);
		if(ind%2 == 0){
				ll cookies = div/2 + 1;
				cout << 1 + cookies << ' ';
				for(int i = 0; i < rem; i++){
					cout << 2*cookies + 1 << ' ';
				}
				for(int i = rem; i < n-2;i++){
					cout << 2*cookies << ' ';
				}
				cout << 1 + cookies - 1 << '\n';
		}else{
			ll cookies = div/2;
			cout << 1 + cookies << ' ';
			for(int i = rem; i < n-2 ;i++){
				cout << 2*cookies + 1<< ' ';
			}
			for(int i = 0; i < rem; i++){
				cout << 2*cookies + 2 << ' ';
			}
			cout << 1 + cookies << '\n'; 
		}
		
	}
	return 0;
}

