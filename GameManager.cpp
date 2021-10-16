#include "GameManager.h"
#include "Levels/LevelOne.h"
#include "Levels/LevelTwo.h"
#include "Levels/LevelThree.h"
#include "Levels/LevelFour.h"
#include "Levels/LevelFive.h"
#include "Levels/LevelSix.h"
#include <thread>
#include <string>
#include <fstream>


void sleep(std::chrono::duration<int> time)
{
  std::this_thread::sleep_for(time);
}


void printASCII(std::string fileName)
{
  std::string line = "";
  std::ifstream file;

  file.open(fileName);
  if(file.is_open())
  {
    while(getline(file, line))
    {
      std::cout << line << std::endl;
    }
  }

  file.close();
}


void getEnemyStats(Enemy* enemy)
{
  if(enemy->getEnemyHealth() < 0) 
  {
    enemy->setEnemyHealth(0);
  }
  std::cout << red << enemy->getEnemyName() << " : Health = " << enemy->getEnemyHealth() << std::endl;
}


void checkAlive(Enemy* enemy)
{
  if(!(enemy->getEnemyHealth() <= 0 ))
  {
    enemy->randomizeEnemyDamage();
  }
  else
  {
    enemy->setEnemyDamage(0);
  }
}


void moveForward()
{
  while(true)
  {
    std::cout << green << "Press 'F' to move forward...  ";
    std::string input;
    std::cin >> input;
    if(!(input == "F" || input == "f" ))
    {
      std::cout << red << "Opps! You are heading in wrong direction" << std::endl << std::endl;
    }
    else break;
  }
}


void welecomeMessage()
{
  system("clear");
  std::cout << "\e[2J\e[H";
  std::cout << blue;
  printASCII("TextFiles/TitleCharacter.txt"); std::cout << blue;
  printASCII("TextFiles/WelecomeTitle.txt"); 
  printASCII("TextFiles/WelecomeText.txt");
  
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


std::string playerCredentials()
{
  char name[50];
  std::cout << "\e[2J\e[H" << def << "Enter your name: " << green;
  std::cin >> name;
  return (std::string)name;
}


void instructions(std::string name)
{
  using namespace std::literals::chrono_literals;

  std::cout << "\e[2J\e[H" << def; 
  system("clear");
  printASCII("TextFiles/Map.txt"); sleep(1s);
  std::cout << blue << "Hi " << name + "," << std::endl << std::endl; sleep(2s);
  std::cout << blue << "Welcome To 'Eldkinane', The Land Of The Golden Egales!" << std::endl ; sleep(2s);
  std::cout << "Our land is captured by a monster named 'Murlocs' and we need your help to get back our land." << std::endl; sleep(2s);
  std::cout << "To reach their you have to cross 5 territories of Eldkinane which are full of monsters." << std::endl; sleep(2s);
  std::cout << "You will need sword, shield, armour and bow to defeat Murlocs." << std::endl << std::endl; sleep(2s);
  std::cout << "Good luck to the finest warrior we have ever known!" << std::endl << std::endl<< std::endl; sleep(2s);

  std::cout << green << "Press Enter To Begin The Journey... ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
}


void gameStart()
{
  welecomeMessage();
  std::string name = playerCredentials();
  instructions(name);

  Player* player = new Player(name, "Eldkinane", 200, 20);

  startLevelOne(name);
  levelOneBattle(player);

  startLevelTwo(name);
  levelTwoBattle(player);

  startLevelThree(name);
  levelThreeBattle(player);

  startLevelFour(name);
  levelFourBattle(player);

  startLevelFive(name);
  levelFiveBattle(player);

  startLevelSix(name);
  levelSixBattle(player);

  delete player;
}
