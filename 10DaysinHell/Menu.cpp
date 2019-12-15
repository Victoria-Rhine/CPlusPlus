#include "Menu.h"
#include <iostream>
#include <chrono>
#include <thread>

void Menu::loadIntro()
{
    std::cout << "You awake in a dark room..." << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    std::cout     << "\t...Hello?" << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    std::cout     << "\t\t...Hello...?" << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout     << "\t\t\t......" << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout     << "\t\t\t\t......" << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2500));
    std::cout     << "\t\t\t\t\tHELLO!!!" << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout     << "You hears screams in the distance." << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout     << "\t...Is anyone there?" << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout     << "\t\tWhat is this place?" << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout     << "\t\t\tIt's so..." << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout     << "\t\t\t\t  hot." << "\n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    std::cout << "\n*****************************\n"
              << "WELCOME TO 10 ROOMS IN HELL\n"
              << "*****************************\n";
}
