<<<<<<< HEAD:Codeforces/ac/876C.cpp
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

int sum(int n){
	int ans = 0;
	while(n > 0){
		ans += n%10;
		n /=10;
	}
	return ans;
}

vector<int> solve(int n){
	int b = n, k = 0;
	while(b>0){
		b/=10;
		k++;
	}
	vector<int> ans;
	for(int i = max(1,n - 9*k); i < n; i++){
		if(sum(i) + i == n){
			ans.push_back(i);
		}
	}
	
	return ans;
}


int main()
{
	#ifdef PAPITAS
		//freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
//	unordered_map<int,vector<int>> freq;
//	for(int i = 1; i < 10000000; i++){
//		freq[sum(i) + i].push_back(i);
//	}
//	for(auto x : freq){
//		vector<int> ans;
//		if(	(ans = solve(x.first)).size() < x.second.size()){
//			cout << "Found \n";
//			cout << x.first << '\n';
//			cout << x.second.size() << '\n';
//			for(auto y : x.second){
//				cout << y << ' ';
//			}cout << '\n';
		
//		}
//	}
	vector<int> ans = solve(n);
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << '\n'; 
	}
	return 0;
}

=======
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

int sum(int n){
	int ans = 0;
	while(n > 0){
		ans += n%10;
		n /=10;
	}
	return ans;
}

vector<int> solve(int n){
	int b = n, k = 0;
	while(b>0){
		b/=10;
		k++;
	}
	cout << k << '\n';
	vector<int> ans;
	for(int i = max(1,n - 9*k); i < n; i++){
		if(sum(i) + i == n){
			ans.push_back(i);
		}
	}

	return ans;
}


int main()
{
	#ifdef PAPITAS
		//freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> ans = solve(n);
	cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++){
			cout << ans[i] << '\n';
	}
	return 0;
}
>>>>>>> refs/remotes/origin/master:Codeforces/876C.cpp
