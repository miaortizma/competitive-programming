#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
vector<pii> vec1;

const int N = 100100;
set < int > v [N];
set < int > id[N];

int main(){
    #ifdef LOCAL
        freopen("in2.txt", "r", stdin);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);
    for( int i = 0; i<n; i++ ){
        int t;
        scanf("%d", &t);
        for( int j = 0; j<t; j++ ){
            int va;
            scanf("%d", &va);
            va--;
            id[va].insert( i );
            v[i].insert( va );
        }
    }

    for( int i = 0; i<m; i++ ){
        if( id[i].size() < 2 ){
            return !printf("%d\n", i);
        }
        int x = * id[i].begin();
        int y = * (++ id[i].begin());

        for( int bit : v[x] ) id[bit].erase( x );
        for( int bit : v[y] ) id[bit].erase( y );

        set < int > ns;
        for( int d : v[x]){
            if( v[y].count(d) ) v[y].erase(d);
            ns.insert( d );
        }

        for( int d : v[y]){
            ns.insert( d );
        }

        v[y] = ns;
        for( int bit : v[y] ) id[bit].insert( y );

     }
     printf("%d", m);
    return 0;
}

