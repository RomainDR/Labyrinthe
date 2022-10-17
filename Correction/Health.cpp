#include "Health.h"
#include "Entity.h"
#include <iostream>

Health::Health(const float _value) : Potions("Potion Health", _value)
{

}

void Health::OnUse(Entity* _entity)
{
	Potions::OnUse(_entity);
	_entity->AddLife(Value());
	std::cout << "new life for " + _entity->Name() + ": " << std::to_string(_entity->Life()) << std::endl;
}
