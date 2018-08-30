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

int square(int x){
	return x * x;
}

int f(int a, int b){
	return square(2*a + 2*b)/a*b;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	for(int i = 1; i < 100; i++){
		for(int j = 1; j < 100; j++){
			cout << i << ' ' << j << ':' << f(i, j) << '\n'; 
		}
	}
	return 0;
}

