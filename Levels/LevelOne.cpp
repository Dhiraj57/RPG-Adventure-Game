#include "../GameManager.h"
// #include "../colormod.h"

void showStats(Player* player, Enemy* enemy)
{

  if(player->getPlayerHealth() < 0) 
  {
    player->setPlayerHealth(0);
  }
  std::cout << blue << player->getPlayerName() << " : Health = " << player->getPlayerHealth() << std::endl;

  getEnemyStats(enemy);

}


void levelOneInstructions(std::string name)
{
  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/Trorotley.txt"); sleep(1s);
  std::cout << blue << "Great work " + name + "," << std::endl << std::endl; sleep(2s);
  std::cout << "You Have Now Reached To 'Trorotley', The Mist Valley!" << std::endl; sleep(2s);
  std::cout << "Here you can get the 'Map' for your further journey."  << std::endl; sleep(2s);
  std::cout << "But wait, to get that map you have to defeat the monster who is guarding that map." << std::endl << std::endl << std::endl; sleep(2s);
}


void startLevelOne(std::string name)
{
  levelOneInstructions(name);
  moveForward();
  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/Monster.txt"); sleep(1s);
  std::cout << blue << "Hurrah! You found the Map, but you have to defeat the monster to get that map." << std::endl << std::endl; sleep(2s);
  
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

void attack(Player* player, Enemy* enemy)
{
  system("clear");
  std::cout << "\e[2J\e[H";
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Attack :"  << std::endl;
  player->randomizeRangedDamage();
  enemy->randomizeEnemyDamage();

  enemy->setEnemyHealth(enemy->getEnemyHealth() - (player->getMeleeDamage() + player->getRangedDamage()));
  player->setPlayerHealth(player->getPlayerHealth() - enemy->getEnemyDamage());

  showStats(player, enemy);
  std::cout << blue << player->getPlayerName() << " : Damage Given = " << player->getMeleeDamage() + player->getRangedDamage() << std::endl;
  std::cout << red << enemy->getEnemyName()  <<" : Damage Given = " << enemy->getEnemyDamage() << std::endl;
}

void block(Player* player, Enemy* enemy)
{
  system("clear");
  std::cout << "\e[2J\e[H";
  printASCII("TextFiles/MonsterBattle.txt");
  std::cout << green << "Defend :"  << std::endl;
  showStats(player, enemy);
  std::cout << blue << player->getPlayerName() << " : Damage Given = 0" << std::endl;
  std::cout << red << enemy->getEnemyName() << " : Damage Given = 0" << std::endl;
}


void levelOneBattle(Player* player)
{
  Enemy* enemy = new Enemy("Gravel",normalEnemy, 30, 5);
  std::string input; 
  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/MonsterBattle.txt"); 
  std::cout << green << "Get Ready Warrior!" << std::endl;
  showStats(player, enemy);
  
  while(true)
  {
    if(enemy->getEnemyHealth() <= 0) break; sleep(2s);
    
    std::cout << def; 
    switch(rand() % 3)
    {
      case 0:
        attack(player, enemy);
        break;
      case 1:
        block(player, enemy);
        break;
      default:
        attack(player, enemy);
        break;
    }
  }

  std::cout << std::endl << std::endl << blue << "!! Hurrah, You Won The Battle !!" << std::endl << std::endl; 
  std::cout << green << "Press Enter To Continue... ";
  std::cin.get();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

  system("clear");
  std::cout << "\e[2J\e[H" << def;
  printASCII("TextFiles/Scroll.txt"); sleep(1s);
  std::cout << blue << "Well done " + player->getPlayerName() + "," << std::endl << std::endl; sleep(2s);
  std::cout << "You have recaptured Trorotley. Now you have the map for the further journey." << std::endl; sleep(2s);
  std::cout << "One down, five more to go. Good luck warrior!" << std::endl<< std::endl; sleep(2s);
  moveForward();
  
  delete enemy;
}
