#ifndef TSP_H
#define TSP_H
#include <vector>

/*Prim's algorithm for a minimal spanning tree
  using adjacency matrix graph representation */
std::vector<int> prims(std::vector<std::vector<int>> graph);


//A vertex in a graph
struct vertex{
    int distance = -1;      //distance to vertex from start
    int predecessor = -1;   //preceding vertex
    bool visit = false;     //tracks if the vertex has been visited
};

//A graph class with a member function to perform a depth first search
class DFSgraph
{
    unsigned int numVert;   //number of vertices

    std::vector<std::vector<int>> adjMatrix; //2D vector storing adjacency

    std::vector<vertex> vertices; //vector storing the vertices

public:
    //constructor that takes number of vertices for the graph
    DFSgraph(unsigned int numVertices);

    //adds an undirected edge between two vertices
    void addEdge(unsigned int a, unsigned int b);

    //Depth first search from a given starting vertex
    void DFS(unsigned int start);
};

/*A 2-approximate solution to the travelling salesman problem
 *prints the order in which the vertices should be traversed */
void travelSalesmanApprox(std::vector<std::vector<int>> graph);


#endif // TSP_H
