#include <chrono>
#include <iomanip>
#include <iostream>
#include <thread>
#include "Character.h"
#include "Rooms.h"
#include "Menu.h"

const int NUM_ROOMS = 12;

void loadIntro();
void loadRooms(Room allRooms[]);
void loadRules();
Character buildCharacter(Character& player);

int main()
{
    int answer = 0;
    std::cout << "Press 1 and Enter to play intro\n"
              << "Press 2 and Enter to skip intro\n";
    std::cin >> answer;

    if (answer == 1)
    {
        loadIntro();
    }

    std::cout << "\n*******************************************\n\n"
              << "\tWELCOME TO 10 ROOMS IN HELL\n\n"
              << "*******************************************\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::string name;
    std::cout << "Enter your name: \n";
    std::cin >> name;
    Character player = Character(name);

    std::cout << "Greetings, " << name << ". Your soul looks...";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "appetizing.\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << "Press 1 and Enter for rules.\n"
              << "Press 2 and Enter to skip rules.\n";

    std::cin >> answer;
    if (answer == 1)
    {
        loadRules();

    }

    buildCharacter(player);

    Room allRooms[NUM_ROOMS];
    loadRooms(allRooms);
    Room* currentLocation = &allRooms[0];

    // Variables for gameplay
    std::string userInput = "empty";
    Direction userDirection;

    // Begins the game with the first location
    std::cout << "========================================================\n"
                 "TESTING......\n"
                 "Enter N for North, S for South, W for West, E for East\n" << std::endl;
    Room* entrancePtr = &allRooms[0];
    std::cout << entrancePtr->getRoomName()<< std::endl;
    currentLocation->visit();

    while (currentLocation->isFinalRoom() == false)
    {
        std::cin >> userInput;

        if (userInput == "N")
            userDirection = NORTH;
        else if (userInput == "S")
            userDirection = SOUTH;
        else if (userInput == "W")
            userDirection = WEST;
        else
            userDirection = EAST;
        {
            if (currentLocation->hasPath(userDirection) == false)
                continue;
            if (currentLocation->hasPath(userDirection) == true)
                currentLocation = currentLocation->getPath(userDirection);
            std::cout << currentLocation->getRoomName() << std::endl;
            currentLocation->visit();
        }
    }
    std::cout << "\nTesting complete\n" << std::endl;

    return 0;
}


//Game setup
void loadIntro()
{
    std::cout << "You awaken in a dark room.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2300));
    std::cout << std::setw(36) << "...Hello?\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2750));
    std::cout << std::setw(48) << "...Hello...?\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    std::cout << std::setw(57) << ".........\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2750));
    std::cout << std::setw(69) << "...HELLO!!!\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(900));
    std::cout << "You hears screams in the distance.\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << std::setw(47) << "...Is someone there?\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << std::setw(70) << "...What is this place?\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << std::setw(40) << "...It's so";
    std::this_thread::sleep_for(std::chrono::milliseconds(2200));
    std::cout << std::setw(10) << "...hot.\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
}

void loadRules()
{
    std::cout << "\nOBJECTIVE: \nSurvive 10 rooms in Hell.\nSurvival is based on health stat.\n\n"
              << "GAMEPLAY: \nYou will encounter objects and obstacles on your journey.\n"
              << "Objects may increase or decrease skills and health. Engage at your own risk.\n\n"
              << "YOU: \nCharacter begins with 100 health.\n\n"
              << "SKILLS:\nCharacter has 5 skills:\n"
              << "- Strength - Stamina - Perception - Persuasion - Luck\n"
              << "Player begins with 15 points to assign towards skills.\n"
              << "The higher the skill, the higher the bonus.\n"
              << "Skills in the negative may have a negative effect." << std::endl;
}

Character buildCharacter(Character &player)
{
    int strength = 0; int stamina = 0;
    int perception = 0; int persuasion = 0;
    int luck = 0;

    std::cout << "\nStart by applying points.\n";

    bool characterBuilt = false;

    while (characterBuilt != true)
    {
        int skillPtCount = 15;
        while (std::cin)
        {
            std::cout << "Enter points in strength: \n";
            std::cin >> strength;
            if (strength < 0)
                std::cout << "Cannot enter negative points. Try again.\n";
            else if (strength > 10)
                std::cout << "Cannot exceed 10 points. Try again\n";
            else
                break;
        }

        skillPtCount = skillPtCount - strength;
        std::cout << "\nPoints to use: " << skillPtCount << "\n";

        while (std::cin)
        {
            std::cout << "Enter points in stamina: \n";
            std::cin >> stamina;
            if (stamina < 0)
                std::cout << "Cannot enter negative points. Try again.\n";
            else if (stamina > 10)
                std::cout << "Cannot exceed 10 points. Try again\n";
            else
                break;
        }

        skillPtCount = skillPtCount - stamina;
        std::cout << "\nPoints to use: " << skillPtCount << "\n";

        while (std::cin)
        {
            std::cout << "Enter points in perception: \n";
            std::cin >> perception;
            if (perception < 0)
                std::cout << "Cannot enter negative points. Try again.\n";
            else if (perception > 10)
                std::cout << "Cannot exceed 10 points. Try again\n";
            else
                break;
        }

        skillPtCount = skillPtCount - perception;
        std::cout << "\nPoints to use: " << skillPtCount << "\n";

        while (std::cin)
        {
            std::cout << "Enter points in persuasion: \n";
            std::cin >> persuasion;
            if (persuasion < 0)
                std::cout << "Cannot enter negative points. Try again.\n";
            else if (persuasion > 10)
                std::cout << "Cannot exceed 10 points. Try again\n";
            else
                break;
        }

        skillPtCount = skillPtCount - persuasion;
        std::cout << "\nPoints to use: " << skillPtCount << "\n";

        while (std::cin)
        {
            std::cout << "Enter points in luck: \n";
            std::cin >> luck;
            if (luck < 0)
                std::cout << "Cannot enter negative points. Try again.\n";
            else if (luck > 10)
                std::cout << "Cannot exceed 10 points. Try again\n";
            else
                break;
        }
        skillPtCount = skillPtCount - luck;

        if (skillPtCount != 0)
        {
            std::cout << "\nMust use 15 points.\nRe-enter points.\n";
        }
        else
        {
            player.setStartingSkills(strength, stamina, perception, persuasion, luck);
            player.getSkillPoints();

            while (std::cin)
            {
                int answer;
                std::cout << "\nPress 1 and Enter to confirm.\n"
                          << "Press 2 and Enter to reset points.\n";
                std::cin >> answer;
                if (answer == 1)
                {
                    characterBuilt = true;
                    break;
                }
                else if (answer == 2)
                {
                    player.resetSkills();
                    break;
                }
                else
                    continue;
            }
        }
    }
    return player;
}

void loadRooms(Room allRooms[])
{
    allRooms[0] = Room("Entrance", false);
    allRooms[1] = Room("A", false);
    allRooms[2] = Room("B", false);
    allRooms[3] = Room("C", false);
    allRooms[4] = Room("D", false);
    allRooms[5] = Room("E", false);
    allRooms[6] = Room("F", false);
    allRooms[7] = Room("G", false);
    allRooms[8] = Room("H", false);
    allRooms[9] = Room("I", false);
    allRooms[10] = Room("J", false);
    allRooms[11] = Room("Exit", true);

    allRooms[0].setPath(WEST, &allRooms[2]);
    allRooms[0].setPath(SOUTH, &allRooms[4]);
    allRooms[0].setPath(EAST, &allRooms[3]);
    allRooms[1].setPath(EAST, &allRooms[2]);
    allRooms[2].setPath(WEST, &allRooms[1]);
    allRooms[2].setPath(EAST, &allRooms[0]);
    allRooms[3].setPath(WEST, &allRooms[0]);
    allRooms[3].setPath(SOUTH, &allRooms[5]);
    allRooms[4].setPath(NORTH, &allRooms[0]);
    allRooms[4].setPath(EAST, &allRooms[5]);
    allRooms[4].setPath(SOUTH, &allRooms[7]);
    allRooms[5].setPath(NORTH, &allRooms[3]);
    allRooms[5].setPath(WEST, &allRooms[4]);
    allRooms[5].setPath(SOUTH, &allRooms[8]);
    allRooms[6].setPath(EAST, &allRooms[7]);
    allRooms[6].setPath(SOUTH, &allRooms[9]);
    allRooms[7].setPath(NORTH, &allRooms[4]);
    allRooms[7].setPath(EAST, &allRooms[8]);
    allRooms[7].setPath(SOUTH, &allRooms[10]);
    allRooms[7].setPath(WEST, &allRooms[6]);
    allRooms[8].setPath(NORTH, &allRooms[5]);
    allRooms[8].setPath(WEST, &allRooms[7]);
    allRooms[9].setPath(NORTH, &allRooms[6]);
    allRooms[9].setPath(EAST, &allRooms[10]);
    allRooms[10].setPath(NORTH, &allRooms[7]);
    allRooms[10].setPath(WEST, &allRooms[9]);
    allRooms[10].setPath(SOUTH, &allRooms[11]);
    allRooms[11].setPath(NORTH, &allRooms[10]);
}
