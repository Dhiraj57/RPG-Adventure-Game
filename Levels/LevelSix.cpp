#include "../GameManager.h"

void showStats(Enemy* enemy, Player* player)
{
  if(player->getPlayerHealth() < 0) 
  {
    player->setPlayerHealth(0);
  }
  std::cout << blue << player->getPlayerName() + " : Health = " << player->getPlayerHealth() << std::endl;

  getEnemyStats(enemy);
}


void levelSixInstructions(std::string name)
{
  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/Oryn.txt"); sleep(1s);
  std::cout << blue << "Great work " + name + "," << std::endl << std::endl; sleep(2s);
  std::cout << "You Have Now Reached To 'Oryn', The Land of Dragons!" << std::endl << std::endl; sleep(2s);
  std::cout << "This is the last territory captured by Murlocs. To recapture this you have to defeat Murlocs."  << std::endl; sleep(2s);
  std::cout << "But be carefull, Murlocs is not like the rest of the monsters. He has different powers." << std::endl; sleep(2s);
  std::cout << "Remeber, you have to use sword, shield, armour and bow that you have collected so far, to defeat the Murlocs." << std::endl; sleep(2s);
  std::cout << "Good luck warrior!" << std::endl << std::endl << std::endl; sleep(2s);
}


void startLevelSix(std::string name)
{
  levelSixInstructions(name);
  moveForward();

  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/Monster6.txt"); sleep(1s);
  std::cout << blue << "Great! You found the Murlocs. Let's take back what is our's" << std::endl << std::endl; sleep(2s);
  
  while(true)
  {
    std::cout << green << "Press 'B' to battle with Murlocs... " ;
    std::string input;
    std::cin >> input;
    if(!(input == "B" || input == "b"))
    {
      std::cout << red << "Hey Warrior, it's time to show your Bravery!" << std::endl << std::endl;
    }
    else break;
  }
}

void attack(Enemy* enemy, Player* player)
{
  bool specialAbilityUsed = false;
  bool specialAbilityMurlocs = false;

  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Attack :" << std::endl;

  if(rand() % 5 == 0)
  {
    player->setMeleeDamage(player->getMeleeDamage() * 2);
    std::cout << blue << "Special Ability Used : Critical Hit" << std::endl;
    specialAbilityUsed = true;
  }
  else
  {
    player->randomizeRangedDamage();
  }

  checkAlive(enemy);

  if(rand() % 5 == 0)
  {
    enemy->setEnemyDamage(0);
    std::cout << blue << "Special Ability Used : Blocker" << std::endl;
  }

  if(rand() % 5 == 0)
  {
    player->setPlayerHealth(player->getPlayerHealth() + 20);
    std::cout << blue << "Special Ability Used : Life Steal" << std::endl;
  }

  enemy->setEnemyHealth(enemy->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));

  if(rand() % 7 == 0)
  {
    std::cout << red << "Special Ability Used By Murlocs : Ground Slash" << std::endl;
    enemy->setEnemyDamage(enemy->getEnemyDamage() * 2);
  }

  if(rand() % 7 == 0)
  {
    std::cout << red << "Special Ability Used By Murlocs : Health Regeneration" << std::endl;
    enemy->setEnemyHealth(enemy->getEnemyHealth() + 10);
  }
  
  player->setPlayerHealth(player->getPlayerHealth() - (enemy->getEnemyDamage()));

  showStats(enemy, player);
  
  std::cout << std::endl << blue << player->getPlayerName() + " : Damage Given = " << player->getMeleeDamage() + player->getRangedDamage() << std::endl;

  if(specialAbilityUsed)
  {
    player->setMeleeDamage(player->getMeleeDamage() / 2);
    specialAbilityUsed = false;
  }

  std::cout << enemy->getEnemyName() << red << " : Damage Given = " << enemy->getEnemyDamage() << std::endl;
  if(specialAbilityMurlocs)
  {
    enemy->setEnemyDamage(enemy->getEnemyDamage() / 2);
    specialAbilityMurlocs = false;
  }
}

void block(Enemy* enemy, Player* player)
{
  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Defend :" << std::endl;
  showStats(enemy, player);
  
  std::cout << std::endl << blue << player->getPlayerName() + " : Damage Given = 0" << std::endl;
  std::cout << red << enemy->getEnemyName() << " : Damage Given = 0" << std::endl;
}


void levelSixBattle(Player* player)
{
  Enemy* enemy = new Enemy("Murlocs", bossEnemy, 100, 10);

  std::string input; 
  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Get Ready Warrior!" << std::endl;
  showStats(enemy, player);
  
  while(true)
  {
    if(enemy->getEnemyHealth() <= 0) break; 
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
        attack(enemy, player);
        break;
      case 1:
        block(enemy, player);
        break;
      default:
        attack(enemy, player);
        break;
    }
  }

  std::cout << std::endl << std::endl << blue << "!! Hurrah, You Won The Battle !!" << std::endl;
  std::cout <<std::endl << green << "Press Enter To Continue... ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/EndCharacter.txt"); sleep(1s);
  std::cout << blue << "Gratias Tibi " + player->getPlayerName() + "," << std::endl << std::endl; sleep(2s);
  std::cout << "You have defeated Murlocs and recaptured Oryn." << std::endl; sleep(2s);
  std::cout << "The lands of Eldkinane has seen your bravery and will alwayas be remembered." << std::endl; sleep(2s);
  std::cout << "Ave " + player->getPlayerName() + "!" << std::endl<< std::endl; sleep(2s);
  
  std::cout << green << "Press Enter To Exit... ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  
  delete enemy;
}