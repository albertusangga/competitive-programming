/*
	Store only one edge
  Maximum match
  N = max(n, m)
*/

#include <bits/stdc++.h>

using namespace std;

void FAST_IO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define REP(_i, _a) for(int _i = 0; _i < (int)_a; ++_i)
#define FOR(_i, _a, _b) for(int _i = (int)_a; _i <= (int)_b; ++_i)
#define FORD(_i, _a, _b) for(int _i = (int)_a; _i >= (int)_b; --_i)
#define RESET(_a, _value) fill_n(_a,sizeof(_a)/sizeof(_a[0]),_v)
#define ALL(_a) _a.begin(), _a.end()
#define SIZE(_a) _a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define newline '\n';

// DEBUG UTIL
#define DEBUG(args...) { cerr << "> "; \
						 string _s = #args; \
						 replace(_s.begin(), _s.end(), ',', ' '); \
						 stringstream _ss(_s); istream_iterator<string> _it(_ss); \
						 err(_it, args); }

void err(istream_iterator<string> it) { cerr << endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << ": " << a << " ";
	err(++it, args...);
}

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string format(const string& s, ...) {
    va_list args;
    va_start (args, s);
    size_t len = vsnprintf(NULL, 0, s.c_str(), args);
    va_end (args);
    std::vector<char> vec(len + 1);
    va_start (args, s);
    vsnprintf(&vec[0], len + 1, s.c_str(), args);
    va_end (args);
    return &vec[0];
}

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int INF = 1e8;

const int MAX_M = 1005;
const int MAX_N = 1005;


int W[MAX_N][MAX_N], N;
int my[MAX_N]; // match arr
int lx[MAX_N], ly[MAX_N]; // label arr
int x[MAX_N], y[MAX_N]; // used arr

int hungary(int nd) {
    int i;
    x[nd] = 1;
    for(i = 1; i <= N; i++) {
        if(y[i] == 0 && W[nd][i] == lx[nd]+ly[i]) {
            y[i] = 1;
            if(my[i] == 0 || hungary(my[i])) {
                my[i] = nd;
                return 1;
            }
        }
    }
    return 0;
}

int n, m, k;

void read() {
	scanf("%d %d %d", &n, &m, &k);
	N = max(n, m);
	int i, j, p;
	REP(_i, k) {
		scanf("%d %d %d", &i, &j, &p);
		W[i][j] = p;
	}
}

void solve() {
	int d;
		
	FOR(i, 1, N)
		FOR(j, 1, N)
			lx[i] = lx[i] > W[i][j] ? lx[i] : W[i][j];

	FOR(i, 1, N) {
			while(1) {
					memset(x, 0, sizeof(x));
					memset(y, 0, sizeof(y));
					if(hungary(i))  break;
					d = INF;
					FOR(j, 1, N) {
						if(x[j]) {
								FOR(k, 1, N)
									if(!y[k])
										d = d < lx[j]+ly[k]-W[j][k] ?
											d : lx[j]+ly[k]-W[j][k];
						}
					}
					if(d == INF)  break;
					FOR(j, 1, N) {
							if(x[j]) lx[j] -= d;
							if(y[j]) ly[j] += d;
					}
			}
	}
	int res = 0, cnt = 0;
	FOR(i, 1, N) {
		if (my[i] && W[my[i]][i]) {
			res += W[my[i]][i];
			++cnt;
		}
	}
	
	printf("%d\n", res);
	printf("%d\n", cnt);
	FOR(i, 1, n) {
		if (my[i] && W[my[i]][i]) {
			printf("%d %d\n", my[i], i);
		}
	}

}

int main() {
	// FAST_IO();

	int TC = 1;
	// cin >> TC;
	FOR(tc, 1, TC) {
		read();
		solve();
	}

	return 0;
}
