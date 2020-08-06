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
	int arr[n+1];
	for(int i = 1; i <= n; i++) cin >> arr[i];
	arr[0] = 0;
	int i;
	for(i = 1; i <= n; i++){
		if(arr[i] > arr[i-1] + 15){
			break;
		}
	}
	cout << min(arr[i-1] + 15, 90);
	
	return 0;
}


