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
	
int arr[3][2];

bool find(int i, int n, int m, int a, int b){
	if(i == 3){
		return true;
	}else{	
		bool f = false;
		if(n - a - arr[i][0] >= 0 && m - arr[i][1] >= 0){
			//cout << i <<"<\n";
			//cout << arr[i][0] << ' ' << arr[i][1] << '\n';
			f = f || find(i+1, n, m, arr[i][0], arr[i][1]);
		}
		if(n - a - arr[i][1] >= 0 && m - arr[i][0] >= 0){
			//cout << i << "<2\n";
			//cout << arr[i][1] << ' ' <<  arr[i][0] << '\n';
			f = f || find(i+1, n, m, arr[i][1], arr[i][0]);
		}
		if(m - b - arr[i][0] >= 0 && n - arr[i][1] >= 0){
			//cout << i << "<3\n";
			//cout << n << '\n';
			//cout << arr[i][0] << ' ' << arr[i][1] << '\n';
			f = f || find(i+1, n, m, arr[i][1], arr[i][0]);
		}
		if(m - b - arr[i][1] >= 0 && n - arr[i][0] >= 0){
			//cout << i << "<4\n";
			//cout << arr[i][1] << ' ' <<  arr[i][0] << '\n';
			f = f || find(i+1, n, m, arr[i][0], arr[i][1]);
		}
		return f;
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	for(int i = 0; i < 3; i++) cin >> arr[i][0] >> arr[i][1];
	if(find(1, arr[0][0], arr[0][1], 0, 0)){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}

