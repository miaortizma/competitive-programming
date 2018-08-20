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
	int x1, y1, x2, y2, a, b;
	cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
	if( (x2 - x1)%a == 0 && (y2 - y1)%b == 0 && ( (abs(x2 - x1)/a)%2 == (abs(y2 - y1)/b)%2 ) ){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}


