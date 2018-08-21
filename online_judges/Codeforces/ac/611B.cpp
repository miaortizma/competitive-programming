#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll todec(string bin){
	ll dec = 0;
	for(int i = bin.size() - 1; i >= 0; i--){
		//cout << (bin.size() - 1 - i ) << '\n';
		if(bin[i] == '1'){
			dec += (1LL<<(bin.size() - 1 - i ));
		}
	}
	return dec;
}

int main(){
	string s;
	ll a, b;
	cin >>  a >> b;
	string str = "";
	int ans = 0;
	for(int i = 1; i <= 63; i++){
		str += "1";
		for(int j = 1; j < i; j++){
			string cop = str;
			cop[j] = '0';
			ll dec = todec(cop);
			//cout << cop << ' ' << dec <<'\n';
			if(a <= dec && dec <= b){
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
