#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <string>
#include <cmath>

using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int A[n][m];
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char tmp;
			cin >> tmp;
			if(tmp == 'X'){
				count++;
			}
		}
	}
	if(count == 1 || (count%2 == 0 && (n%2 == 0  || m%2 == 0) ) ){
		cout << "YES";
	}else{
		cout << "NO";
	}
	return 0;
}
