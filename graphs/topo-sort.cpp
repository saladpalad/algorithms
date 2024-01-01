/*
Implementation of topo-sort using Kahn's algorithm (essentially just BFS lol)
Time Complexity: O(m+n)
Ch. 3.6
*/
#include <iostream>
#include <queue>
#include <vector>

template <typename T> class Graph {
  std::vector<std::vector<T>> adjList;

public:
  explicit Graph(size_t n) : adjList(n) {}

  void addEdge(T u, T v) { adjList[u].push_back(v); }

  std::vector<T> topoSort() {
    std::vector<T> sorted;
    std::vector<int> inDegree(adjList.size(), 0);

    // Calculate in-degrees of vertices
    for (const auto &edges : adjList) {
      for (T v : edges) {
        inDegree[v]++;
      }
    }

    std::queue<T> q;
    for (T i = 0; i < adjList.size(); ++i) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    while (!q.empty()) {
      T u = q.front();
      q.pop();
      sorted.push_back(u);

      for (T v : adjList[u]) {
        if (--inDegree[v] == 0) {
          q.push(v);
        }
      }
    }

    if (sorted.size() != adjList.size()) {
      // Graph has at least one cycle
      return std::vector<T>();
    } else {
      return sorted;
    }
  }
};

int main() {
  Graph<int> g(7);

  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);

  std::vector<int> sorted = g.topoSort();

  if (sorted.empty()) {
    std::cout << "Error: Graph has at least one cycle!" << std::endl;
  } else {
    std::cout << "Topologically sorted order: ";
    for (int node : sorted) {
      std::cout << node << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
