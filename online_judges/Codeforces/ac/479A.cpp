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
		//freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    ans = max(ans, a+b+c);
    ans = max(ans, a+b*c);
    ans = max(ans, a*b+c);
    ans = max(ans, a*b*c);
    ans = max(ans, (a+b)*c);
    ans = max(ans, a*(b+c));
    cout << ans << '\n';
    return 0;
}
