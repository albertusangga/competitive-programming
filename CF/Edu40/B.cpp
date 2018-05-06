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
#define RESET(_a, _value) memset(_a, _value, sizeof(_a))
#define ALL(_a) _a.begin(), _a.end()
#define SIZE(_a) _a.size()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define newline '\n';

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
const int INF = 2e9;

const int MAX_N = 1e3 + 5;

int n;
string s;

int main() {
	FAST_IO();
	
	cin >> n;
	cin >> s;
	if (n == 1) {
		cout << 1 << endl;
		exit(0);
	}
	int ans = 1e9;
	FORD(i, n / 2, 0) {
		int cur = i;
		string repeat = s.substr(0, i);
		string after = s.substr(i, i);
		if (repeat == after) {
			cur += 1;
		} else {
			cur += i;
		}
		cur += (n - 2*i);
		ans = min(ans, cur);
	}

	cout << ans << endl;

	return 0;
}
