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

const int nmax = 1e5;
int n, m, l, r, q, c;

int len = ceil(sqrt(nmax));

int d[len+10];
int c[len+10];
int b[nmax+10];
int a[nmax+10];

void paint(int l, int r, int c){
	int L = l/len;
	int R = r/len;
	for(int i = l; i <= r; ){
		if(i % len == 0 && i + len - 1 <= r ){
			d[i/len] += abs(c[i/len] - c)*len;
			c[i/len] = c;
			i += len;
		}else{
			b[i] += abs(a[i] - c);
			d[i/len] += abs(a[i] - c);
			a[i] = c;
			i++;
		}
	}
}

int query(int l, int r){
	int ans = 0;
	for(int i = l; i <= r; ){
		if(i % len == 0 && i + len - 1 <= r ){
			
		}else{
		}
	}
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
	cin >> n >> m;
	cout << BLC << '\n';
	while(m){
		cin >> q >> l >> r;
		l--;
		r--;
		if(q == 1){
			cin >> c;
			paint(l, r, c);
		}else{
			query(l, r);
		}
	}
	return 0;
}

