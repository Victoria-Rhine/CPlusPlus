#ifndef ROOMS_H
#define ROOMS_H

#include <string>

enum Direction
{
    NORTH, EAST, SOUTH, WEST
};

class Room
{
private:
    std::string name;
    bool visited;
    bool exit;
    Room* path[4] = {nullptr};

public:
    Room();
    Room(std::string roomName, bool isFinalRoom);

    std::string getRoomName() const;
    void getRoomDescription() const;

    bool hasPath(Direction direction);
    Room* getPath(Direction direction) const;
    void setPath(Direction direction, Room* pathLocation);

    bool isFinalRoom() const;

    void visit();
    bool isVisited();
};
#endif // ROOMS_H
