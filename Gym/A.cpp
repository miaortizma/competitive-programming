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

#define x(t) get<0>(t)
#define y(t) get<1>(t)
#define v(t) get<2>(t)


const int KMAX = 1e9;
const int NMAX = 1e5;
int m, k;
typedef tuple<int,int,int> triple;

triple arr[NMAX+10];


int bin(int lo, int s){
	int hi = m, mid;
	while(lo < hi){
		mid = (lo + hi)/2;
	}
}

bool cmp(triple a, triple b){
	return x(a) < x(b);
}

void print(triple X){
	cout << x(X) << ' ' << y(X) << ' ' << v(X) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	cin >> T; 
	while(T--){
		cin >> m >> k;
		int l, r, v;
		for(int i = 0; i < m; i++){
			cin >> l >> r >> v;
			arr[i] = triple(l,r,v);
		}
		sort(arr, arr + m, cmp);
		int ans = 0;
		for(int i = 0; i < m; i++){
			int s = x(arr[i]);
			int f = y(arr[i]);
			int ind = bin(i, min(s + k - 1, KMAX));
			int constant = 0;
			for(int j = i + 1; j < lo; j++){
				
			}
		}
		
	}
	return 0;
}

