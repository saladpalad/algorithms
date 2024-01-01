/*
Implementation of BFS two-coloring algo to check if a graph is bipartite
Idea: Nodes in the same layer must not share the same color to each other
Ch. 3.4
*/

#include <iostream>
#include <queue>
#include <vector>

template <typename T> class Graph {
  std::vector<std::vector<T>> adjList;
  std::vector<int> colors;

public:
  explicit Graph(size_t n) : adjList(n), colors(n, -1) {}

  void addEdge(T u, T v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  bool isBipartite(T s) {
    colors[s] = 0; // Assign color 0 to the starting vertex
    std::queue<T> q;
    q.push(s);

    while (!q.empty()) {
      T u = q.front();
      q.pop();
      for (T v : adjList[u]) {
        if (colors[v] == -1) {
          colors[v] =
              1 - colors[u]; // Assign the opposite color to neighboring node
          q.push(v);
        } else if (colors[v] == colors[u]) {
          return false;
        }
      }
    }
    return true;
  }
};

int main() {
  Graph<int> g(6);

  g.addEdge(0, 3);
  g.addEdge(0, 4);
  g.addEdge(0, 5);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(1, 5);
  g.addEdge(2, 3);
  g.addEdge(2, 4);
  g.addEdge(2, 5);

  bool isBipartite = g.isBipartite(0);

  if (isBipartite) {
    std::cout << "The graph is bipartite!" << std::endl;
  } else {
    std::cout << "The graph is not bipartite!" << std::endl;
  }

  return 0;
}
