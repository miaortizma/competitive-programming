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

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int ways[8][3];
	int j = 0;
	ways[j][0] = 0;
	ways[j][1] = 4;
	ways[j++][2] = 8;
	ways[j][0] = 2;
	ways[j][1] = 4;
	ways[j++][2] = 6;
	for(int i = 0; i < 3; i++){
		ways[j][0] = i*3;
		ways[j][1] = i*3 + 1;
		ways[j++][2] = i*3 + 2;
		ways[j][0] = i;
		ways[j][1] = 3 + i;
		ways[j++][2] = 6 + i;
	}
	string arr[3];
	int x = 0, o = 0;
	for(int i = 0; i < 3; i++){
		cin >> arr[i];
		for(int j = 0; j < 3; j++){
			if(arr[i][j] == 'X'){
				x++;
			}else if(arr[i][j] == '0'){
				o++;
			}
		}
	}
	int X = 0, O = 0;
	for(int i = 0; i < 8; i++){
		if(arr[ways[i][0]/3][ways[i][0]%3] == arr[ways[i][1]/3][ways[i][1]%3] && arr[ways[i][0]/3][ways[i][0]%3] == arr[ways[i][2]/3][ways[i][2]%3]){
			if(arr[ways[i][0]/3][ways[i][0]%3] == 'X'){
				X++;
			}else if(arr[ways[i][0]/3][ways[i][0]%3] == '0'){
				O++;
			}
		}
	}
	if( (X && O) || (x != o + 1 && x != o) || (O && X == 0  && x > o) || (X && O == 0 && x == o)){
		cout << "illegal";
	}else if(X){
		cout << "the first player won";
	}else if(O){
		cout << "the second player won";
	}else if(x + o == 9){
		cout << "draw";
	}else if(x > o){
		cout << "second";
	}else{
	    cout << "first";
	}
	return 0;
}
