#include <iostream>
#include <cstdlib>
#include <chrono>
#include "Player.h"
#include "Enemy.h"
#include "colormod.h"
using namespace std::literals::chrono_literals;

void printASCII(std::string);

void sleep(std::chrono::duration<int>);
void getEnemyStats(Enemy*);
void checkAlive(Enemy*);
void moveForward();
void gameStart();