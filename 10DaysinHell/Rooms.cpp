#include "Rooms.h"

#include <iostream>


Room::Room()
{
    name = "?";
    visited = false;
    exit = false;
}

Room::Room(std::string roomName, bool isFinalRoom)
{
    name = roomName;
    visited = false;
    exit = isFinalRoom;
}

std::string Room::getRoomName() const
{
    return name;
}

void Room::getRoomDescription() const
{
    // FIX ME
    std::cout << "Room descriptions" << std::endl;
}

bool Room::hasPath(Direction direction)
{
    if (path[direction] != nullptr)
        return true;
    else
        return false;
}

Room* Room::getPath(Direction direction) const
{
    if (path[direction] != nullptr)
        return path[direction];
    else
        return nullptr;
}

void Room::setPath(Direction direction, Room* pathLocation)
{
    path[direction] = pathLocation;
}

bool Room::isFinalRoom() const
{
    if (exit == true)
        return true;
    else
        return false;
}

void Room::visit()
{
    visited = true;
}

bool Room::isVisited()
{
    return visited;
}
