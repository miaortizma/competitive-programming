#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	string home;
	cin >> home;
	int dep = 0, arr = 0;
	while(n--){
		string fl;
		cin >> fl;
		int i;
		for(i = 0; i < 3; i++){
			if(home[i] != fl[i]){
				break;
			}
		}
		if(i == 3){
			dep++;
		}else{
			arr++;
		}
	}
	if(dep == arr){
		cout << "home";
	}else{
		cout << "contest";
	}
	return 0;
}


