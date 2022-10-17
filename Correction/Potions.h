#pragma once
#include "Item.h"
class Potions : public Item
{
private:
	float value = 0.0f;

public:
	Potions() = default;
	Potions(const std::string& _name, const float _value);
	Potions(const Potions& _copy);

#pragma region methods
public:
	float Value() const;
	std::string ToString() const override;
	void OnUse(class Entity* _entity) override;
	bool Equals(const Item* _other) const override;
#pragma endregion methods
};

