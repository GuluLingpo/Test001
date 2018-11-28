#include <iostream>
#include <vector>
#include <queue>
#include "function.h"
using namespace std;

void Implement::addEdge(const int label_1, const int label_2 , const int weight)
{
    this->VertexArr[label_1].neighbors.push_back(Neighbor(label_2, weight));
    this->VertexArr[label_2].neighbors.push_back(Neighbor(label_1, weight));
}

struct cmp_Neighbor {
    bool operator() (const Neighbor& a, const Neighbor& b) {
        return (a.weight > b.weight);
    }
};

int Implement::shortest_path(const int label_1 , const int label_2)
{
    int vn = (int)this->VertexArr.size();
    
    int dist[vn];
    fill(dist, dist + vn, 1e9);
    dist[label_1] = 0;

    priority_queue<Neighbor, vector<Neighbor>, cmp_Neighbor> pq;
    pq.emplace(label_1, 0);

    vector<bool> visited(vn, false);

    while (!pq.empty())
    {
        int u = pq.top().label;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        int nn = this->VertexArr[u].neighbors.size();
        for (int v = 0; v < nn; v++) {
            if (dist[this->VertexArr[u].neighbors[v].label] > dist[u] + this->VertexArr[u].neighbors[v].weight) {
                dist[this->VertexArr[u].neighbors[v].label] = dist[u] + this->VertexArr[u].neighbors[v].weight;
                pq.emplace(this->VertexArr[u].neighbors[v].label, dist[this->VertexArr[u].neighbors[v].label]);
            }
        }
    }

    return dist[label_2];
}

int Implement::mst_weight()
{
    int vn = (int)this->VertexArr.size();
    int ans = 0;

    priority_queue<Neighbor, vector<Neighbor>, cmp_Neighbor> pq;

    vector<bool> visited(vn, false);
    visited[0] = true;

    int nn = this->VertexArr[0].neighbors.size();
    for (int v = 0; v < nn; v++)
        pq.emplace(this->VertexArr[0].neighbors[v].label, this->VertexArr[0].neighbors[v].weight);
    
    while (!pq.empty()) {
        Neighbor nei = pq.top();
        pq.pop();

        if (visited[nei.label]) continue;
        visited[nei.label] = true;

        ans += nei.weight;

        nn = this->VertexArr[nei.label].neighbors.size();
        for (int v = 0; v < nn; v++)
            pq.emplace(this->VertexArr[nei.label].neighbors[v].label, this->VertexArr[nei.label].neighbors[v].weight);
    }
    
    return ans;
}

bool Implement::two_colorable()
{
    int colorable = true;
    int color[7122] = {};
    for (int i = 0; i < 7122; i++) {
        color[i] = 0;
    }
    vector<int> inGraph;
    for (int i = 0; i < (int)this->VertexArr.size(); i++) {
        if (this->VertexArr[i].neighbors.size())
           inGraph.push_back(i);
    }

    queue<int> q;
    q.push(inGraph[0]);
    color[inGraph[0]] = 1;

    while (!q.empty()) {
        //Vertex &vq = this->VertexArr[q.front()];
        int nn = this->VertexArr[q.front()].neighbors.size();
        for (int i = 0; i < nn; i++) {
            if (color[this->VertexArr[q.front()].neighbors[i].label] == 0) {
                if (color[q.front()] == 1) {
                    color[this->VertexArr[q.front()].neighbors[i].label] = -1;
                } else if (color[q.front()] == -1) {
                    color[this->VertexArr[q.front()].neighbors[i].label] = 1;
                }
                q.push(this->VertexArr[q.front()].neighbors[i].label);
            } else if (color[this->VertexArr[q.front()].neighbors[i].label] == 1) {
                if (color[q.front()] == 1) {
                    colorable = false;
                    break;
                }
            } else if (color[this->VertexArr[q.front()].neighbors[i].label] == -1) {
                if (color[q.front()] == -1) {
                    colorable = false;
                    break;
                }
            }
        }
        q.pop();
        if (!colorable) {
            break;
        }
    }

    return colorable;
}
