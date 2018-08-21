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
	int a, b, c;
	cin >> a >> b >> c;
	bool pos[c+1];
	memset(pos, false, sizeof(pos));
	pos[a] = true;
	pos[b] = true;
	for(int i = min(a, b); i <= c; i++){
		if((i - a > 0 && pos[i-a]) || (i - b > 0 && pos[i-b])){
			pos[i] = true;
		}
	}
	if(pos[c]){
		cout << "Yes";
	}else{
		cout << "No";
	}
	return 0;
}


