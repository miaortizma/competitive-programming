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

char other(char a, char b){
	char arr[] = {'a', 'b', 'c'};
	for(int i = 0; i < 3; i++){
		if(arr[i] != a && arr[i] != b){
			return arr[i];
		}  
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, t;
	cin >> n >> t;
	string a, b;
	cin >> a >> b;
	int c, d;
	vector<int> posa, posb;
	char ans[n];
	for(int i = 0; i < n; i++){
		if(a[i] == b[i]){
			posa.push_back(i);
		}else{
			posb.push_back(i);
		}
	}
	if(t < (posb.size() + 2 - 1)/2){
		cout << -1;
	}else{
		if(posb.size()%2 == 1){
			int p = posb[0];
			ans[p] = other(a[p], b[p]);	
			t--;
		}
		int i = posb.size()%2;
		//cout << t << '\n';
		while(i < posb.size()){
			int p = posb[i];
			if(i%2 == 0){
				ans[p] = a[p];
				t--;
			}else{
				ans[p] = b[p];
			}
			i++;
		}
		i = posb.size()%2;
		while(i < posb.size() && t > 0){
			int p = posb[i];
			int k = posb[i+1]; 
			ans[p] = other(a[p], b[p]);
			ans[k] = other(a[k], b[k]);
			t--;
			i+=2;
		}
		i = 0;
		while(i < posa.size() && t > 0){
			int p = posa[i];
			ans[p] = other(a[p], b[p]);
			t--;
			i++;
		}
		while(i < posa.size()){
			int p = posa[i];
			ans[p] = a[p];
			i++;
		}
		for(int i = 0; i < n; i++){
			cout << ans[i];
		}
		cout << '\n';
	}
	return 0;
}


