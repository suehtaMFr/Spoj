#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define sz(x) ((int)x.size())
#define fin freopen ("input.txt","r",stdin);
#define fout freopen ("output.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
//rapadura é doce, mas não é mole não
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
//I see you
std::mt19937 rng((int) std::chrono ::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 205;

vector<vector<int>> adj(MAXN), cp(MAXN);// cp = capacity

int bfs(int s, int t, vector<int>& parent) {
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, INT_MAX});
	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		for (int next : adj[cur]) {
			if (parent[next] == -1 && cp[cur][next]) {
				parent[next] = cur;
				int new_flow = min(flow, cp[cur][next]);
				if (next == t) return new_flow;
				q.push({next, new_flow});
			}
		}
	}
	return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(MAXN);
    int new_flow;
    while ((new_flow = bfs(s, t, parent))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            cp[prev][cur] -= new_flow;
            cp[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main () {
	
	fast;
	int tc,v,n;
	cin >> tc;
	while(tc--){
		cp = vector<vector<int>> (MAXN,vector<int> (MAXN,0));
		cin >> v;
		for(int i = 1; i < v; i++){
			cin >> n;
			for(int j = 1,e; j <=n; j++){
				cin >> e;
				adj[i].pb(e); adj[e].pb(i);
				cp[i][e] = ((i==1||e==v) ? 1 : INT_MAX);
			}
		}
		cout << maxflow(1,v) << "\n";
		for(int i=1;i<MAXN;i++) adj[i].clear();
	}
}
