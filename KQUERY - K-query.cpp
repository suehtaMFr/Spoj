#include <vector>
#include <iostream>
#include <algorithm>

// Regular show
#define import python
#define mid ((l+r)>>1)
#define sz(x) ((int)x.size())
#define fin freopen ("in.txt","r",stdin);
#define fout freopen ("out.txt","w",stdout);
#define fast std::ios_base::sync_with_stdio(false),std::cin.tie(NULL),std::cout.tie(NULL);
// Rapadura é doce, mas não é mole não.
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
// I see you
typedef long long int ll;
typedef unsigned long long int ull;
// priority_queue<int,vector<int>,greater<int>> pq;

int n;
std::vector<int> nill;
std::vector<std::vector<int>> seg(120000, nill);

void build(int id, int l, int r, std::vector<int> &v){
	if(l==r) seg[id].eb(v[l]);
	else{
		build(2*id  ,     l, mid, v);
		build(2*id+1, mid+1,   r, v);
		std::vector<int> c(sz(seg[2*id])+sz(seg[2*id+1]));
		merge(begin(seg[2*id]), end(seg[2*id]), begin(seg[2*id+1]), end(seg[2*id+1]), begin(c));
		seg[id] = c;
	}
}

int query(int id, int l, int r, int x, int y, int k){
	if(y<l || x>r) return 0;
	if(l>=x && r<=y){
		int p = upper_bound(begin(seg[id]), end(seg[id]), k) - begin(seg[id]);
		return sz(seg[id]) - p;
	}
	int a = query(2*id  ,     l, mid, x, y, k);
	int b = query(2*id+1, mid+1,   r, x, y, k);
	return a + b;
}

int main (){
	
	fast;
	int q; std::cin >> n;
	std::vector<int> v(n), a;
	for(int i=0;i<n && std::cin >> v[i];i++);
	build(1, 0, n-1, v);
	std::cin >> q;
	for(int i=0,x ,y ,k;i<q;i++){
		std::cin >> x >> y >> k;
		std::cout << query(1, 0, n-1, x-1, y-1, k) << "\n";
	}
}
