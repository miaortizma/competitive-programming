#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define pb push_back
#define x(t) get<0>(t)
#define y(t) get<1>(t)
#define c(t) get<2>(t)
#ifdef PAPITAS
	#define DEBUG 1
#else
	#define DEBUG 0
#endif
#define _DO_(x) if(DEBUG) x


typedef tuple<ll,ll,ll> data;
typedef tuple<ll,ll> sol;

int gcd(ll a, ll b){
	while(a % b != 0){
		ll t = a;
		a = b;
		b = t%b;
	}
	return b;
}

sol f(data A){
	ll a = x(A), b = y(A);
	ll c = gcd(a, b);
	return sol((y(A)- x(A))/c, y(A)/c); 
}

sol mul(sol A, sol B){
	ll a = x(A)*x(B), b = y(A)*y(B);
	ll c = gcd(a, b);
	return sol(a/c, b/c);
}

sol best(sol A, sol B){
	double a = x(A)/double(y(A)), b = x(B)/double(y(B));
	if( a > b ){
		return A; 
	}else{
		return B;
	}
}


void print(data A){
	cout << "data: \n";
	cout << x(A) << ',' << y(A) << ',' << c(A) << endl;
}

void print(sol A){
	cout << x(A) << ',' << y(A) <<  ' ';
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ll n, K;
	int T = 1;
	while(cin >> n >> K){
		if(n == 0) break;
		int m[n+1];
		ll a, b, c;
		vector<data> datas[n+1];
		for(int i = 1; i <= n; i++) cin >> m[i];
		for(int i = 1; i <= n; i++){
			datas[i] = vector<data> (m[i]+1);
			for(int j = 1; j <= m[i]; j++){
				cin >> a >> b >> c;
				datas[i][j] = data(a, b, c);
			}
		}
		sol dp[n+1][1010];
		for(int i = 0; i <= K; i++) dp[0][i] = sol(1,1);
		//cout << T++ << ' ' << n << ' ' << K << endl;
		for(int i = 1; i <= n; i++){
			int k;
			for(k = 0; k < c(datas[i][1]); k++){
				dp[i][k] = sol(0,1);
			} 
			for(int j = 1; j <= m[i]; j++){
				for(k = c(datas[i][j]); k <= K; k++){
					sol A = dp[i][k-1];
					sol B = mul(dp[i-1][k-c(datas[i][j])], f(datas[i][j]));
					sol C = best(A,B);
					dp[i][k] = best(dp[i][k],C);
				}
			}
		}
		
		/*for(int j = 1; j  <= K; j++){
			cout << j << ' ';
			for(int i = 1; i <= n; i++){
				print(dp[i][j]);
			}
			cout << endl;
		}*/
			
				
		sol ans = dp[n][K];
		a = y(ans) - x(ans), b = y(ans);
		c = gcd(a,b);
		cout << a/c << "/" << b/c << '\n';
	}
	return 0;
}

