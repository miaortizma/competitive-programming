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


int mat[110][110];
int type, row, col, val, n, m, Q;

struct query{
	int type, row, col, val;
	
};

query queries[10010];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> n >> m >> Q;
	for(int i = 0; i < Q; i++){
		cin >> type;
		query q;
		q.type = type;
		switch(type){
			case 3:{
				cin >> row >> col >> val;
				q.row = row - 1;
				q.col = col - 1;	
				q.val = val;
				break;
			}
			case 2:{
				cin >> col;
				q.col = col - 1;	
				break;
			}
			case 1:{
				cin >> row;
				q.row = row - 1;
				break;
			}
		}
		queries[i] = q;
	}
	for(int i = Q - 1; i >= 0; i--){
		query q = queries[i];
		type = q.type;
		row = q.row;
		col = q.col;
		val = q.val;
		switch(type){
			case 1:{
				int temp = mat[row][m - 1];
				for(int i = m - 1; i > 0; i--){
					mat[row][i] = mat[row][i-1];
				}
				mat[row][0] = temp;
				break;
			}
			case 2:{
				int temp = mat[n - 1][col];
				for(int i = n - 1; i > 0; i--){
					mat[i][col] = mat[i-1][col];
				}
				mat[0][col] = temp;
				break;
			}
			case 3:{
				mat[row][col] = val;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

 
