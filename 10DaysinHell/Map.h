#ifndef MAP_H
#define MAP_H

#include <string>

enum Direction
{
    NORTH, EAST, SOUTH, WEST
};

class Map
{
private:
    std::string name;
    bool visited;
    bool exit;
    Map* neighbors[4] = {nullptr};

public:
    Map();
    Map(std::string roomName, bool isFinalRoom);

    std::string getRoomName() const;
    std::string getDescription() const;

    /**
     * @brief hasNeighbor determines if location has neighbor at given direction
     * @param dir takes in a direction
     * @return returns true if there is a neighbor, false if there is not a neighbor
     */
    bool hasNeighbor(Direction dir);

    /**
     * @brief getNeighbor determines the neighbor at given direction
     * @param dir takes in a direction
     * @return returns point to neighbor if it exists, nullptr if does not exist
     */
    Location* getNeighbor(Direction dir) const;

    /**
     * @brief setNeighbor assigns a neighbor to a location
     * @param dir takes in a direction
     * @param neighborLoc takes in the address of neighbor
     */
    void setNeighbor(Direction dir, Location* neighborLoc);

    /**
     * @brief isExit determines if location contains exit
     * @return returns true if there is an exit, false if there is not an exit
     */
    bool isExit() const;

    /**
     * @brief visit visits a location
     */
    void visit();

    /**
     * @brief isVisited determines if location is previously visited
     * @return returns true if visited, false if not visited
     */
    bool isVisited();
};

#endif // MAP_H
