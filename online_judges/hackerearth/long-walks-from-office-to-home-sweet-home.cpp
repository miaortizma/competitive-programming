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

const int MOD = (int)1e9+7;
ll T, N, K, U, V;

int ADJ[50][50], RSLT[50][50], IDNT[50][50];

void mltp(int A[][50], int B[][50]){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			ll tmp = 0;
			for(int k = 0; k < N; k++){
				tmp = (tmp + A[i][k] * 1LL * B[k][j])%MOD;
			}
			RSLT[i][j] = tmp;
		}
	}
}

int matrix_expo(){
	int A[50][50];
	memcpy(A, IDNT, sizeof(A));
	while(K){
		if(K&1){
			mltp(A, ADJ);
			memcpy(A, RSLT, sizeof(A));
		}
		mltp(ADJ, ADJ);
		memcpy(ADJ, RSLT, sizeof(ADJ));
		K >>= 1;
	}
	/*
	cout << U << ' ' << V << '\n';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << A[i][j] << ' ';
		}cout << '\n';
	}
	*/
	return A[U][V];
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> T;
	for(int i = 0; i < 50; i++){
		IDNT[i][i] = 1;
	}
	while(T--){
		cin >> N >> K >> U >> V;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				cin >> ADJ[i][j];
			}
		}
		if(K == 0){
			cout << 0;
		}else if(K == 1){
			cout << ADJ[U][V];
		}else{
			cout << matrix_expo();	
		}
		cout << '\n';
	}
	return 0;
}


