//time complexity : O(VlogE)

using Edge = pair<int, int>;
#define w first
#define idx second

int vn;			//number of vertices
vector<Edge> adj[MAX_V]; 	//adjacent list

int prim_pq()
{
	int tot = 0;
	priority_queue< Edge, vector<Edge>, greater<Edge> > pq;
	vector<bool> vis(vn, false);
	vis[0] = true;
	for (auto v:adj[0]) pq.emplace(v);
	
	while (!pq.empty()) {
		Edge mn = pq.top();
		pq.pop();
		if (vis[mn.idx]) continue;
		vis[mn.idx] = true;
		tot += mn.w
		for (auto v:adj[mn.idx]) pq.emplace(v);
	}
	
	return tot;
}
