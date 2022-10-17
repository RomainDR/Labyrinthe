#pragma once
#include "Item.h"
class Weapons : public Item
{
private:
	float damage = 0.0f;
public:
	Weapons() = default;
	Weapons(const std::string& _name, float _damage);
	Weapons(const Weapons& _copy);

public:
	float Damage() const;
	void SetDamage(const float _dmg);
	std::string ToString() const override;
	void OnUse(Entity* _entity) override;
};

