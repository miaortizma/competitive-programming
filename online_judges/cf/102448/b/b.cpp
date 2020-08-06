
#include<bits/stdc++.h>
#define ms(a,v) memset(a,v,sizeof a)
#define ll long long
#define N 200005
using namespace std;

int n,m,q;
string arr[N];
map<string,int> mp;
int sg[N*2];
int operation(int a, int b){
    return a+b;
}
void initTree(){
   for(int i=0;i<n;i++)
        sg[i+n]=mp[arr[i]];
    for(int i=n-1;i>0;i--)
        sg[i]=operation(sg[i<<1],sg[(i<<1)+1]);

}
int query(int l,int r){
    l+=n;
    r+=n+1;
    int ans=0;
    for(;l < r;l>>=1,r>>=1) {
        if (l & 1) ans=operation(ans,sg[l++]);
        if (r & 1) ans=operation(ans,sg[--r]);
    }
    return ans;
}
void actualizar(int position,int value){
    sg[position+n]=value;
    for(int pos=(n+position)/2;pos>0;pos/=2)
        sg[pos]=operation(sg[pos*2],sg[pos*2+1]);
}
int main(){
	#ifdef LOCAL
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<m;i++){
        string s;
        int w;
        cin>>s>>w;
        mp[s]=w;
    }
    initTree();
    for(int i=0;i<q;i++){
        int type;
        scanf("%d",&type);
        if(type==1){
            int h;
            string s;
            cin>>h>>s;
            actualizar(h-1,mp[s]);
        }else{
            int l,r;
            scanf("%d %d",&l,&r);
            int x=query(l-1,r-1);
            int tot=(r-l+1)*30;
            if(x>tot)
                printf("YES\n");
            else
                printf("NO\n");
        }

    }
	return 0;
}

