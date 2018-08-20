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
typedef pair<int,int> pii;

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
	vector<int> sgm;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int cur = 0;
	sgm.push_back(0);
	for(int i = 1; i < n; i++){
		if(arr[i] <= arr[i-1]){
			sgm.push_back(i);
		}
	}
	sgm.push_back(n);
	int ans = 0;
	for(int i = 1; i < sgm.size(); i++){
		ans = max(ans, sgm[i] - sgm[i-1]);
		//expand the segment to the left or to the right..
		if(sgm[i] < n || sgm[i-1] - 1 >= 0){
			ans = max(ans, sgm[i] - sgm[i-1] + 1);
		}
		//change the element that breaks the segment or change the element that is before the one that breaks the segment
		if(sgm[i]+1 < n && ( (arr[sgm[i] + 1] > arr[sgm[i] - 1] + 1) || ( sgm[i] - 2 >= 0 && arr[sgm[i]] > arr[sgm[i] - 2] + 1) )){
			ans = max(ans, sgm[i+1] - sgm[i-1]);	
		}
	}s
	cout << ans;
	return 0;
}


