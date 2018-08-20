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
int arr[] = {2,3,5,7};
//			 0,1,2,3,4,5,6,7,8,9
int bin[] = {0,0,1,2,0,4,3,8,1,0};
const int N = (1 << 4), MOD = (int) 1e9 + 7;
int mat[N][N], sol[N];
ll T, n;

int f(int x){
	int cur = 0;
	for(int j = 0; j < 4; j++){
		if((1<<j)&x){
			cur = cur ^ arr[j];
		}
	}
	return cur;
}

int idnt[N][N], rslt[N][N];

void mltp(int A[][N], int B[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ll temp = 0;
			for(int k = 0; k < N; k++){
				temp = (temp + A[i][k] * 1LL * B[k][j])%MOD;
			}
			rslt[i][j] = temp;
		}
	}
}

void print(int A[][N]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}

int matrix_expo(ll L){
	int A[N][N], B[N][N];
	memcpy(A, idnt, sizeof(A));
	memcpy(B, mat, sizeof(B));
	while(L){
		if(L&1){
			mltp(A, B);
			memcpy(A, rslt, sizeof(A));
		}
		L >>= 1;
		mltp(B, B);
		memcpy(B, rslt, sizeof(B));
	}
	ll ans = 0;
	//print(A);
	for(int i = 0; i < N; i++){
		if(f(i) || i == 13){
			for(int j = 0; j < N; j++){
				ans = (ans + sol[j]*1LL*A[j][i])%MOD;
			}
		}
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
	sol[0] = 3;
	sol[1] = 2;
	sol[2] = 1;
	sol[3] = 1;
	sol[4] = 1;
	sol[8] = 1;
	for(int i = 0; i < N; i++){
		idnt[i][i] = 1;
		for(int j = 1; j <= 9; j++){
			int y = i ^ bin[j];
			mat[i][y] += 1;
		}
	}
	cin >> T;
	while(T--){
		cin >> n;
		if(n == 1){
			cout << 6;
		}else{
			cout << matrix_expo(n - 1);
		}
		cout << '\n';
	}
	return 0;
}


