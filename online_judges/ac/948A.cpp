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
	int r, c;
	cin >> r >> c;
	string arr[r];
	for(int i = 0; i < r; i++){
		cin >> arr[i];
	}
	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,-1,1};
	bool posb = true;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(arr[i][j] == 'S'){
				for(int k = 0; k < 4; k++){
					if(0 <= i + dx[k] && i + dx[k] < r && 0 <= j + dy[k] && j + dy[k] < c){
						char oth = arr[i+dx[k]][j+dy[k]];
						if(oth == 'W'){
							posb  = false;
							break;
						}else if(oth != 'S'){
							arr[i+dx[k]][j+dy[k]] = 'D';
						}
					}
				}
			}
		}
	}
	if(posb){
		cout << "Yes\n";
		for(int i = 0; i < r; i++){
			cout << arr[i] << '\n';
		}
	}else{
		cout << "No";
	}
	return 0;
}


