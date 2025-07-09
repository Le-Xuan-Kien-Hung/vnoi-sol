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
 *    created: 
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
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 1e9 ; 
// ================================================================================================================

#define int long long 
int n , k ;
int a[maxN] , f[maxN] ; 
int bitMa[maxN] , bitMi[maxN] ; 
vector<int> sortedA ; 
int val[maxN] ;
pair<int , int> b[maxN] ; 
int d = 0 ;
void up(bool t , int x , int val) {
	for(x++ ; x > 0 ; x -= x & -x) {
		if(t) maximize(bitMa[x] , val) ; 
		else minimize(bitMi[x] , val) ; 
	}
}

int get(bool t , int x) {
	int ans = 0 ;
	if(t) {
		ans = -INF ; 
		for(x++ ; x <= d + 1 ; x += x & -x) 
			maximize(ans , bitMa[x]) ; 
	}
	else {
		ans = INF ;
		for(x++ ; x <= d + 1 ; x += x & -x) 
			minimize(ans , bitMi[x]) ; 
	}

	return ans ; 
}
bool ok(int x) {
	int fmi = 0 , fma = 0 ; 
	FOR(i , 1 , d + 1) bitMa[i] = -INF , bitMi[i] = INF ; 
	up(0 , a[0] , 0) ; up(1 , a[0] , 0) ; 
	FOR(i , 1 , n) {
		int valS = val[a[i]] - x ; 
		int pos = lower_bound(val + 1 , val + d + 1 , valS) - val ;
		fmi = get(0 , pos) + 1 ; 
		fma = get(1 , pos) + 1 ;
		up(0 , a[i] , fmi) ;
		up(1 , a[i] , fma) ; 
	}

	return fmi <= k and k <= fma ; 
}
void solve() {
	cin >> n >> k ;
	FOR(i , 1 , n) {
		cin >> a[i] ;
		a[i] += a[i - 1] ; 
		sortedA.emplace_back(a[i]) ;
		b[i] = make_pair(a[i] , i) ;
 	}

 	sort(b , b + n + 1) ; 
 	FOR(i , 0 , n) {
 		if(i == 0 || b[i].fir != b[i - 1].fir) ++d;
 		val[d] = a[b[i].sec] , a[b[i].sec] = d ; 
 	}

 	// if(ok(4)) {
 		// cout << "YES\n" ; 
 	// }
	int l = -INF , r = INF , ans = 0 ; 
	while(l <= r) {
		int m = (l + r) >> 1 ;
		if(ok(m)) {
			// cout << "OK " << m << '\n' ; 
			ans = m ; 
			r = m - 1 ; 
		}
		else l = m + 1 ; 
	}

	cout << ans << '\n' ; 
}
signed main(){
    freopen("qbsegpar"); 
    FastIO;
    int numTest = 1 ;
    // cin >> numTest;
    while(numTest--) {
        solve();
    }

    cerr << '\n' << "Time elapsed " << TIME << "s.\n";
    return 0;
}