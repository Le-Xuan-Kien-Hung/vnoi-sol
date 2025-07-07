// D:\Sublime Text\Packages\User
#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2")
#pragma GCC optimize ("O3,unroll-loops,no-stack-protector")
// =================================================================================================================
template <typename T> inline void read(T &x){bool nega=0;char c;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
template <typename T> inline void display(T x){if(x>9) display(x/10);putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}display(x);}
template <typename T> inline void writeln(T x){write(x);putchar('\n');}
template <typename T> void maximize(T &res, T val) { if (res < val) res = val; }
template <typename T> void minimize(T &res, T val) { if (res > val) res = val; }

/**
 *    author:  cc123
 *    created: 07/07/2025 7:00:19 CH (GMT+7)
**/

#define ll long long 
#define str string
#define pb push_back
#define fir first
#define sec second
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FOR(i,a,b) for(int (i)=(a) ; i<=(b) ; i++)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define FastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define freopen(name) if(fopen(name".inp","r")) {freopen (name".inp","r",stdin); freopen (name".out","w",stdout);}
#define getbit(x , i) (((x) >> i) & 1) 
#define seton(x , i) ((x) | (1ULL << (i)))
#define setoff(x , i) ((x) &~ (1ULL << i))
#define flip(x , i) ((x)^(1ULL << i)) 

const int maxN = 1e6 + 7;
const ll LINF = 1e18;
const int INF = 1e9 + 9 ; 
// ================================================================================================================

#define int long long 
int n , L , R ;
int a[maxN] ;
vector<int> sortedA ; 

int bit[maxN] ; 
void up(int x , int val) {
	for(; x <= (int)sortedA.size() + 5 ; x += x & -x) bit[x] += val ; 
}
int get(int x) {
	int ans = 0 ;
	for(; x > 0  ; x &= x - 1) ans += bit[x] ;
	return ans ; 
}
int getSum(int l , int r) {
	return get(r) - get(l - 1) ; 
}
int getIdx(int val) {
	int pos = upper_bound(ALL(sortedA) , val) - sortedA.begin() - 1 ;
	return pos ; 
}
void solve() {
	cin >> n >> L >> R ; 
	FOR(i , 1 , n) {
		cin >> a[i] ;
		a[i] += a[i - 1] ; 
		sortedA.emplace_back(a[i] - L) ; 
		sortedA.emplace_back(a[i] - R) ; 
		sortedA.emplace_back(a[i]) ; 
	}
	sortedA.emplace_back(0) ; 
	sortedA.emplace_back(-LINF) ; 
	sort(ALL(sortedA)) ; 	

	auto it = unique(ALL(sortedA)) ; 

	sortedA.erase(it , sortedA.end()) ; 

	up(getIdx(0), 1) ; 

	int ans = 0 ; 
	FOR(i , 1 , n) {
		int barL = a[i] - R ; 
		int barR = a[i] - L ; 
		// count element from [barL ... barR] by BIT ;

		int idL = getIdx(barL) , idR = getIdx(barR) ; 

		int t = get(idR) - get(idL - 1) ; 
		ans = ans + t ; 

		up(getIdx(a[i]) , 1) ; 
	}
	
	cout << ans << '\n' ; 
}
signed main(){
    freopen(""); 
    FastIO;
    int numTest = 1 ;
    // cin >> numTest;
    while(numTest--) {
        solve();
    }

    cerr << '\n' << "Time elapsed " << TIME << "s.\n";
    return 0;
}
