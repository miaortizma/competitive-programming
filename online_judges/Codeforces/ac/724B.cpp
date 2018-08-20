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

int n, m;
int arr[25][25], cpy[25][25];

void _set(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			arr[i][j] = cpy[i][j];
		}
	}
}

bool check(int arr[]){
	int c = 0;
	for(int i = 0; i < m; i++){
		if(arr[i] != (i+1)){
			for(int j = i+1; j < m; j++){
				if(arr[j] == (i+1)){
					swap(arr[i], arr[j]);
					break;
				}
			}
			c++;
		}
	}
	return c <= 1;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
			cpy[i][j] = arr[i][j];
		}
	}
	for(int l = 0; l < m; l++){
		for(int r = l; r < m; r++){
			_set();
			int i;
			for(i = 0; i < n; i++){
				swap(arr[i][l], arr[i][r]);	
				if(!check(arr[i])){
					break;
				}
			}
			if(i == n){
				cout << "YES";
				exit(0);
			}
		}
	}
	cout << "NO";
	return 0;
}


