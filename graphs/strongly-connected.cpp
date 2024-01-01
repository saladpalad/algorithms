/*
Implementation of algorithm to check if a graph is strongly connected or not.
Idea: Run BFS on any vertex S and see if S can reach every node in the graph.
Then repeat the process but on the reversed graph. If both BFS are successful
and S can reach every node, then the graph is strongly connected.
Ch. 3.5
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

template <typename T> class Graph {
  std::vector<std::vector<T>> adjList;
  std::vector<std::vector<T>> revAdjList;

public:
  explicit Graph(size_t n) : adjList(n), revAdjList(n) {}

  void addEdge(T u, T v) {
    adjList[u].push_back(v);
    revAdjList[v].push_back(u); // Reverse the edge for reverse graph
  }

  bool BFS(T start, std::vector<std::vector<T>> &graph) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<T> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
      T u = q.front();
      q.pop();

      for (T v : graph[u]) {
        if (!visited[v]) {
          visited[v] = true;
          q.push(v);
        }
      }
    }
    // Check if all nodes were able to be visited from the starting vertex
    return std::all_of(visited.begin(), visited.end(),
                       [](bool v) { return v; });
  }

  // Run BFS on G and G reversed
  bool isStronglyConnected() {
    for (size_t i = 0; i < adjList.size(); ++i) {
      if (!BFS(i, adjList)) {
        return false;
      }
    }

    for (size_t i = 0; i < revAdjList.size(); ++i) {
      if (!BFS(i, revAdjList)) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  Graph<int> g(3);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 0);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 1);

  bool isStronglyConnected = g.isStronglyConnected();

  if (isStronglyConnected) {
    std::cout << "The graph is strongly connected!" << std::endl;
  } else {
    std::cout << "The graph is not strongly connected!" << std::endl;
  }

  return 0;
}
