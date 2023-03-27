#include <bits/stdc++.h>
 
using namespace std;
 
//Regular show
#define mid ((l+r)>>1)
#define midf ((l+r)/2.0)
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
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
//~ long double pi = 3.141592653589793;
#define pfc(x) {cout << x;continue;}

class segtree{
	
private:
	int n;
	vector<vector<int>> save;
	vector<int> modify(vector<int> & a,vector<int> & b)
	{
		vector<int> c(sz(a)+sz(b));
		merge (all(a),all(b),c.begin());
		return c;
	}
	
	void build(int ii,int l,int r,vector<int> const & a){
		
		if(l==r) 
			save[ii].pb(a[l]);//leaf
		else
		{
			build(2*ii,l,mid,a);
			build(2*ii+1,mid+1,r,a);
			save[ii]=modify(save[2*ii],save[2*ii+1]);
		}
	}
	
    int query(int ii, int l, int r, int x, int y,int k) {
        
        if (x > r || y < l) 
			return 0LL;
        
        if (l >= x && r <= y)//totalmente dentro
		    return save[ii].size()-(upper_bound(save[ii].begin(),save[ii].end(),k) - save[ii].begin());
        //parcialmente dentro
        int p1 = query(2 * ii, l, mid, x, y, k);
        int p2 = query(2 * ii + 1, mid + 1, r, x, y, k);
        return p1+p2;
    }
    
public:
	segtree(vector<int> const& a) {
        n = sz(a);
        save.resize(4 * n);
        build(1, 0, n - 1, a);
    }
    int query(int x,int y,int k) {
		return query(1,0,n-1,x-1,y-1,k);
	}
};

int main () {
	int n,r=0LL,q,i,j,k;
	cin >> n;
	vector<int> v(n);
	for(int z=0;z<n;z++)
		cin >> v[z];
	segtree s(v);
	cin >> q;
	for(int z=0;z<q;z++)
	{
		cin >> i >> j >> k;
		i^=r,j^=r,k^=r;
		if(i<1) i=1;
		if(j>n) j=n;
		r = (i>j ? 0LL:s.query(i,j,k));
		cout << r << "\n";
	}
}
