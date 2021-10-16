#include <string>

enum EnemyType
{
  normalEnemy,
  bossEnemy
};

enum AttackType
{
  groundSlash,
  speedDash,
  healthRegenration
};

class Enemy{
private:
  std::string enemyName;
  int enemyHealth;
  int enemyDamage;
  EnemyType enemyType;
  AttackType attackType;

public:
  Enemy(std::string, EnemyType, int, int);

  std::string const getEnemyName();
  void setEnemyName(std::string);
  int const getEnemyHealth();
  void setEnemyHealth(int);
  int const getEnemyDamage();
  void setEnemyDamage(int);
  AttackType const getAttackType();
  void setAttackType(AttackType);
  EnemyType const getEnemyType();
  void setEnemyType(EnemyType);
  void randomizeEnemyDamage();

};