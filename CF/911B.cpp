#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;

#define newline '\n';
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FAST_IO ios_base::sync_with_stdio(false)

const int PI = acos(-1.0);
const int MOD = 1e9 + 7;

int N, A, B;

int main() {
  cin >> N >> A >> B;
  int ans = -1;
  for (int a = 0; a <= A; ++a) {
    int b = N - a;
    ans = max(ans, min(A / max(a, 1), B / max(b, 1)));
  }
  cout << ans << "\n";

  return 0;
}