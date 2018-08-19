#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <string>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	unsigned long long n, m, a;
	cin >> n >> m >> a;
	//tle
	/*for(int i = 0; i < n; i+=a){
		for(int j = 0; j < m; j+=a){
			s++;
		}
	}*/
	unsigned long long s = ((n + a - 1)/a)*((m + a - 1)/a);
	cout << s;
    return 0;
}
