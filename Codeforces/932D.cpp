#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> v, ll W){
    cout << "Hello\n";
    int n = v.size();
    vector<ll>::iterator low = lower_bound(v.begin(), v.end(), W);
    if(*low > W){
        if(low == v.begin()){
            return 0;
        }else{
            low--;
            return low - v.begin();
        }
    }else{
        return low - v.begin();
    }
    return 1;
}

int main(){
    int Q, ind = 0;
    cin >> Q;
    ll last = 0, i, p, q;
    vector< vector<ll> >node, weights;
    vector<ll> v0;
    // weight, index
    v0.push_back(0);
    weights.push_back(v0);
    node.push_back(v0);
    while(Q--){
        cin >> i >> p >> q;
        p = p^last;
        q = q^last;
        p--;
        if(i == 1){
            vector<ll> v = node[p];
            vector<ll>::iterator low = v.begin();
            vector<ll> next, next1;
            next.push_back(q);
            ll w = q;
            while(low != v.end()){
                low = lower_bound(v.begin(), v.end(), q);
                q = *low;
                w+=q;
                next.push_back(q);
                next1.push_back(w);
            }
            node.push_back(next);
            weights.push_back(next1);
            cout << "Good\n";
        }else{
            last = solve(weights[p], q);
            cout << last << '\n';
        }
    }
    return 0;
}
