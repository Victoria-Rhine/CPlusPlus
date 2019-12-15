#include "breadthfirstsearch.h"

/* implementing BFS on adjacency matrix
 * building the adjacency matrix */
static int graph[NODE][NODE] = {
    //a, b, c, d, e, f, g, h, i, j, k, l, m, n
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //a
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, //b
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1}, //c
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1}, //d
    {0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, //e
    {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0}, //f
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, //g
    {0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0}, //h
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0}, //i
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1}, //j
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0}, //k
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}, //l
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1}, //m
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0}  //n
};

void BFSMatrix(node *vertex, node s)
{
    node u;
    std::queue<node> myQueue;

    for (int i = 0; i < NODE; i++) // mark everything as not visited
        vertex[i].state = 0; // not visited

    vertex[s.value].state = 1; // mark start as visited
    myQueue.push(s); // insert starting node

    while (!myQueue.empty()) // loop until nothing in queue
    {
        u = myQueue.front(); // delete from queue and print
        myQueue.pop(); // pop off front of queue
        std::cout << char(u.value + 'A') << " ";

        for (int i = 0; i < NODE; i++)
        {
            if (graph[i][u.value])
            {
                if (vertex[i].state == 0) // when the node is non-visited
                {
                    vertex[i].state = 1;
                    myQueue.push(vertex[i]);
                }
            }
        }
        u.state = 2; // completed for node u
    }
}

/* implementing BFS on adjacency list
 * function to add new neighbor */
void Vertex::addNeighbor(Vertex *v)
{
    neighbors.push_back(v);
}

// shows vertices currently in queue
void BFS::showq(std::queue <Vertex*> gq)
{
    std::queue <Vertex*> g = gq;
    while (!g.empty())
    {
        std::cout << '\t' << g.front()->data;
        g.pop();
    }
    std::cout << '\n';
}

void BFS::BFSList(Vertex *root)
{
    Vertex *v;
    std::list<Vertex*> nbr; // list to hold neighbors
    this->vertexQueue.push(root); // add root of linked list

    while( !vertexQueue.empty()) // loop until nothing in queue
    {
        std::cout << "Queue now is :"; // prints contents of queue
        showq(vertexQueue);
        while(vertexQueue.front()->visited == true) // checks if vertex in queue is visited
        {
            this->vertexQueue.pop(); // avoids repeatedly checking already visited vertices
        }
        v = vertexQueue.front(); // get vertex from queue
        this->vertexQueue.pop(); // pop off vertex
        std::cout << v->data << " ";
        v->visited = true; // mark vertex as visited
        nbr = v->neighbors; // get neighbors
        for(std::list<Vertex*> :: iterator it = nbr.begin(); it != nbr.end(); it++ )
        {
            // if neighbor not visited add to queue
            if(!(*it)->visited)
                this->vertexQueue.push(*it);
        }
    }
}
