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

int n;

int search(int last, int left[], int k, string state){
	if(k == 3*n) {
		return 1;	
	}
	/*stringstream ss;
	string a;
	ss << last;
	ss >> a;*/
	//state +=  a;
	left[last]--;
	/*cout << k << '\n';
	cout << state << '\n';*/
	int ans = 0;
	for(int i = 1; i <= 3; i++){
		if(left[i] > 0 && i != last){
			ans += search(i, left, k+1, state);
		}
	}
	left[last]+=1;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int ans[] = {6, 30, 174, 1092, 7188, 48852, 339720, 2403588, 17236524, 124948668};
	cin >> n;
	/*int left[4];
	for(int i = 1; i <= 3; i++){
		left[i] = n;
	}
	ll ans = search(1, left, 1, "");*/
	cout << ans[n-1]<< '\n';
	return 0;
}



