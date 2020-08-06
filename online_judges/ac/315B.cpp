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

const int NMAX = (int) 1e5;
int arr[NMAX+5], update[NMAX+5], sum[NMAX+5];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> arr[i];
	for(int i = 1; i <= m; i++){
		int q;
		cin >> q;
		if(i > 0) sum[i] += sum[i - 1];
		switch(q){
			case 1:{
				int v, x;
				cin >> v >> x;
				arr[v] = x;
				update[v] = i;
				break;
			}
			case 2:{
				int y;
				cin >> y;
				sum[i] += y;
				break;
			}
			case 3:{
				int qx;
				cin >> qx;
				cout << arr[qx] + sum[i] - sum[update[qx]]<< '\n';
				break;
			}
		}
	}
	return 0;
}


