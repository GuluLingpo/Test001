//time complexity : O(V + ElogE) or O(VlogE)

using Edge = pair<int, int>;
#define w first
#define idx second

int vn;			//number of vertices
int dist[MAX_V];		//shortest path from start
vector<Edge> adj[MAX_V];	//adjacent list

void dijkstra(int s)
{
	vector<bool> vis(vn, false);
	fill(dist, dist + vn, INF);
	dist[s] = 0;
	priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
	pq.emplace(0, s);
	
	while (!pq.empty()) {
		int u = pq.top().idx;
		pq.pop();
		
		if (vis[u]) continue;
		vis[u] = true;
		
		for (auot v:adj[u]) {
			if (dist[v.idx] > dist[u] + v.w) {
				dist[v.idx] = dist[u] + v.w;
				pq.emplace(dist[v.idx], v.idx);
			}
		}
	}
}
