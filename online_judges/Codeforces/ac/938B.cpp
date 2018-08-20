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

const int NMAX = 1e6;

bool prize[NMAX+1];

int main()
{
	int n, tmp;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> tmp;
		prize[tmp] = true;
	}
	int l = 1, r = NMAX, ans;
	while(l < r){
		l++;
		r--;
		if(prize[l]){
			prize[l] = false;
			ans = l - 1;
		}
		if(prize[r]){
			prize[r] = false;
			ans = l - 1;
		}
	}
	cout << ans << '\n';
	return 0;
}


