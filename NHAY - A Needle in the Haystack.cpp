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
typedef vector<int> vi;
typedef vector<ll> vll;
// priority_queue<int,vector<int>,greater<int>> pq;

vi kmp_function(string const& S) {
  int N = sz(S);
  vi pi(N, 0);
  for (int i = 1; i < N; i++) {
    int j = pi[i-1];
    while (j > 0 && S[i] != S[j]) j = pi[j-1];
    if (S[i] == S[j]) j++;
    pi[i] = j;
  }
  return pi;
}
vi find_string(string const& S, string const& T) {
  vi have;
  int N = sz(S), M = sz(T);
  auto P = kmp_function(T+"#"+S);
  for (int i = M+1; i <= N+M; i++) {
    if (P[i] == M) have.emplace_back(i-2*M);
  }
  return have;
}

int main(){
  fast;
  int n;
  while(cin>>n){
    string a, b, s; cin >> a >> b;
    vi c = find_string(b,a);
    for(int i=0;i<sz(c);i++) cout << c[i] << "\n";
    if(!sz(c)) cout << "\n";
  }
}
