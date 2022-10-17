#include "Entity.h"
#include "Vector2.h"
#include "Utils.h"
#include "MapDatabse.h"
#include "Map.h"

#pragma region constructor
Entity::Entity(const std::string& _name, Map* _currentMap,  Vector2* _position, const float _maxLife, const float _maxMana)
{
	name = _name;
	life = maxLife = _maxLife;
	mana = maxMana = _maxMana;
	position = _position;
	map = _currentMap;
}

Entity::Entity(const Entity& _copy)
{
	name = _copy.name;
	life = _copy.life;
	maxLife = _copy.maxLife;
	mana = _copy.mana;
	maxMana = _copy.maxMana;
	position = _copy.position;
	map = _copy.map;
}
Entity::~Entity()
{
	delete position;
}
#pragma endregion constructor

#pragma region methods


Vector2* Entity::Position() const
{
	return position;
}

Map* Entity::GetMap() const
{
	return map;
}

std::string Entity::Name() const
{
	return name;
}
std::string Entity::ToString() const
{
	return name + ": Life => " + std::to_string(life) + ", Mana => " + std::to_string(mana);
}
float Entity::Life() const
{
	return life;
}
float Entity::MaxLife() const
{
	return maxLife;
}
float Entity::Mana() const
{
	return mana;
}
float Entity::MaxMana() const
{
	return maxMana;
}
bool Entity::IsDead() const
{
	return life == 0;
}
bool Entity::HashMana(const float _cost) const
{
	return mana >= _cost;
}
bool Entity::Equals(const Entity* _other) const
{
	return name == _other->name;
}
void Entity::SetLife(const float _life)
{
	life = Utils::Clamp(_life, 0.0f, maxLife);
}
void Entity::SetMaxLife(const float _maxLife)
{
	maxLife = _maxLife;
}
void Entity::AddLife(const float _value)
{
	life = Utils::Clamp(life + _value, 0.0f, maxLife);
}
void Entity::SetMana(const float _mana)
{
	mana = _mana;
}
void Entity::SetMaxMana(const float _maxMana)
{
	maxMana = _maxMana;
}
void Entity::TakeDamage(const float _dmg)
{
	life = Utils::Clamp(life - _dmg, 0.0f, maxLife);
}
void Entity::AddMana(const float _value)
{
	mana = Utils::Clamp(mana + _value, 0.0f, maxMana);
}
void Entity::DecreaseMana(const float _value)
{
	mana = Utils::Clamp(mana - _value, 0.0f, maxMana);
}
#pragma endregion methods
