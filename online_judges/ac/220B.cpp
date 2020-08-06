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
int arr[NMAX+5];
int ans[NMAX+5];

int n, q, l, r, S;

struct query{
	int l;
	int r;
	int block;
	int id;
};

int occ[NMAX+5];
int cur;

void add(int id){
	if(arr[id] > NMAX) return;
	if(occ[arr[id]] == arr[id]) cur--;
	occ[arr[id]]++;
	if(occ[arr[id]] == arr[id]) cur++; 
}

void dlt(int id){
	if(arr[id] > NMAX) return;
	if(occ[arr[id]] == arr[id]) cur--;
	occ[arr[id]]--;
	if(occ[arr[id]] == arr[id]) cur++;
}

query queries[NMAX+5];

bool cmp(query A, query B){
  if (A.block != B.block) return A.block < B.block;
  return A.block % 2 ? A.r > B.r : A.r < B.r;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	S = sqrt(n);
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		query qe;
		qe.l = l;
		qe.r = r;
		qe.block = l/S;
		qe.id = i;
		queries[i] = qe;
	}
	sort(queries, queries + q, cmp);
	l = 1;
	r = 0;
	for(int i = 0; i < q; i++){
		query qe = queries[i];
		while(r<qe.r){
			add(r+1);
			r++;
		}
		while(r>qe.r){
			dlt(r);
			r--;
		}
		while(l<qe.l){
			dlt(l);
			l++;
		}
		while(l>qe.l){
			add(l-1);
			l--;
		}
		ans[qe.id] = cur;
	}
	for(int i = 0; i < q; i++){
		cout << ans[i] << '\n';
	}
	return 0;
}


