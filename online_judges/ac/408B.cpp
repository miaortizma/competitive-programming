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

int A[256], B[256];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	string a, b;
	cin >> a >> b;
	for(int i = 0; i < a.size(); i++){
		A[a[i]]++;
	}
	for(int i = 0; i < b.size(); i++){
		B[b[i]]++;
	}
	bool posb = true;
	int ans = 0;
	for(int i = 'a'; i <= 'z'; i++){
		if(B[i] > 0){
			if(A[i] == 0){
				posb = false;
				break;
			}else{
				ans+= min(A[i],B[i]);
			}
		}
	}
	if(posb == false){
		ans = -1;
	}
	cout << ans << '\n';
	return 0;
}


