#include "Weapons.h"
#include "Entity.h"
#include <iostream>

#pragma region constructor
Weapons::Weapons(const std::string& _name, float _damage): Item(_name)
{
	damage = _damage;
	SetIsStacklable(false);
}

Weapons::Weapons(const Weapons& _copy) : Item(_copy)
{
	damage = _copy.damage;
}
#pragma endregion constructor

#pragma region methods

float Weapons::Damage() const
{
	return damage;
}

void Weapons::SetDamage(const float _dmg)
{
	damage = _dmg < 0 ? 0 : _dmg;
}

std::string Weapons::ToString() const
{
	return Item::ToString() + ", damage: " + std::to_string(damage);
}

void Weapons::OnUse(Entity* _entity)
{
	_entity->TakeDamage(damage);
	std::cout << _entity->Name() + " receive: " + std::to_string(damage) + " damage !" << std::endl;
	std::cout << "life of " + _entity->Name() + ": " + std::to_string(_entity->Life()) << std::endl;
}
#pragma endregion methods