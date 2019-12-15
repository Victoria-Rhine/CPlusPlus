#include <iostream>
#include <climits>
#include <stack>
#include "TSP.h"

using namespace std;


//prims helper function to find next smallest key not yet in the MST
int smallestKey(vector<int> keys, vector<bool> inMST){
    int min = INT_MAX;
    int index;

    for(int i = 0; i < keys.size(); i++){
        if(!(inMST.at(i)) && keys.at(i) < min){
            min = keys.at(i);
            index = i;
        }
    }
    return index;
}

std::vector<int> prims(std::vector<std::vector<int>> graph){
    int numVert = graph.size();

    //vector of predecessors which will actually contain the MST
    vector<int> predecessor(numVert, -1);   //initialize all to -1

    //vector if weight key values for each vertex
    vector<int> keys(numVert, INT_MAX);     //initialize all to infinity

    //vector that tracks if a vertex is included in the MST yet
    vector<bool> inMST(numVert, false);     //initialize all to false


    //use vertex 0 as start vertex in algorithm
    keys.at(0) = 0;

    for(int i = 0; i < numVert; i++){
        int currentVert = smallestKey(keys, inMST);
        inMST.at(currentVert) = true;

        for(int nextVert = 0; nextVert < numVert; nextVert++){
            //if adjacent, not in MST, and edge weight is less than key
            if(graph[currentVert][nextVert] && !(inMST[nextVert])
                    && graph[currentVert][nextVert] < keys[nextVert]){
                predecessor[nextVert] = currentVert;
                keys[nextVert] = graph[currentVert][nextVert];
            }
        }
    }
    return predecessor;
}


DFSgraph::DFSgraph(unsigned int numVertices){
    numVert = numVertices;
    vertex temp;
    for(unsigned int i = 0; i < numVertices; i++){
        //add a vertex to list of vertices
        vertices.push_back(temp);
        //fill out adjacency matrix with zeroes
        adjMatrix.push_back(std::vector<int>(numVertices, 0));
    }
}

void DFSgraph::addEdge(unsigned int a, unsigned int b){
    if(a >= numVert || b >= numVert){
        std::cout << "ERROR: vertex does not exist, no edge added \n";
        return;
    }
    adjMatrix[a][b] = 1;
    adjMatrix[b][a] = 1;
}

void DFSgraph::DFS(unsigned int start){
    //check if start index is in range
    if(start >= numVert){
        std::cout << "ERROR: This start index does not exist\n";
        return;
    }
    //mark start vertex as visited and distance to 0
    vertices.at(start).visit = true;
    vertices.at(start).distance = 0;

    //create stack to hold index of each queued vertex
    std::stack<int> stack;
    stack.push(start);

    //index of current vertex
    int current;
    while(!stack.empty()){
        //pop next vertex in stack
        current = stack.top();
        stack.pop();

        //print vertex
        std::cout << current << " ";

        for(unsigned int j = 0; j < numVert; j++){
            //if vertex is adjacent and not visited
            if(adjMatrix[current][j] == 1 && !(vertices.at(j).visit)){
                vertices.at(j).visit = true;
                vertices.at(j).distance = vertices.at(current).distance + 1;
                vertices.at(j).predecessor = current;
                stack.push(j);
            }
        }
    }
    //print start to close the traversal into a loop
    std::cout << start << std::endl;
}


void travelSalesmanApprox(std::vector<std::vector<int> > graph){
    vector<int> mst = prims(graph);
    //use the vector of MST to create a DFSgraph
    DFSgraph tree(mst.size());
    for(unsigned int i = 1; i < mst.size(); i++){
        tree.addEdge( i, mst.at(i) );
    }

    cout << "Approximately optimal route for travelling salesman:" << endl;
    //depth first search will give the travelling salesman tour
    tree.DFS(0);

}





