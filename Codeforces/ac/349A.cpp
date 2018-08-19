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

int coin[101];

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n, val;
	cin >> n;
	bool ok = true;
	for(int i = 0; i < n; i++){
		cin >> val;
		switch(val){
			case 100:{
				if(coin[50] != 0 && coin[25] != 0){
					coin[50]--;
					coin[25]--;
					coin[100]++;
				}else if(coin[25] >= 3){
					coin[25] -= 3;
					coin[100]++;
				}else{
					ok = false;
				}
				break;
			}
			case 50:{
				if(coin[25] == 0){
					ok = false;
				}else{
					coin[25]--;
					coin[50]++;	
				}
				break;
			}
			case 25:{
				coin[25]++;
				break;
			}
		}
	}
	if(ok){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}

