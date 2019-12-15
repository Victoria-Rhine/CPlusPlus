#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H
#define NODE 14
#include <iostream>
#include <iterator>
#include <list>
#include <queue>

// implementing BFS on adjacency matrix
typedef  struct node {
    int value = 0;
    int state = 0; //status
} node;

void BFSMatrix(node *vertex, node s);

/* implementing BFS on adjacency list
 * class to handle vertex information */
class Vertex
{
public:
    std::list<Vertex*> neighbors;
    char data;
    bool visited;

    Vertex(): data{'\0'}, visited{false}{}
    Vertex(char ch): data{ch}, visited{false}{}

    void addNeighbor(Vertex *v);
};

// class to handle queue and execute bfs on list
class BFS
{
public:
    std::queue<Vertex*> vertexQueue;

    void showq(std::queue <Vertex*> gq);

    void BFSList(Vertex *root);
};

#endif // BREADTHFIRSTSEARCH_H
