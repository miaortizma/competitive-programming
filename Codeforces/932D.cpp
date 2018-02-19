#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll> v, ll W){
    int n = v.size();
    vector<ll>::iterator low = lower_bound(v.begin(), v.end(), W);
    /*cout << "Weights\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << "\nind";
    cout << *low << ' ' << low - v.begin() + 1;*/
    int pos = low - v.begin();
    if(pos == n) return n;
    if(*low > W){
        //cout << "<";
        if(low == v.begin()){
            return 0;
        }else{
            low--;
            return low - v.begin() + 1;
        }
    }else{
        //cout << "<<";
        return low - v.begin() + 1;
    }
    return 1;
}

int main(){
    int Q, ind = 0;
    cin >> Q;
    ll last = 0,t, p, q;
    vector< vector<ll> >node, weights;
    vector<ll> v0;
    // weight, index
    v0.push_back(0);
    weights.push_back(v0);
    node.push_back(v0);
    while(Q--){
        cin >> t >> p >> q;
        p = p^last;
        q = q^last;
        //cout << p << ' ' << q << '\n';
        p--;
        if(t == 1){
            vector<ll> v = node[p];
            vector<ll>::iterator low = v.begin();
            vector<ll> next, next1;
            ll w = q;
            /*cout << "Parent\n";
            for(int i = 0; i < v.size(); i++){
                cout << v[i] << ' ';
            }cout << '\n';*/
            next.push_back(q);
            next1.push_back(w);
            while(low != v.end()){
                low = lower_bound(v.begin(), v.end(), q);
                //cout << *low << '\n';
                if(low == v.end()) break;
                q = *low;
                w+=q;
                next.push_back(q);
                next1.push_back(w);
                low++;
            }
            node.push_back(next);
            weights.push_back(next1);
            /*cout << "\n----\n";
            for(int i = 0; i < next.size(); i++){
                cout << next[i] << ' ';
            }
            cout << '\n';
            for(int i = 0; i < next1.size(); i++){
                cout << next1[i] << ' ';
            }
            cout << "Good\n";*/
        }else{
            last = solve(weights[p], q);
            cout << last << '\n';
        }
        //cout << '\n';
    }
    return 0;
}
