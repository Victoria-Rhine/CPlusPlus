#include <iostream>
#include "TSP.h"

using namespace std;

int main()
{
    //A 2-D vector representing an example graph
    vector<vector<int>> graph(5);
    graph.at(0) = {0,5,8,9,3};
    graph.at(1) = {5,0,7,2,4};
    graph.at(2) = {8,7,0,13,11};
    graph.at(3) = {9,2,13,0,6};
    graph.at(4) = {3,4,11,6,0};

    travelSalesmanApprox(graph);


    return 0;
}
