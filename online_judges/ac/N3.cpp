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
	int state[n+5];
	memset(state, 0, sizeof(state));
	char c;
	for(int i = 1; i <= n; i++){
		cin >> c;
		switch(c){
			case '+':{
				state[i] = state[i-1] + 1;
				break;
			}
			case '-':{
				state[i] = state[i-1] - 1;
				break;
			}
			case 'z':{
				int k;
				cin >> k;
				state[i] = state[i - k - 1];
				break;
			}
		}
	}
	cout << state[n];
	return 0;
}


