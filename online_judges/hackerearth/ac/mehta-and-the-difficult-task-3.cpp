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

const int N = (1 << 4) , MOD = (int) 1e9 + 7;
int mat[N][N], rslt[N][N], idnt[N][N], sol[N];
ll T, t, n;

int bits(int x){
	return __builtin_popcount(x);
}

void print(int X[][N], char s){
	cout <<s<< '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << X[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void bin(int x){
	for(int i = 3; i >= 0; i--){
		cout << (((1 << i) & x) >> i);
	}
}

void multp(int A[][N], int B[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ll tmp = 0;
			for(int k = 0; k < N; k++){
				tmp = (tmp + A[i][k] * 1LL * B[k][j])%MOD; 
			}
			rslt[i][j] = tmp;
		}
	}
}

int matrix_expo(ll L, int x){
	int A[N][N], B[N][N];
	memcpy(A, idnt, sizeof(A));
	memcpy(B, mat, sizeof(B));
	while(L){
		if(L&1){
			multp(A, B);
			memcpy(A, rslt, sizeof(A));
		}
		L >>= 1;
		multp(B, B);
		memcpy(B, rslt, sizeof(B));
	}
	//print(A, 'A');
	int ans = 0;
	for(int i = 0; i < N; i++){
		ans = (ans + sol[i] * 1LL * A[i][x])%MOD;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	sol[0] = 6;
	sol[1] = 1;
	sol[2] = 1;
	sol[4] = 1;
	sol[8] = 1;
	for(int i = 0; i < N; i++){
		idnt[i][i] = 1;
		mat[i][i] = 6;
		for(int j = 0; j < N; j++){
			if(abs(bits(i) - bits(j)) == 1 && ( (i|j) == j)){
				mat[i][j] = 1;
				mat[j][i] = 1;
			}
		}
	}
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		int x = 0;
		for(int i = 3; i >= 0; i--){
			cin >> t;
			if(t){
				x += (1<<i);	
			}
		}
		if(n == 1){
			cout << sol[x];
		}else{
			cout << matrix_expo(n - 1, x);	
		}
		cout << '\n';
	}
	return 0;
}


