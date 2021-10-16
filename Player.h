#include <string>

enum SpecialAbility
{
  criticalHit,
  blocker,
  lifeSteal,
  rangedAttack
};

enum meleeDamage
{
  sword,
  shield,
  armour,
  bow
};

class Player{
private:
  std::string playerName;
  std::string playerVillage;
  int playerLevel;
  int playerHealth;
  int meleeDamage;
  int rangedDamage;
  SpecialAbility specialAbility;

public:
  Player(std::string, std::string, int, int);

  std::string const getPlayerName();
  void setPlayerName(std::string);
  std::string const getPlayerVillage();
  void setPlayerVillage(std::string);
  int const getPlayerLevel();
  void setPlayerLevel(int);
  int const getPlayerHealth();
  void setPlayerHealth(int);
  int const getMeleeDamage();
  void setMeleeDamage(int);
  int const getRangedDamage();
  void setRangedDamage(int);
  SpecialAbility const getSpecialAbility();
  void setSpecialAbility(SpecialAbility);
  void randomizeRangedDamage();

};