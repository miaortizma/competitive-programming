#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string str;
	cin >> str;
	char tmp = 0;
	int t = 0;
	bool dangerous = false;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == tmp){
			t++;
		}else{
			tmp = str[i];
			t = 1;
		}
		if(t == 7){
			dangerous = true;
			break;
		}
	}
	if(dangerous){
		cout << "YES";
	}else {
		cout << "NO";
	}
	return 0;
}


