#include <bits/stdc++.h>

using namespace std;

#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)

#define mp make_pair
#define pb push_back
#define newline '\n'

using ii = pair<int, int>;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

const int MAX_V = 1e5 + 5;

int V, E;
int s, t;
vvii adj_list;
ll dist[MAX_V];
ll arr[MAX_V];

vector<ll> ans;

int main() {
  FAST_IO;

  cin >> V >> E;
  adj_list.resize(V + 5);
  for (int i = 0; i < E; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj_list[u].pb({v, w*2});
  }

  for (int i = 0; i < V; ++i) {
	  	memset(dist, 127, sizeof(dist));
	  	cin >> a[i];
		priority_queue<ii, vii, greater<ii> > pq;

		pq.push({0, i});
		dist[s] = 0;

		while (!pq.empty()) {
			int w = pq.top().first;
			int u = pq.top().second;
			pq.pop();
			if (w > dist[u]) continue;

			for (ii adj : adj_list[u]) {
				int v = adj.first;
				int cost = adj.second;
				if (dist[u] + cost < dist[v]) {
					dist[v] = dist[u] + cost;
					pq.push({dist[v], v});
				}
			}
		}
		
  }

  return 0;
}