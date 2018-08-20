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
	int n = s.size();	
	bool div[100];
	memset(div, false, sizeof(div));
	for(int i = 0; i <= 99; i++){
		if(i%4 == 0){
			//cout <<i <<'\n';
			div[i] = true;
		}
	}
	ll ans = 0;
	for(int i = 0; i < n; i++){
		int end = (s[i] - '0');
		if(div[end]){
			ans++;
		}
		if(i - 1 >= 0){
			end += (s[i-1] - '0')*10;
		}
		if(div[end]){
			ans += (i)*1LL;
		}
	}
	cout << ans << '\n';
	return 0;
	
}


