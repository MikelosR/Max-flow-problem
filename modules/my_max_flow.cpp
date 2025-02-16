
#include "../include/agogos.h"
#include "../include/idragogeio.h"
#include "../include/my_max_flow.h"
using namespace std;

bool bfs(vector<ydragogeio>& graph, int source, int sink, vector<int>& parent) {
    vector<bool> visited(graph.size(), false); //avoid cycles or revisiting the same node during the BFS traversal
    queue<int> q;   //BFS explores all neighbors of a node before moving to the next level in the graph
    visited[source] = true;
    q.push(source);
    //Use BFS
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (const auto& edge : graph[u].get_edges()) {
            int v = edge.get_send_to_idragogeio();
            if (!visited[v] && edge.get_capacity() > 0) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
                if (v == sink) return true;
            }
        }
    }
    return false;
}

vector<ydragogeio> create_residual_graph(vector<ydragogeio>& graph){
    //make a vector with "vertexes" for the residual graph
    vector<ydragogeio> residualGraph;
    agogos temp_edge;
    vector<agogos> temp_residual_edges;
    //Fill the residualGraph with values from graph
    for (auto& vertex : graph) {
        ydragogeio newVertex(vertex.get_name());
        for (auto& edges : vertex.get_edges()){
            //use the copy constructor of class agogos
            temp_edge = edges;
            newVertex.add_edge(temp_edge);
            temp_residual_edges.push_back(edges);
        }
        residualGraph.push_back(newVertex);
    }

    //Add in the residual graph the reverse edges
    for (unsigned long i = 0; i < temp_residual_edges.size(); i++) {
        temp_edge.set_from_idragogeio(temp_residual_edges[i].get_send_to_idragogeio());
        temp_edge.set_send_to_idragogeio(temp_residual_edges[i].get_from_idragogeio());
        temp_edge.set_flow(0);
        temp_edge.set_capacity(0);
        residualGraph[temp_edge.get_from_idragogeio()].add_edge(temp_edge);
    }
    return residualGraph;
}


int ford_fulkerson(vector<ydragogeio>& graph, int source, int sink) {
    vector<int> parent(graph.size(), -1);
    int max_flow = 0;

    vector<ydragogeio> residualGraph = create_residual_graph(graph);

    //Augment the flow while there is an augmenting path
    while (bfs(residualGraph, source, sink, parent)) {
        int path_flow = INT_MAX;
        int s = sink;
        // Find the maximum flow through the path found by BFS
        while (s != source) {
            int u = parent[s];
            for (auto& edge : residualGraph[u].get_edges()) {
                if (edge.get_send_to_idragogeio() == s) {
                    path_flow = min(path_flow, edge.get_capacity());
                    //cout<<"path_flow: "<<path_flow<<endl;
                    break;
                }
            }
            s = parent[s];
        }
        //Update the residual capacities and flows
        s = sink;
        while (s != source) {
            int u = parent[s];
            for (auto& edge : residualGraph[u].get_edges()) {
                if (edge.get_send_to_idragogeio() == s) {
                    edge.set_capacity(edge.get_capacity() - path_flow);  //Forward edge flow update
                    break;
                }
            }

            for (auto& edge : residualGraph[s].get_edges()) {
                if (edge.get_send_to_idragogeio() == u) {
                    edge.set_capacity(edge.get_capacity() + path_flow);  // Reverse edge flow update
                    //cout<<"residual edge after: "<<edge.get_capacity()<<endl;
                    break;
                }
            }
            s = parent[s];
        }
        max_flow += path_flow;
    }

    return max_flow;
}

//For debugging, print the queue
void showq(queue<int> gq)
{
    queue<int> g = gq;
    while (!g.empty()) {
        cout << '\t' << g.front();
        g.pop();
    }
    cout << '\n';
}