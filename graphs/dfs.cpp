#include <iostream>
#include <stack>
#include <vector>

template <typename T> class Graph {
  std::vector<std::vector<T>> adjList;
  std::vector<bool> discovered;

public:
  explicit Graph(size_t n) : adjList(n), discovered(n, false) {}

  void addEdge(T u, T v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // Comment this line for undirected graph
  }

  void DFS(T start) {
    std::stack<T> s;
    discovered[start] = true;
    s.push(start);

    while (!s.empty()) {
      T u = s.top();
      s.pop();

      std::cout << u << " ";

      for (T v : adjList[u]) {
        if (!discovered[v]) {
          discovered[v] = true;
          s.push(v);
        }
      }
    }
  }
};

int main() {
  Graph<int> g(6);

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(1, 4);
  g.addEdge(2, 4);
  g.addEdge(3, 4);
  g.addEdge(3, 5);
  g.addEdge(4, 5);

  std::cout << "DFS Traversal starting from vertex 0: ";
  g.DFS(0);

  return 0;
}
