#include "Player.h"

Player::Player(std::string name, std::string village, int health, int damage)
{
  setPlayerName(name);
  setPlayerVillage(village);
  setPlayerHealth(health);
  setMeleeDamage(damage);
}

std::string const Player::getPlayerName()
{
  return playerName;
}

void Player::setPlayerName(std::string name)
{
  playerName = name;
}

std::string const Player::getPlayerVillage()
{
  return playerVillage;
}

void Player::setPlayerVillage(std::string village)
{
  playerVillage = village;
}

int const Player::getPlayerLevel()
{
  return playerLevel;
}

void Player::setPlayerLevel(int level)
{
  playerLevel = level;
}

int const Player::getPlayerHealth()
{
  return playerHealth;
}

void Player::setPlayerHealth(int health)
{
  playerHealth = health;
}

int const Player::getMeleeDamage()
{
  return meleeDamage;
}

void Player::setMeleeDamage(int damage)
{
  meleeDamage = damage;
} 

int const Player::getRangedDamage()
{
  return rangedDamage;
}

void Player::setRangedDamage(int damage)
{
  rangedDamage = damage;
}

SpecialAbility const Player::getSpecialAbility()
{
  return specialAbility;
}

void Player::setSpecialAbility(SpecialAbility ability)
{
  specialAbility = ability;
}

void Player::randomizeRangedDamage()
{
  setRangedDamage(5 + rand() % 9);
}
