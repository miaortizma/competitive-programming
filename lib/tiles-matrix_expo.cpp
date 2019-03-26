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
const int N = (1 << 6), MOD = (int) 1e9 + 7;

struct Matrix{
	int rows, cols;
	vector<vector<int>> mat;
	Matrix(int n, int m): mat(n, vector<int>(m)), rows(n), cols(m) {}
	vector<int> operator[](int i){ return mat[i]; }
	Matrix operator*(const Matrix &other) const{
		int n = rows, m = other.cols;
		Matrix result(n, m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int k = 0; k < cols; k++){
					result.mat[i][j] = (result[i][j] + mat[i][k] * 1LL * other.mat[k][j] ) % MOD; 
				}
			}
		}
		return result;
	}
};

ll n, m, T;

typedef pair<int,int> pii;
vector< pii > tiles[7];
vector< int > starts[7];
vector< Matrix > vstarts;
vector< Matrix > matrices[7];

Matrix fast_exponentiation(int m, ll power){
		int n = 1 << m;
		Matrix result(n, n);
		for(int i = 0; i < n; i++){ 
			result.mat[i][i] = 1;
		}
		int i = 1;
		while(power){
			if(power&1){
				result = result * matrices[m][i - 1];
			}
			if(matrices[m].size() == i){
				matrices[m].push_back(matrices[m][i-1] * matrices[m][i-1]);
			}
			power >>= 1;
			i++;
		}
		return result;
}

void ctiles(int i, int a, int b){
	if(i > 0){
		if(a == 0){
			starts[i].push_back(b);
		}
		tiles[i].push_back(pii(a, b));
	}
	if(i == 6){
		return;
	} 
	ctiles(i+1, a, b);
	ctiles(i+1, a | (1 << i), b | (1 << i));
	if(i < 5) ctiles(i+2, a, (b | (1 << i | 1 <<(i+1))));
}

int main(){
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ctiles(0, 0, 0);
	for(int i = 0; i <= 6; i++){
		int sz = (1 << i);
		vstarts.push_back(Matrix(1, sz));
		matrices[i].push_back(Matrix(sz, sz));
		for(int j = 0; j < starts[i].size(); j++){
			vstarts[i].mat[0][starts[i][j]]++;
		}
		for(int j = 0; j < sz; j++){
			for(int k = 0; k < tiles[i].size(); k++){
				if( !(j & tiles[i][k].first) ){
					matrices[i][0].mat[j][tiles[i][k].second]++; 
				}
			}
		}
	}
	cin >> T;
	while(T--){
		cin >> m >> n;
		if(n == 1){
			cout << starts[m].size() << '\n';
		}else{
			Matrix result = vstarts[m] * fast_exponentiation(m, n-1);
			int ans = 0;
			for(int i = 0; i < (1 << m); i++){ ans = (ans + result[0][i]) % MOD; }
			cout << ans << '\n';
		}
	}
	return 0;
}


