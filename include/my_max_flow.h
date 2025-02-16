
#include "libraries.h"
using namespace std;

bool bfs(vector<ydragogeio>& graph, int source, int sink, vector<int>& parent);
vector<ydragogeio> create_residual_graph(vector<ydragogeio>& graph);
int ford_fulkerson(vector<ydragogeio>& graph, int source, int sink);