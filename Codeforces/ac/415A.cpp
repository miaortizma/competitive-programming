#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    n = min(n, m);
    if(n%2 == 0){
    	cout << "Malvika";
	}else{
		cout << "Akshat";
	}

    return 0;
}
