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

const int NMAX = (int)1e5, mod = (int)1e9 + 7;
int arr[NMAX+10];
ll prr[NMAX+10];
int frst[NMAX+10];
int scnd[NMAX+10];
vector<int> nds[NMAX+10];
ll f[NMAX+10];
int n, q, a, b, l, r;

ll sum(ll a, ll b){
	return (a + b + mod)%mod;
}

ll rst(ll a, ll b){
	return (a - b + mod)%mod;
}

ll mlt(ll a, ll b){
	return (a%mod*b%mod)%mod;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> n >> q >> f[1] >> f[2] >> a >> b;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		if(i > 2){
			f[i] = sum(mlt(a, f[i-2]), mlt(b, f[i-1]));
		}
		//cout << f[i] << ' ';
	}
	//cout << '\n';
	
	while(q--){
		cin >> l >> r;
		frst[l]++;
		if(l+1<=r) scnd[l+1]++;
		nds[r+1].push_back(r - l + 1);
	}
	//cout << '\n';
	for(int i = 1; i <= n; i++){	
		for(int j = 0; j < nds[i].size(); j++){
			int s = nds[i][j];
			if(s == 1){
				frst[i-1]--;
			}else if(s == 2){
				scnd[i-1]--;
				frst[i-2]--;
			}else{
				prr[i-2] = rst(prr[i-2], f[s-1]);
				prr[i-1] = rst(prr[i-1], f[s]);
			}
		}
		ll extra = sum(mlt(frst[i], f[1]), mlt(scnd[i], f[2]));
		/*
		if(i == 4){
			cerr << "--\n";
			cerr << "arr-i: " << arr[i] << '\n';
			cerr << "prr-i: " << prr[i] << '\n';
			cerr << "extra: " << extra << '\n';
			cerr << "arr-i-1: " << prr[i - 1] << '\n';
			cerr << "arr-i-2: " << prr[i - 2] << '\n';
			cerr << "--\n";
		}
		*/
		int A = mlt(sum(prr[i-1], mlt(scnd[i-1], f[2])), b);
		int B = mlt(sum(prr[i-2], sum(mlt(frst[i-2], f[1]), mlt(scnd[i-2], f[2]))), a);
		prr[i] = sum(prr[i], sum(A, B) );
		cout << sum(arr[i], sum(prr[i], extra)) << ' ';
	}
	cout << '\n';
	return 0;
}


