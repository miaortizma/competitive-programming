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

const int NMAX = (int)1e5;
ll arr[NMAX+5];

ll sum(ll x){
	return (x*(x+1))/2;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << setprecision(15);
	ll n, m;
	ll qx, qd;
	ll total = 0;
	cin >> n >> m;
	while(m--) {
		cin >> qx >> qd;
		total += qx*n;
		if(qd >= 0){
			total += qd*sum(n-1);
		}else{
			if(n%2 == 1){
				total += qd*sum(n/2)*2;	
			}else{
				total += qd*sum(n/2) + qd*sum(n/2 - 1);
			} 
		}
	}
	double mean = total/(double)n;
	cout << mean << '\n';
	return 0;
}


