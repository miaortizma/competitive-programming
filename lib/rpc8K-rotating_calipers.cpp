#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#ifdef PAPITAS
	#define DEBUG 1
#else
	#define DEBUG 0
#endif
#define _DO_(x) if(DEBUG)
#define x first
#define y second

const int NMAX = (int)1e5*2;
typedef pair<ll,ll> pii;

int n, r, x, y;
pii P[NMAX+5];
ll dir(pii p, pii q, pii r){
	return (q.y-p.y)*(r.x-p.x) - (q.x-p.x)*(r.y-p.y);
}

void print(pii A){
	cout << A.x << ' ' << A.y << endl;
}

bool F = true;
double ans;

double square(double x){
	return x*x;
}


double vDist(pii O, pii A, pii B){
	double num = abs((B.y-A.y)*O.x - (B.x-A.x)*O.y + B.x*A.y - B.y*A.x);
	double denom(sqrt(square(B.y-A.y) + square(B.x-A.x)));
	return num/denom;
}

double aDist(pii O, pii A, pii B){
	if(F){
		ans = vDist(O, A, B);
		F = false;
	}else{
		ans = min(ans, vDist(O, A, B));
	}
	
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> n >> r;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		P[i] = pii(x, y);
	}
	sort(P, P + n);
	vector<pii> U, L;
	cout << fixed << setprecision(9);
	//monotone chain
	for(int i = 0; i < n; i++){
		while(L.size() >= 2 && dir(L[L.size() - 2], L[L.size() - 1], P[i]) >= 0) L.pop_back();
		while(U.size() >= 2 && dir(U[U.size() - 2], U[U.size() - 1], P[i]) <= 0) U.pop_back();
		L.push_back(P[i]);
		U.push_back(P[i]);
	}
	int i = 0, j = L.size() - 1;
	int lasti = i, lastj = j;
	//antipodal pairs with area
	while(i < U.size() - 1 || j > 0){
		//antipodal vertex-edge pair detected
		if(lasti != i){
			aDist(L[j], U[i], U[i-1]);
		}else if(lastj != j){
			aDist(U[i], L[j], L[j+1]);
		}
		lasti = i;
		lastj = j;
		if(i == U.size() - 1){ j--;}
		else if(j == 0){ i++;}
		else if( (U[i+1].y - U[i].y)*(L[j].x - L[j-1].x) > (U[i+1].x - U[i].x)*(L[j].y - L[j-1].y) ){ i++;}
		else{j--;}
	}
	if(lasti != i){
		aDist(L[j], U[i], U[i-1]);	
	}else if(lastj != j){
		aDist(U[i], L[j], L[j+1]);
	}
	cout << ans << '\n';
	return 0;
}


