#include<bits/stdc++.h>
using namespace std;

const int NMAX = 1e5;
map<string, int> id;
vector<string> words;
vector<int> back[NMAX];
bool visited[NMAX];
int out[NMAX];
int dp[NMAX][2];
string str, a, b;


bool better(int i, int j){
	if(dp[i][0] < dp[j][0]){
		return i;
	}else if(dp[i][0] == dp[j][0]){
		if(dp[i][1] < dp[j][1]){
			return i;
		}else{
			return j;
		}
	}else{
		return j;
	}
}

void find(int n){
	queue<int> q;
	for(int i = 0; i < n; i++){
		if(out[i] == 0){
			q.push(i);
		}
		string word = words[i];
		dp[i][1] = word.size();
		for(int j = 0; j < word.size(); j++){
			if(word[j] == 'r'){
				dp[i][0]++;
			}
		}
	}
	while(q.size()){
		int u = q.front();
		q.pop();
	}
	
}



int main(){
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> str;
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		words.push_back(str);
		id[str] = i;
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		transform(a.begin(), a.end(), a.end(), ::tolower);
		transform(b.begin(), b.end(), b.end(), ::tolower);
		int ida = id[a], idb = id[b];
		back[idb].push_back(ida);		
		out[ida]++;
	}
	
}
