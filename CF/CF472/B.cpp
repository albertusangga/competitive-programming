#include <bits/stdc++.h>

using namespace std;

void FAST_IO() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

#define REP(_i, _a) for(int _i = 0; _i < _a; ++_i)
#define FOR(_i, _a, _b) for(int _i = _a; _i <= _b; ++_i)
#define FORD(_i, _a, _b) for(int _i = _a; _i >= _b; --_i)
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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const double PI = acos(-1.0);
const int MOD = 1e9 + 7;
const int MOD2 = 1e9 + 9;
const int INF = 2e9;

const int MAX_N = 5e2 + 5;

int n, m;
string s[55];
ii hash_value[55];

int main() {
	FAST_IO();
	
	cin >> n >> m;
	REP(i, n) {
		cin >> s[i];
		int hash1 = 0;
		int hash2 = 0;
		REP(j, m) {
			hash1 = (s[i][j] + (ll)hash1 * 7) % MOD;
			hash2 = (s[i][j] + (ll)hash2 * 11) % MOD2;
		}
		hash_value[i] = {hash1, hash2};
	}

	REP(c, m) {
		set<ii> cnt;
		cnt.clear();
		REP(r, n) {
			if (s[r][c] == '#') {
				cnt.insert(hash_value[r]);
			}
		}
		if (cnt.size() > 1) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";

	return 0;
}
