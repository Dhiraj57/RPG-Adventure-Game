#include "../GameManager.h"

void showStats(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3)
{
  if(player->getPlayerHealth() < 0) 
  {
    player->setPlayerHealth(0);
  }
  std::cout << blue << player->getPlayerName() + " : Health = " << player->getPlayerHealth() << std::endl;

  getEnemyStats(enemy1);
  getEnemyStats(enemy2);
  getEnemyStats(enemy3);

}


void levelThreeInstructions(std::string name)
{
  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/Prilubean.txt"); sleep(1s);
  std::cout << blue << "Great work " + name + "," << std::endl << std::endl; sleep(2s);
  std::cout << "You Have Now Reached To 'Prilubean', The Cloudy Ocean!" << std::endl; sleep(2s);
  std::cout << "Here you can get the 'Shield' you needed to defeat Murlocs."  << std::endl; sleep(2s);
  std::cout << "But to get that shield you have to defeat the monsters who are guarding that shield." << std::endl << std::endl << std::endl; sleep(2s);
}


void startLevelThree(std::string name)
{
  levelThreeInstructions(name);
  moveForward();

  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/Monster3.txt"); sleep(1s);
  std::cout << blue << "Hurrah! You found the Shield, but you have to defeat those monsters to get that shield." << std::endl << std::endl; sleep(2s);
  
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


void attack(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3)
{
  bool specialAbilityUsed = false;

  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Attack :" << std::endl;

  switch(rand() % 9)
  {
    case 0:
      player->setMeleeDamage(player->getMeleeDamage() * 2);
      std::cout << blue << "Special Ability Used : Critical Hit" << std::endl;
      specialAbilityUsed = true;
      break;

    default:
      player->randomizeRangedDamage();
      break;
  }

  checkAlive(enemy1);
  checkAlive(enemy2);
  checkAlive(enemy3);

  switch(rand() % 3)
  {
    case 0:
      if((enemy1->getEnemyHealth() <= 0 )) {}
      else
      {
        enemy1->setEnemyHealth(enemy1->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
        break;
      }
      
    case 1:
      if((enemy2->getEnemyHealth() <= 0 )) {}
      else
      {
        enemy2->setEnemyHealth(enemy2->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
        break;
      }

    case 2:
      if((enemy3->getEnemyHealth() <= 0 )) {}
      else
      {
        enemy3->setEnemyHealth(enemy3->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
        break;
      }

    default:
      enemy1->setEnemyHealth(enemy1->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
      break;

  }
  player->setPlayerHealth(player->getPlayerHealth() - (enemy1->getEnemyDamage() + enemy2->getEnemyDamage() + enemy3->getEnemyDamage()));

  showStats(player, enemy1, enemy2, enemy3);
  std::cout << blue << std::endl << player->getPlayerName() + " : Damage Given = " << player->getMeleeDamage() + player->getRangedDamage() << std::endl;

  if(specialAbilityUsed)
  {
    player->setMeleeDamage(player->getMeleeDamage() / 2);
    specialAbilityUsed = false;
  }

  std::cout << red << enemy1->getEnemyName() << " : Damage Given = " << enemy1->getEnemyDamage() << std::endl;
  std::cout  << enemy2->getEnemyName() << " : Damage Given = " << enemy2->getEnemyDamage() << std::endl;
  std::cout  << enemy3->getEnemyName() << " : Damage Given = " << enemy3->getEnemyDamage() << std::endl;
}

void block(Player* player, Enemy* enemy1, Enemy* enemy2, Enemy* enemy3)
{
  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Defend :" << std::endl;
  showStats(player, enemy1, enemy2, enemy3);
  
  std::cout << blue << std::endl << player->getPlayerName() + " : Damage Given = 0" << std::endl;
  std::cout << red << enemy1->getEnemyName() << " : Damage Given = 0" << std::endl;
  std::cout << enemy2->getEnemyName() << " : Damage Given = 0" << std::endl;
  std::cout << enemy3->getEnemyName() << " : Damage Given = 0" << std::endl;
}


void levelThreeBattle(Player* player)
{
  Enemy* enemy1 = new Enemy("Gravel", normalEnemy, 30, 5);
  Enemy* enemy2 = new Enemy("Daedra", normalEnemy, 30, 5);
  Enemy* enemy3 = new Enemy("Vandal", normalEnemy, 30, 5);

  std::string input; 
  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Get Ready Warrior!" << std::endl;
  showStats(player, enemy1, enemy2, enemy3);
  
  while(true)
  {
    if(enemy1->getEnemyHealth() <= 0 && enemy2->getEnemyHealth() <= 0 && enemy3->getEnemyHealth() <= 0) break; 
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
        attack(player, enemy1, enemy2, enemy3);
        break;
      case 1:
        block(player, enemy1, enemy2, enemy3);
        break;
      default:
        attack(player, enemy1, enemy2, enemy3);
        break;
    }
  }

  std::cout << std::endl << std::endl << blue << "!! Hurrah, You Won The Battle !!" << std::endl << std::endl;
  std::cout << green << "Press Enter To Continue... ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/Shield.txt"); sleep(1s);
  std::cout << blue << "Well done " + player->getPlayerName() + "," << std::endl << std::endl; sleep(2s);
  std::cout << "You have recaptured Prilubean. Now you have the shield to defeat Murlocs." << std::endl; sleep(2s);
  std::cout << "Also a special ability is unlocked - Blocker (will get 0 damage on enemy hit)." << std::endl; sleep(2s);
  std::cout << "Three down, three more to go. Good luck warrior!" << std::endl<< std::endl; sleep(2s);
  moveForward();
  
  delete enemy1;
  delete enemy2;
  delete enemy3;
}
