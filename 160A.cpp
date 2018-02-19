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
	int arr[n];
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + n);
	int count = 0, i = 0;
	while(count < sum - count ){
		//cout << ">" << i << '\n';
		count+=arr[i];
		i++;
	}
	cout << n - i + 1 << '\n';
	return 0;
}


