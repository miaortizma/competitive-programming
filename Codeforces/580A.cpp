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
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int ans, cur;
    ans = cur = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            cur = 1;
        }else{
            cur++;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
    return 0;
}
