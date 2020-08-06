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
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	n--;
	int ans = 0, state = 0;
	while(n--){
		//cout << state << '\n';
		switch(state){
			case 0:{
				if(a < b){
					ans += a;
					state = 1;
				}else{
					ans += b;
					state = 2;
				}
				break;
			}
			case 1:{
				if(a < c){
					ans += a;
					state = 0;
				}else{
					ans += c;
					state = 2;
				}
				break;
			}
			case 2:{
				if(b < c){
					ans += b;
					state = 0;
				}else{
					ans += c;
					state = 1;
				}
				break;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

