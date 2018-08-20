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


ll T, N, K;
const int MOD = (int) 1e9 + 7;
string bans[50];
int ADJ[16][16], IDNT[16][16], RSLT[16][16];

string S;

void print(int X[][16]){
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			cout << X[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void st(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				ADJ[i+4*j][i*4+k] = 1;
			}
		}
	}
	for(int i = 0; i < 16; i++){
		IDNT[i][i] = 1;
	}
}

int id(char a, char b){
	return (a - 'a')*4 + (b - 'a');
}

void mltp(int A[][16], int B[][16]){
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			ll tmp = 0;
			for(int k = 0; k < 16; k++){
				tmp = (tmp + A[i][k] * 1LL * B[k][j]) % MOD;
			}
			RSLT[i][j] = tmp;
		}
	}
}

int matrix_expo(ll L){
	int A[16][16], B[16][16];
	memcpy(A, IDNT, sizeof(A));
	memcpy(B, ADJ, sizeof(B));
	for(int i = 0; i < K; i++){
		if(bans[i].size() == 3){
			int x = id(bans[i][0], bans[i][1]);
			int y = id(bans[i][1], bans[i][2]);
			B[x][y] = 0;
		}else if(bans[i].size() == 2){
			int x = id(bans[i][0], bans[i][1]);
			for(int j = 0; j < 16; j++){
				B[x][j] = 0;
				B[j][x] = 0;
			}
		}else if(bans[i].size() == 1){
			for(int j = 0; j < 4; j++){
				int x = id(bans[i][0], 'a' + j);
				int y = id('a' + j, bans[i][0]);
				for(int k = 0; k < 16; k++){
					B[x][k] = 0;
					B[k][x] = 0;
					B[y][k] = 0;
					B[k][y] = 0;
				}
			}
		}
	}
	while(L){
		if(L&1){
			mltp(A, B);
			memcpy(A, RSLT, sizeof(A));
		}
		mltp(B, B);
		memcpy(B, RSLT, sizeof(B));
		L >>= 1;
	}
	int ret = 0;
	for(int i = 0; i < 16; i++){
		for(int j = 0; j < 16; j++){
			ret = (ret + A[i][j]) % MOD;
		}
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
	cin >> T;
	st();
	while(T--){
		cin >> N >> K;
		for(int i = 0; i < K; i++){
			cin >> bans[i];
		}
		if(N == 0){
			cout << 0;
		}else if(N == 1){
			int arr[4];
			for(int i = 0; i < 4; i++) arr[i] = 1;
			for(int i = 0; i < K; i++){
				if(bans[i].size() == 1){
					arr[bans[i][0] - 'a'] = 0;
				}
			}
			int ans = 0;
			for(int i = 0; i < 4; i++){
				ans += arr[i];
			}
			cout << ans;
		}else if(N == 2){
			int arr[16];
			for(int i = 0; i < 16; i++){
				arr[i] = 1;
			}
			for(int i = 0; i < K; i++){	
				if(bans[i].size() == 2){
					arr[id(bans[i][0], bans[i][1])]	= 0;
				}else if(bans[i].size() == 1){
					for(int j = 0; j < 4; j++){
						int x = id(bans[i][0], 'a' + j);
						int y = id('a' + j, bans[i][0]);
						arr[x] = 0;
						arr[y] = 0;
					}
				}
			}
			int ans = 0;
			for(int i = 0; i < 16; i++){
				ans += arr[i];
			}
			cout << ans;
		}else{
			cout << matrix_expo(N - 2);
		}
		cout << '\n';
	}
	return 0;
}


