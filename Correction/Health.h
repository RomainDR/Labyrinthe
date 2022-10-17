#pragma once
#include "Potions.h"
class Health : public Potions
{
public:
	Health() = default;
	Health(const float _value);

	void OnUse(Entity* _entity) override;

};

