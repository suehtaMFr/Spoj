#include <bits/stdc++.h>

using namespace std;

vector<int> adj[2024];

void deep(int u,int v,bool & ans,int cl[]) {
	
	cl[u]=v;
	for(int x:adj[u])
	{
		if(cl[x]==cl[u])
		{
			ans = false;
			return;
		}
		if(!cl[x])deep(x,(v%2+1),ans,cl);
	}
}

int main () {
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc,v,e,x,y;
	cin >> tc;
	for(int i=1;i<=tc;i++)
	{
		cin >> v >> e;
		int cl[v+1]={0};
		for(int j=0;j<e;j++)
		{
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		bool ans=true;
		for(int j=1;j<=v && ans;j++)
		{
			if(!cl[j])
				deep(j,1,ans,cl);
		}
		cout << "Scenario #" << i << ":\n";
		cout << (!ans ? "Suspicious bugs found!" : "No suspicious bugs found!") << "\n";
		for(int j=1;j<=v;j++)
			adj[j].clear();
	}
}
