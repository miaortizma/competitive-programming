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

bool A[10];
bool B[10];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n, m, c;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> c;
		A[c] = true;
	}
	for(int i = 0; i < m; i++){
		cin >> c;
		B[c] = true;
	}
	for(int i = 1; i <= 9; i++){
		if(A[i] && B[i]){
			cout << i << '\n';
			return 0;
		}
	}
	int i = 0, j = 0;
	while(!A[i]) i++;
	while(!B[j]) j++;
	if(i < j){
		cout << i << j << '\n';
	}else{
		cout << j << i << '\n';
	}
	return 0;
}

