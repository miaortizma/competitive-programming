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

const int NMAX = (int)1e5; 
typedef pair<int,int> pii;
int minPrime[NMAX+1];
vector<pii> pfactors[NMAX+1];
vector<int> divisors[NMAX+1];
bool calc[NMAX+1];

void sieve(int n){
	for (int i = 2; i * i <= n; ++i) {
    	if (minPrime[i] == 0) {         //If i is prime
        	for (int j = i * i; j <= n; j += i) {
            	if (minPrime[j] == 0) {
                	minPrime[j] = i;
            	}
        	}
    	}
	}
	for (int i = 3; i <= n; i+=2) {
    	if (minPrime[i] == 0) {
        	minPrime[i] = i;
    	}
	}
}

void factorize(int n){
	int N = n;
	vector<pii> res;
	while (n != 1) {
    	int prime = minPrime[n];
    	int expo = 0;
    	while(n%prime == 0){
    		expo++;
    		n /= prime;
		}
        res.push_back(pii(prime, expo));
    }
    pfactors[N] = res;
}

void print(string name, vector<int> arr){
	cout << name << '\n';
	for(int i = 0; i < arr.size(); i++){
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void setDivisors(int n, int i, int N) {
    int j, x, k;
    vector<pii> factors = pfactors[N];
    for (j = i; j<factors.size(); j++) {
        x = factors[j].first * n;
        for (k = 0; k<factors[j].second; k++) {
            divisors[N].push_back(x);
            setDivisors(x, j + 1, N);
            x *= factors[j].first;
        }
    }
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);
	#ifdef PAPITAS
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	int n;
	cin >> n;
	sieve(NMAX);
	factorize(100);
	while(n--){
		int arr[3];
		for(int i = 0; i < 3; i++){
			cin >> arr[i];
			if(!calc[arr[i]]){
				factorize(arr[i]);
				divisors[arr[i]].push_back(1);
				setDivisors(1, 0, arr[i]);
				sort(divisors[arr[i]].begin(), divisors[arr[i]].end());
				calc[arr[i]] = true;
			}
		}
		sort(arr, arr + 3);
		vector<int> div1 = divisors[arr[0]], div2 = divisors[arr[1]], div3 = divisors[arr[2]];
		int i = 0, j = 0, k = 0;
		ll ans = 0;
		for(;i < div1.size(); i++){
			while(j < div2.size() && div2[j] < div1[i]){
				j++;
			}
			for(ll J = j; J < div2.size(); J++){	
				ans += (div3.size()*1LL) - J;
			}
		}
		cout << ans << '\n';
		
	}
	return 0;
}


