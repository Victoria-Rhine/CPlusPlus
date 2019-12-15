#include "Character.h"

#include <iostream>

Character::Character(std::string playerName)
{
    name = playerName;
    health = 100;
    strength = 0;
    stamina = 0;
    perception = 0;
    persuasion = 0;
    luck = 0;
    skillPoints = 15;
}

void Character::setStartingSkills(int strPts, int staPts, int percPts, int persPts, int luckPts)
{
    while (strPts > 0)
    {
        plusStrength();
        strPts--;
        skillPoints--;
    }
    while (staPts > 0)
    {
        plusStamina();
        staPts--;
        skillPoints--;
    }
    while (percPts > 0)
    {
        plusPerception();
        percPts--;
        skillPoints--;
    }
    while (persPts > 0)
    {
        plusPersuasion();
        persPts--;
        skillPoints--;
    }
    while (luckPts > 0)
    {
        plusLuck();
        luckPts--;
        skillPoints--;
    }
}

void Character::resetSkills()
{
    strength = 0;
    stamina = 0;
    perception = 0;
    persuasion = 0;
    luck = 0;
}

void Character::getSkillPoints()
{
    std::cout << "\nCharacter stats:"
              << "\nStrength: " << strength
              << "\nStamina: " << stamina
              << "\nPerception: " << perception
              << "\nPersuasion: " << persuasion
              << "\nLuck: " << luck << std::endl;
}

void Character::plusStrength()
{
    strength++;
}

void Character::plusStamina()
{
    stamina++;
}
void Character::plusPerception()
{
    perception++;
}

void Character::plusPersuasion()
{
    persuasion++;
}

void Character::plusLuck()
{
    luck++;
}

void Character::minusStrength()
{
    strength--;
}

void Character::minusStamina()
{
    stamina--;
}

void Character::minusPerception()
{
    perception--;
}

void Character::minusPersuasion()
{
    persuasion--;
}

void Character::minusLuck()
{
    luck--;
}
