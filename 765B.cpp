#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string ob;
	char st = 'a' - 1;
	cin >> ob;
	int i;
	for( i = 0; i < ob.size(); i++){
		if(ob[i] == char(st + 1)) {
			st++;
		}else if (ob[i] > st){
			break;
		}
	}
	if(i == ob.size()){
		cout << "YES";
	}else{
		cout << "NO";
	}
	
	return 0;
}


