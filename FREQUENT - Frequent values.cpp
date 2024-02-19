#include <bits/stdc++.h>
 
using namespace std;
 
// Regular show
#define import python
#define mid ((l+r)>>1)
#define sz(x) ((int)x.size())
#define fin freopen ("in.txt","r",stdin);
#define fout freopen ("out.txt","w",stdout);
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
// Rapadura é doce, mas não é mole não.
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
// I see you
typedef vector<int> vi;
typedef long long int ll;
typedef unsigned long long int ull;
// priority_queue<int,vector<int>,greater<int>> pq;

int block_size, mx;

struct query{
    int l, r, idx;
    bool operator<(query other) const
    {
        return make_pair(l / block_size, r) < make_pair(other.l / block_size, other.r);
    }
};

void add(int x, vi &mp, vi &bi){
	bi[mp[x]++]--;
	bi[mp[x]]++;
	mx = max(mx, mp[x]);
}

void remove(int x, vi &mp, vi &bi){
	if(bi[mp[x]]==1 && mx==mp[x]) mx--;
	bi[mp[x]--]--;
	bi[mp[x]]++;
}

int main (){
	
	fast;
	int n, q;
	while(cin >> n && n){
		cin >> q;
		block_size = sqrt(n);
		int ini = 0;
		map<int, int> tra;
		vi v(n), ans(q), mp(200005,0), biggest(200005,0);
		vector<query> qr(q);
		for(int i=0, x;i<n;i++){
			cin >> x;
			map<int, int>::iterator it = tra.find(x);
			if(it==tra.end()){
				tra[x] = ini;
				v[i] = ini++;
			} else v[i] = (*it).ss;
		}
		for(int i=0, l, r;i<q;i++){
			cin >> l >> r;
			qr[i] = {l-1, r-1, i};
		}
		sort(all(qr));
		int l = 0, r = -1;
		mx = 0;
		for(auto x : qr){
			while(l > x.l){
				l--;
				add(v[l], mp, biggest);
			}
			while(r < x.r) {
				r++;
				add(v[r], mp, biggest);
			}
			while(l < x.l) {
				remove(v[l], mp, biggest);
				l++;
			}
			while(r > x.r) {
				remove(v[r], mp, biggest);
				r--;
			}
			ans[x.idx] = mx;
		}
		for(int i=0;i<q;i++) cout << ans[i] << "\n";
	}
}
