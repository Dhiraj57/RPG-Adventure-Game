#include "../GameManager.h"

void showStats(Player* player, Enemy* enemy1, Enemy* enemy2)
{
  if(player->getPlayerHealth() < 0) 
  {
    player->setPlayerHealth(0);
  }
  std::cout << blue << player->getPlayerName() + " : Health = " << player->getPlayerHealth() << std::endl;

  getEnemyStats(enemy1);
  getEnemyStats(enemy2);

}


void levelTwoInstructions(std::string name)
{
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/Redlords.txt"); sleep(1s);
  std::cout << blue << "Great work " + name + "," << std::endl << std::endl; sleep(2s);
  std::cout << "You Have Now Reached To 'Redlords', The field of Red Swords!" << std::endl; sleep(2s);
  std::cout << "Here you can get the 'Sword' you needed to defeat Murlocs."  << std::endl; sleep(2s);
  std::cout << "But to get that sword you have to defeat the monsters who are guarding that sword." << std::endl << std::endl << std::endl; sleep(0s);
}


void startLevelTwo(std::string name)
{
  levelTwoInstructions(name);
  moveForward();

  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/Monster2.txt"); sleep(1s);
  std::cout << blue << "Hurrah! You found the Sword, but you have to defeat those monsters to get that sword." << std::endl << std::endl; sleep(2s);
  
  while(true)
  {
    std::cout << green << "Press 'B' to battle with monster... " ;
    std::string input;
    std::cin >> input;
    if(!(input == "B" || input == "b"))
    {
      std::cout << red << "Hey Warrior, it's time to show your Bravery!" << std::endl << std::endl;
    }
    else break;
  }
}


void attack(Player* player, Enemy* enemy1, Enemy* enemy2)
{
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Attack :" << std::endl;
  player->randomizeRangedDamage();
  checkAlive(enemy1);
  checkAlive(enemy2);

  switch(rand() % 2)
  {
    case 0:
      if((enemy1->getEnemyHealth() <= 0 )) {}
      else
      {
        enemy1->setEnemyHealth(enemy1->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
        break;
      }
      
    case 1:
      enemy2->setEnemyHealth(enemy2->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
      break;
  }
  player->setPlayerHealth(player->getPlayerHealth() - (enemy1->getEnemyDamage() + enemy2->getEnemyDamage()));

  showStats(player, enemy1, enemy2);
  std::cout << std::endl << blue << player->getPlayerName() + " : Damage Given = " << player->getMeleeDamage() + player->getRangedDamage() << std::endl;
  std::cout << red << enemy1->getEnemyName() << " : Damage Given = " << enemy1->getEnemyDamage() << std::endl;
  std::cout << red << enemy2->getEnemyName() << " : Damage Given = " << enemy2->getEnemyDamage() << std::endl;
}


void block(Player* player, Enemy* enemy1, Enemy* enemy2)
{
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Defend :" << std::endl;
  showStats(player, enemy1, enemy2);
  
  std::cout << std::endl << blue << player->getPlayerName() + " : Damage Given = 0" << std::endl;
  std::cout << red << enemy1->getEnemyName() << " : Damage Given = 0" << std::endl;
  std::cout << red << enemy2->getEnemyName() << " : Damage Given = 0" << std::endl;
}


void levelTwoBattle(Player* player)
{
  Enemy* enemy1 = new Enemy("Gravel", normalEnemy, 30, 5);
  Enemy* enemy2 = new Enemy("Daedra", normalEnemy, 30, 5);

  std::string input; 
  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Get Ready Warrior!" << std::endl;
  showStats(player, enemy1, enemy2);
  
  while(true)
  {
    if(enemy1->getEnemyHealth() <= 0 && enemy2->getEnemyHealth() <= 0) break; 
    if(player->getPlayerHealth() <= 0) 
    {
      std::cout << std::endl << std::endl << red << "Opps! You Lost The Battle!" << std::endl;
      std::cout << "Try Again!" << std::endl; 
      exit(1);
    }
    sleep(2s);

    switch(rand() % 3)
    {
      case 0:
        attack(player, enemy1, enemy2);
        break;
      case 1:
        block(player, enemy1, enemy2);
        break;
      default:
        attack(player, enemy1, enemy2);
        break;
    }
  }

  std::cout << std::endl << std::endl << blue << "!! Hurrah, You Won The Battle !!" << std::endl <<std::endl;
  std::cout << green << "Press Enter To Continue... ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  std::cout << "\e[2J\e[H" << def;
  system("clear");
  printASCII("TextFiles/Sword.txt"); sleep(1s);
  std::cout << blue << "Well done " + player->getPlayerName() + "," << std::endl << std::endl; sleep(2s);
  std::cout << "You have recaptured Redlords. Now you have the sword to defeat Murlocs." << std::endl; sleep(2s);
  std::cout << "Also a special ability is unlocked - Critical hit.(performs attack with massive damage)." << std::endl; sleep(2s);
  std::cout << "Two down, four more to go. Good luck warrior!" << std::endl<< std::endl; sleep(2s);
  moveForward();
  
  delete enemy1;
  delete enemy2;
}
