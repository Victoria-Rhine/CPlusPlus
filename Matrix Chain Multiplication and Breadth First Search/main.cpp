#include "breadthfirstsearch.h"
#include "mcmdynamic.h"

int main()
{
    // MCM using DP
    std::cout << "Matrix Chain multiplication using dynamic programming:\n";
    int array[] = {30, 4, 8, 5, 10, 25, 15};
    int n = sizeof(array)/sizeof(array[0]);
    matrixChainOrder(array, n);
    std::cout << "------------------------------------------------------\n";

    // MCM with memoization
    std::cout << "Matrix Chain multiplication with memoization:\n"
              << "Optimal Cost Is: " << matrixChainOrderMem(array);
    std::cout << "\n------------------------------------------------------\n";

    // BFS on adjacency matrix
    std::cout << "Breadth first search on adjacency matrix:\n";
    node vertices[NODE];
    node start;
    char s = 'A';
    start.value = s - 'A';

    for(int i = 0; i < NODE; i++)
        vertices[i].value = i;

    std::cout << "BFS Traversal: ";
    BFSMatrix(vertices, start);
    std::cout << "\n------------------------------------------------------\n";

    // BFS on adjacency list
    // assigning vertices
    Vertex v0('A'), v1('B') ,v2('C'), v3('D'), v4('E'), v5('F'), v6('G'), v7('H'),
            v8('I'), v9('J'), v10('K'), v11('L'), v12('M'), v13('N');

    // adding connected edges
    v0.addNeighbor(&v1);   // a,b
    v0.addNeighbor(&v3);   // a,d
    v1.addNeighbor(&v2);   // b,c
    v2.addNeighbor(&v12);  // c,m
    v2.addNeighbor(&v13);  // c,n
    v3.addNeighbor(&v4);   // d,e
    v3.addNeighbor(&v5);   // d,f
    v3.addNeighbor(&v6);   // d,g
    v3.addNeighbor(&v13);  // d,n
    v4.addNeighbor(&v5);   // e,f
    v5.addNeighbor(&v7);   // f,h
    v6.addNeighbor(&v7);   // g,h
    v6.addNeighbor(&v9);   // g,j
    v7.addNeighbor(&v8);   // h,i
    v7.addNeighbor(&v10);  // h,k
    v8.addNeighbor(&v9);   // i,j
    v9.addNeighbor(&v10);  // j,k
    v9.addNeighbor(&v13);  // j,n
    v10.addNeighbor(&v11); // k,l
    v11.addNeighbor(&v12); // l,m
    v12.addNeighbor(&v13); // m,n

    BFS myList;
    myList.BFSList(&v0);
    std::cout << "\n------------------------------------------------------\n";

    return 0;
}
