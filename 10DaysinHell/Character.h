#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character
{
public:
    //initiate characters
    Character(std::string playerName);

    //initiate starting skill points
    void setStartingSkills(int strPts, int staPts, int percPts, int persPts, int luckPts);

    //set all skills to zero
    void resetSkills();

    //return skill points
    void getSkillPoints();

    //add skill point
    void plusStrength();
    void plusStamina();
    void plusPerception();
    void plusPersuasion();
    void plusLuck();

    //remove skill point
    void minusStrength();
    void minusStamina();
    void minusPerception();
    void minusPersuasion();
    void minusLuck();

private:
    std::string name;

    int health;
    int strength;
    int stamina;
    int perception;
    int persuasion;
    int luck;

    int skillPoints;
};

#endif // CHARACTER_H
