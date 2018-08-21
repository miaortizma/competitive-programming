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

bool impar[50][50];
int ans[50][50];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	for(int i = 0; i <= n/2; i++){
		for(int j = 0; j <= i; j++){
			impar[i][n/2+j] = true;
			impar[i][n/2-j] = true;
			impar[n - 1 - i][n/2+j] = true;
			impar[n - 1 - i][n/2-j] = true;
		}
	}
	int p = 1, q = 2;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(impar[i][j]){
				cout << p << '\t';
				p+=2;
			}else{
				cout << q << '\t';
				q+=2;
			}
		}
		cout << '\n';
	}	
	return 0;
}


