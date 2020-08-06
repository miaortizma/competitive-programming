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

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int cnt = 1;
	for(int i = n - 1; cnt > 0 && i > 0; i--){
		cnt = 0;
		for(int j = 0; j < i; j++){
			if(arr[j] > arr[j+1]){	
				swap(arr[j], arr[j+1]);
				cout << (j+1) << ' ' << (j+2) << '\n';
				cnt++;
			}
		}	
	}
	return 0;
}


