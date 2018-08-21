#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	cout << fixed << showpoint;
	cout << setprecision(3);
	int mat[5][5];
	int x,y;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 1){
				x = i + 1;
				y = j + 1;	
			}
		}
	}
	cout << abs(3 - x) + abs(3 - y);
	return 0;
}


