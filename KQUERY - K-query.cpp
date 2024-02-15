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
typedef long long int ll;
typedef unsigned long long int ull;
// priority_queue<int,vector<int>,greater<int>> pq;

struct no{
	int o = 0, c = 0;//open - closed 
	bool ans = false;
}nill;

class segtree{
private:
	vector<no> seg;
	int n;
	
	no merge(no &a, no &b){
		no c;
		int mn = min(a.o, b.c);
		c.o = a.o + b.o - mn;
		c.c = a.c + b.c - mn;
		c.ans = (!c.o && !c.c);
		return c;
	}
	
	void build(int id, int l, int r, string &s){
		if(l==r){
			if(s[l]=='(') seg[id].o++;
			else seg[id].c++;
		}
		else{
			build(2*id  ,     l, mid, s);
			build(2*id+1, mid+1,   r, s);
			seg[id] = merge(seg[2*id], seg[2*id+1]);
		}
	}
	
	no query(int id, int l, int r, int x, int y){
		if(y<l || x>r) return nill;
		if(l>=x && r<=y) return seg[id];
		no a = query(2*id  ,     l, mid, x, y);
		no b = query(2*id+1, mid+1,   r, x, y);
		return merge(a, b);
	}
	
	void update(int id, int l ,int r, int x){
		if(x<l || x>r) return;
		if(l==x && x==r){
			seg[id].o = !seg[id].o;
			seg[id].c = !seg[id].c;
			return;
 		}
 		update(2*id  ,     l, mid, x);
 		update(2*id+1, mid+1,   r, x);
 		seg[id] = merge(seg[2*id], seg[2*id+1]);
	}
	
public:
	segtree(string &s){
		n = sz(s);
		seg.assign(4*n, nill);
		build(1, 0, n-1, s);
	}
	void update(int x) { update(1, 0, n-1, x-1);}
	bool query() { return query(1, 0, n-1, 0, n-1).ans;}
};

int main (){
	
	fast;
	for(int tc = 1; tc<=10; tc++){
		cout << "Test " << tc << ":\n"; 
		int n, q; cin >> n;
		string s; cin >> s;
		segtree sg(s);
		cin >> q;
		for(int i=0, x;i<q;i++){
			cin >> x;
			if(x) sg.update(x);
			else cout << (sg.query() ? "YES\n" : "NO\n");
		}
	}
}
