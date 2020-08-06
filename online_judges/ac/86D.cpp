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

const int NMAX = 200000;
int n, q, l , r, S;

int arr[NMAX+10];
int cnt[1000010];

struct Query{
	int id;
	int block;
	int l;
	int r;
};

Query qris[NMAX+10];

bool cmp(Query A, Query B){
  if (A.block != B.block) return A.block < B.block;
  return A.block % 2 ? A.r > B.r : A.r < B.r;
}

ll ans = 0;
ll answ[NMAX+10];

ll f(ll x, ll y){
	return x*x*y;
}

void add(int id){
	//cerr << "add: " << arr[id] << '\n';
	ans -= f(cnt[arr[id]], arr[id]);
	cnt[arr[id]]++;
	ans += f(cnt[arr[id]], arr[id]);
}

void dlt(int id){
	//cerr << "dlt: " << arr[id] << '\n';
	ans -= f(cnt[arr[id]], arr[id]);
	cnt[arr[id]]--;
	ans += f(cnt[arr[id]], arr[id]);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> n >> q;
	S = sqrt(n);
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		Query qe;
		qe.l = l;
		qe.r = r;
		qe.id = i;
		qe.block = qe.l/S;
		qris[i] = qe; 
	}
	sort(qris, qris + q, cmp);
	l = 1;
	r = 0;
	for(int i = 0; i < q; i++){
		Query qe = qris[i];
		while(r < qe.r){
			r++;
			add(r);
		}
		while(r > qe.r){
			dlt(r);
			r--;
		}
		while(l < qe.l){
			dlt(l);
			l++;
		}
		while(l > qe.l){
			l--;
			add(l);
		}
		answ[qe.id] = ans;
	}
	for(int i = 0; i < q; i++){
		cout << answ[i] << '\n';
	}
	return 0;
}


