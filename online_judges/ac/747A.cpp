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
	int n, bestdiff, a = -1 , b = -1, c, diff;
	cin >> n;
	bestdiff = n;
	for(int i = 1; i <= n/2 + 1; i++){
		c = n/i;
		if(c*i == n){
			diff = abs(c - i);
			if(diff < bestdiff){
				bestdiff = diff;
				a = c;
				b = i;
			}
		}
	}
	if(a > b){
		swap(a,b);
	}
	cout << a << ' ' << b << '\n';
	return 0;
}


