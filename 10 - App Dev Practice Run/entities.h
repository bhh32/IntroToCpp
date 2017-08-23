#pragma once
#ifndef ENTITIES_H
#define ENTITIES_H

struct Entities
{
	int hitPoints;
	int maxHitPoints;
	int attackPoints;
	int healPoints;
	int defendPoints;
	int skillPointsToAdd;
	int skillIncreaseAmount;
	char skillChoice;
	char continueOrImprove;
	bool finishedSkillUpgrade;
	int actionChoice;
};

void Attack(Entities &enemy, Entities &self);
int Defend(Entities &enemy, Entities &self);
void Heal(Entities &self);
void ImproveSkills(Entities &self, Entities enemy);
void PlayerDeath();
void EnemyDeath(Entities &self, Entities &enemy);

#endif ENTITIES_H
