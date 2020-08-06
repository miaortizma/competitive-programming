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

int n;
bool use[256];
char mat[2048+10][2048+10];

bool valid(int x, int y){
	return 0 <= x && x < n && 0 <= y && y < n;
}

void check(int r, int c){
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	for(int i = 0; i < 4; i++){
		int x = r + dx[i];
		int y = c + dy[i];
		if(valid(x, y)){
			use[mat[x][y]] = true;
		}
	}
}

bool in(int r, int c, int x, int y, int p, int q){
	return x <= r && r < p && y <= c && c < q;
}

void solve(int r, int c, int x, int y, int p, int q){
	int sz = (p - x)/2;
	int dx[] = {x, x, p - sz, p - sz};
	int dy[] = {y, q - sz, y, q - sz};
	int dp[] = {p - sz, p - sz, p, p};
	int dq[] = {q - sz, q, q - sz, q};
	
	int dr[] = {p - sz - 1, p - sz - 1, p - sz, p - sz};
	int dc[] = {q - sz - 1, q - sz, q - sz - 1, q - sz};
	
	memset(use, false, sizeof(use));
	
	//check surroundings of the 3 that will be placed
	for(int i = 0; i < 4; i++){
		if(!in(r, c, dx[i], dy[i], dp[i], dq[i])){
			check(dr[i], dc[i]);			
		}
	}
	//get first letter that can be used
	char A;
	for(int i = 'A'; i <= 'Z'; i++){
		if(!use[i]){
			A = (char) i;
			break;
		}
	}
	//place letter
	for(int i = 0; i < 4; i++){
		if(!in(r, c, dx[i], dy[i], dp[i], dq[i])){
			mat[dr[i]][dc[i]] = A;
		}
	}
	if(p - x != 2 && q - y != 2){
		//divide
		for(int i = 0; i < 4; i++){
			if(in(r, c, dx[i], dy[i], dp[i], dq[i])){
				solve(r, c, dx[i], dy[i], dp[i], dq[i]);
			}else{
				solve(dr[i], dc[i], dx[i], dy[i], dp[i], dq[i]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int r, c;
	cin >> n >> r >> c;
	r--;
	c--;
	mat[r][c] = '.';
	if(n != 1){
		solve(r, c, 0, 0, n, n);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << mat[i][j];
		}
		cout << '\n';
	}
	return 0;
}


