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

int arr[101];
	

int range(int i, int j){
	return arr[j] - arr[i-1];
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	arr[0] = 0;
	for(int i = 1; i <= n; i++) cin >> arr[i], arr[i] += arr[i-1];
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++ ){
			/*cout << i << ' ' << j << '\n';
			cout << "left: " << range(0, i - 1) << '\n';
			cout << "flip: " << j - i +1 - range(i, j) << '\n';
			cout << "right: " << range(j+1, n) << "\n\n";*/
			ans = max(ans, range(0,i-1) + (j - i + 1) - range(i, j) + range(j+1, n));
		}
	}
	cout << ans;
	return 0;
}

