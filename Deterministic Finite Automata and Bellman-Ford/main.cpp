#include <iostream>
#include <vector>
#include <iomanip>
#include <climits>

// function for DFA
void DFA(std::string Q[], std::string input)
{
    // Q = { "s", "q1", "q2", "r1", "r2" }
    std::string currState = Q[0]; // s is start state

    // check for empty string
    if (input.size() == 0)
        std::cout << "Input is empty string." << std::endl;

    if (input.size() != 0) // if not an empty string
    {
        // print where we start
        std::cout << "Input " << input << ".\nStarting at " << Q[0] << std::endl;

        // counter for traversing string
        unsigned int i = 0;

        do
        {
            if (currState == Q[0] && i < input.size()) // if at start state and within string
            {
                if (input.at(i) == 'a')
                {
                    currState = Q[1]; // a moves to q1
                    std::cout << "State is now " << currState << std::endl; // print new state
                    i++; // move to next letter
                }
                else
                {
                    currState = Q[3]; // b moves to r1
                    std::cout << "State is now " << currState << std::endl; // print new state
                    i++; // move to next letter
                }
            }

            if (currState == Q[1] && i < input.size()) // if at q1 and within string
            {
                if (input.at(i) == 'a')
                {
                    // a stays at q1
                    std::cout << "State is now " << currState << std::endl; // print new state
                    i++; // move to next letter
                }
                else
                {
                    currState = Q[2]; // b moves to q2
                    std::cout << "State is now " << currState << std::endl; // print new state
                    i++; // move to next letter
                }
            }

            if (currState == Q[2] && i < input.size()) // if at q2 and within string
            {
                if (input.at(i) == 'a')
                {
                    currState = Q[1]; // a moves to q1
                    std::cout << "State is now " << currState << std::endl; // print new state
                    i++; // move to next letter
                }
                else
                {
                    // b stays at q2
                    std::cout << "State is now " << currState << std::endl; // print new state
                    i++; // move to next letter
                }
            }

            if (currState == Q[3] && i < input.size()) // if at r1 and within string
            {
                if (input.at(i) == 'a')
                {
                    currState = Q[4]; // a moves to r2
                    std::cout << "State is now " << currState << std::endl; // print new state
                    i++; // move to next letter
                }
                else
                {
                    // b stays at r1
                    std::cout << "State is now " << currState << std::endl; // print new state
                    i++; // move to next letter
                }
            }

            if (currState == Q[4] && i < input.size()) // if at r2 and within string
            {
                if (input.at(i) == 'a')
                {
                    // a stays at r2
                    std::cout << "State is now " << currState << std::endl; // print new state
                    i++; // move to next letter
                }
                else
                {
                    currState = Q[3]; // b moves to r1
                    std::cout << "State is now " << currState << std::endl; // print new state
                    i++; // move to next letter
                }
            }
        }
        while (i < input.size());

        // check if we are at accept state
        if (currState == Q[1] || currState == Q[3])
            std::cout << "String accepted at " << currState <<  ".\n" << std::endl;
        else
            std::cout << "String not accepted at " << currState << ".\n" << std::endl;
    }
}

// Beginning Bellman Ford section
// vertex holds char and number
struct Vertex
{
    char letter;
    unsigned int vertNum;
};

struct Vertex* createVertex(char l, unsigned int n)
{
    struct Vertex* vertex = new Vertex;
    vertex->letter = l;
    vertex->vertNum = n;
    return vertex;
};

// a structure to represent a weighted edge in graph
struct Edge
{
    Vertex src;
    Vertex dest;
    int weight;
};

// a structure to hold predecessors
struct Parent
{
    char letter;
    int vertNum;
};

struct Parent* createParent(char l, int n)
{
    struct Parent* parent = new Parent;
    parent->letter = l;
    parent->vertNum = n;
    return parent;
};


// recursively print path of given vertex v from source vertex
void printPath(std::vector<Parent> const &parent, int v)
{
    if (v < 0)
        return;

    printPath(parent, parent[v].vertNum);
    std::cout << parent[v].letter << " ";
}

// function to run Bellman Ford Algorithm from given source
void BellmanFord(std::vector<Edge> const &edges, struct Vertex* source, int N)
{
    // number of edges present in the graph
    int E = 21;

    // distance[] and parent stores shortest-path (least cost/path)
    // initially all vertices except source vertex have weight of infinity and no parent

    std::vector<int> distance (N, INT_MAX);
    distance[source->vertNum] = 0;

    // setting up parent vector
    std::vector<Parent> parent =
    { {' ', -1}, {' ', -1}, {' ', -1}, {' ', -1}, {' ', -1}, {' ', -1}, {' ', -1},
      {' ', -1}, {' ', -1}, {' ', -1}, {' ', -1}, {' ', -1}, {' ', -1}, {' ', -1}};

    int u, v, w;
    int k = N;

    // relaxation step (run V-1 times)
    while (--k)
    {
        for (int j = 0; j < E; j++)
        {
            // edge from u to v having weight w
            u = edges[j].src.vertNum;
            v = edges[j].dest.vertNum;
            w = edges[j].weight;

            // if the distance to the destination v can be
            // shortened by taking the edge u -> v
            if (distance[u] != INT_MAX && distance[u] + w < distance[v])
            {
                // update distance to the new lower value
                distance[v] = distance[u] + w;

                // set v's parent as u
                parent[v].vertNum = u;
                parent[v].letter = edges[j].src.letter;
            }
        }
    }

    // run relaxation step once more for Nth time to check for negative-weight cycles
    for (int i = 0; i < E; i++)
    {
        // edge from u to v having weight w
        u = edges[i].src.vertNum;
        v = edges[i].dest.vertNum;
        w = edges[i].weight;

        // if the distance to the destination u can be shortened by taking the edge u-> v
        if (distance[static_cast<unsigned long long>(u)] != INT_MAX &&
                distance[static_cast<unsigned long long>(u)] + w < distance[static_cast<unsigned long long>(v)])
        {
            std::cout << "Negative Weight Cycle Found!!";
            return;
        }
    }

    // print costs and predecessors
    char label = 'a';
    for (int i = 0; i < N; i++)
    {
        std::cout << "Vertex " << label << " from source is distance: "
                  << distance[static_cast<unsigned long long>(i)] << ".\nPredecessors: ";
        printPath(parent,i); std::cout << "\n\n";
        label++;
    }
}

int main()
{
    // PART 1 DFA
    // states for DFA
    std::string Q[5] = { "s", "q1", "q2", "r1", "r2" };

    // test strings
    DFA(Q, "ababa");
    DFA(Q, "baba");
    DFA(Q, "aababaab");
    DFA(Q, "babaabaaabb");
    DFA(Q, "");

    std::cout << "\n" << std::endl;

    // PART 2 BELLMAN FORD
    // build verticies
    struct Vertex* a = createVertex('a', 0);
    struct Vertex* b = createVertex('b', 1);
    struct Vertex* c = createVertex('c', 2);
    struct Vertex* d = createVertex('d', 3);
    struct Vertex* e = createVertex('e', 4);
    struct Vertex* f = createVertex('f', 5);
    struct Vertex* g = createVertex('g', 6);
    struct Vertex* h = createVertex('h', 7);
    struct Vertex* i = createVertex('i', 8);
    struct Vertex* j = createVertex('j', 9);
    struct Vertex* k = createVertex('k', 10);
    struct Vertex* l = createVertex('l', 11);
    struct Vertex* m = createVertex('m', 12);
    struct Vertex* n = createVertex('n', 13);

    // build edges
    std::vector<Edge> edges =
    {
        // (x, y, w) -> edge from x to y having weight w
        { *a, *d, 3 }, { *b, *a, -2 }, { *c, *b, 1 }, { *c, *n, -3 },
        { *c, *m, 3 }, { *d, *e, 2 }, { *d, *f, 6 }, { *d, *g, -1 },
        { *d, *n, -1 }, { *e, *f, 3 }, { *f, *h, -2 }, { *g, *h, 1 },
        { *g, *j, 3 }, { *h, *k, -1 }, { *i, *h, -4 }, { *j, *i, 2 },
        { *j, *k, 3 }, { *l, *k, 2 }, { *m, *l, -4 }, { *n, *m, 8 }, { *n, *j, 5 }
    };

    // set number of verticies in the graph
    int N = 14;

    // run Bellman Ford Algorithm from given source
    BellmanFord(edges, a, N);

    return 0;
}

