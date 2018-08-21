#include<bits/stdc++.h>
#define ll long long
using namespace std;

void print(vector<ll> v){
    for(int i = 0; i < v.size(); i++) cout << v[i] << ' ';
    cout << '\n';
}

ll solve(vector<ll> v, ll W){
    int n = v.size();
    vector<ll>::iterator up = upper_bound(v.begin(), v.end(), W);
    //print(v);
    //cout <<"up:" <<*up<<'\n';
    if(up == v.begin()) return 0;
    if(up == v.end()) return n;
    return up - v.begin();
}

int main(){
    int Q, ind = 0;
    cin >> Q;
    ll last = 0,t, p, q;
    vector< vector<ll> >node, weights;
    vector<ll> v0;
    v0.push_back(0);
    weights.push_back(v0);
    node.push_back(v0);
    while(Q--){
        //cout <<"\nQ::"<<  Q << '\n';
        cin >> t >> p >> q;
        p = p^last;
        q = q^last;
        //cout << "p\tq\n";
        p--;
        //cout << p << '\t' << q << '\n';
        if(t == 1){
            vector<ll> v = node[p];
            vector<ll> next, next1;
            ll w = q;
            vector<ll>::iterator low = lower_bound(v.begin(), v.end(), w);
            //cout <<"low: " <<  *low << '\n';
            //cout <<"q: " << w << '\n';
            next.push_back(q);
            next1.push_back(w);
            while(low != v.end()){
                q = *low;
                w += q;
                low++;
                next.push_back(q);
                next1.push_back(w);
            }
            node.push_back(next);
            weights.push_back(next1);

            int n = node[node.size() - 1].size();
            int a = node.size();
            //cout << "Node values:\n";
            //print(node[a-1]);
            //cout << "\nWeight values added:\n";
            //print(weights[a-1]);

        }else{
            last = solve(weights[p], q);
            //cout << "last:\n";
            cout << last << '\n';
        }
    }
    return 0;
}
