#include "Potions.h"
#include "Utils.h"
#include <iostream>

Potions::Potions(const Potions& _copy) : Item(_copy)
{
	value = _copy.value;
}
Potions::Potions(const std::string& _name, const float _value) : Item(_name)
{
	value = _value;
}

float Potions::Value() const
{
	return value;
}

std::string Potions::ToString() const
{
	return Item::ToString() + " value: " + std::to_string(value);
}

void Potions::OnUse(Entity* _entity)
{
	Item::OnUse(_entity);
}

bool Potions::Equals(const Item* _other) const
{
	const Potions* _potion = dynamic_cast<const Potions*>(_other);
	if (_potion == nullptr) return false;
	const bool _result = Item::Equals(_other) && value == _potion->value;
	return _result;
}
