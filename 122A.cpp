#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	int n;
	cin >> n;
	bool almost = false;
	int lucky[] = {4,7,44,47,74,77,444,447,474,477,777};
	for(int i = 0; i < 11; i++ ){
		if(n%lucky[i] == 0){
			almost = true;
		}
	}
	if(almost){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}


