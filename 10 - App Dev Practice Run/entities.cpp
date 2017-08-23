#include "entities.h"
#include "gameloop.h"
#include <iostream>

void Attack(Entities &enemy, Entities &self)
{
	self.hitPoints -= enemy.attackPoints;

	std::cout << "Hit!\n";

}

int Defend(Entities &enemy, Entities &self)
{
	self.hitPoints += self.defendPoints;
	
	if (self.hitPoints > enemy.attackPoints)
	{
		std::cout << "You defended against the enemy, and they missed!\n";
		return self.hitPoints - self.defendPoints;
	}
	else
	{
		self.hitPoints -= enemy.attackPoints;
		std::cout << "You defended against the enemy, and it reduced the attack impact!\n";
	}

	return self.hitPoints;
	
}

void Heal(Entities &self)
{
	if (self.healPoints + self.hitPoints <= self.maxHitPoints)
	{
		self.hitPoints += self.healPoints;
		std::cout << "You healed yourself to " << self.hitPoints << "!\n";
	}
	else
	{
		self.hitPoints += self.healPoints;
		self.hitPoints -= self.maxHitPoints;
		std::cout << "You filled your hitpoints! Your hitpoints are now: " << self.hitPoints << "\n";
	}	
}

void ImproveSkills(Entities &self, Entities enemy)
{
	GameLoop gameLoop;
	while (!self.finishedSkillUpgrade)
	{
		std::cout << "You have " << self.skillPointsToAdd << " skill points to add\n. Type {hit} - Hit Points\n     {attk} - Attack Points\n     {heal} - Heal Points\n     {def} - Defend Points: ";
		std::cin >> self.skillChoice;

		if (self.skillChoice == 'hit')
		{
			std::cout << "How many skill points would you like to add: ";
			std::cin >> self.skillIncreaseAmount;

			self.maxHitPoints += self.skillIncreaseAmount;
			self.hitPoints = self.maxHitPoints;

			self.skillIncreaseAmount -= self.skillIncreaseAmount;
		}
		else if (self.skillChoice == 'attk')
		{
			std::cout << "How many skill points would you like to add: ";
			std::cin >> self.skillIncreaseAmount;

			self.attackPoints += self.skillIncreaseAmount;

			self.skillIncreaseAmount -= self.skillIncreaseAmount;
		}
		else if (self.skillChoice == 'heal')
		{
			std::cout << "How many skill points would you like to add: ";
			std::cin >> self.skillIncreaseAmount;

			self.healPoints += self.skillIncreaseAmount;

			self.skillIncreaseAmount -= self.skillIncreaseAmount;
		}
		else if (self.skillChoice == 'def')
		{
			std::cout << "How many skill points would you like to add: ";
			std::cin >> self.skillIncreaseAmount;

			self.defendPoints += self.skillIncreaseAmount;

			self.skillIncreaseAmount -= self.skillIncreaseAmount;
		}
		else
			std::cout << "You didn't make a proper choice. Try Again!\n";

		if (self.skillPointsToAdd == 0)
		{
			self.finishedSkillUpgrade = !self.finishedSkillUpgrade;
			self.skillPointsToAdd = 3;
		}
	}

	gameLoop.Battle(self, enemy);
}

void PlayerDeath()
{
	GameLoop gameLoop;
	std::cout << "You Died!\nBetter Luck Next Time On Your Journey To Find... Dun Dun Dun... The Holy Donut!\n";
	system("pause");
	gameLoop.gameIsOver = !gameLoop.gameIsOver;
}

void EnemyDeath(Entities &self, Entities &enemy)
{
	GameLoop gameLoop;

	std::cout << "Great you defeated the chef!\n";
	while (self.continueOrImprove != 'c' || self.continueOrImprove != 'C' || self.continueOrImprove != 'i' || self.continueOrImprove != 'I')
	{
		std::cout << "Would you like to {c} continue or {i} improve your stats: ";
		std::cin >> self.continueOrImprove;

		if (self.continueOrImprove == 'c' || self.continueOrImprove == 'C')
		{
			gameLoop.Battle(self, enemy);
		}
		else if (self.continueOrImprove == 'i' || self.continueOrImprove == 'I')
			ImproveSkills(self, enemy);
		else
			std::cout << "You didn't choose a proper choice. Try Again!\n";
	}
	self.continueOrImprove = '-1';
}

