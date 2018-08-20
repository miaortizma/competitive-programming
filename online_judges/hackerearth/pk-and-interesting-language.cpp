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

const int MOD = (int)1e9 + 7;
const int N = 26;
int MAT[N][N];
int IDNT[N][N];
int RSLT[N][N];

int sum(int a, int b){
	return (a+b)%MOD;
}

void multp(int A[][N], int B[][N] ){
	memset(RSLT, 0, sizeof(RSLT));
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				RSLT[i][j] = (RSLT[i][j] + A[i][k] * 1LL *B[k][j])%MOD; 
			}
		}
	}
}

int matrix_expo(int L, int c){
	int A[N][N], B[N][N];
	memcpy(A, IDNT, sizeof(A));
	memcpy(B, MAT, sizeof(B));
	while(L){
		if(L&1){
			multp(A, B);
			memcpy(A, RSLT, sizeof(A));
		}
		multp(B, B);
		memcpy(B, RSLT, sizeof(B));
		L >>= 1;
	}
	int ret = 0;
	for(int i = 0; i < N; i++){
		ret = sum(ret, A[i][c-'a']);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	for(int i = 0; i < N; i++){
		IDNT[i][i] = 1;
		for(int j = 0; j < N; j++){
			cin >> MAT[i][j];
		}
	}
	int T;
	cin >> T;
	while(T--){
		char c;
		int L;
		cin >> c >> L;
		cout << matrix_expo(L - 1, c) << '\n';
	}
	return 0;
}


