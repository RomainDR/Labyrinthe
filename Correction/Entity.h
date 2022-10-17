#pragma once
#include <string>

class Vector2;
class Map;

class Entity
{
#pragma region f/p
private:
	std::string name ="";
	float life = 0.0f;
	float maxLife = 100.0f;
	float mana = 0.0f;
	float maxMana = 100.0f;

	Vector2* position = nullptr;
	Map* map = nullptr;

#pragma endregion f/p

#pragma region constructor/destructor
public:
	Entity() = default;
	Entity(const std::string& _name, Map* _currentMap, Vector2* _position, const float _maxLife = 100.0f, const float _maxMana = 100.0f);
	Entity(const Entity& _copy);
	virtual ~Entity();
#pragma endregion constructor/destructor


#pragma region methods
	Vector2* Position() const;
	Map* GetMap() const;
	std::string Name() const;
	std::string ToString() const;
	float Life() const;
	float MaxLife() const;
	float Mana() const;
	float MaxMana() const;
	bool IsDead() const;
	bool HashMana(const float _cost) const;
	bool Equals(const Entity* _other) const;
	void SetLife(const float _life);
	void SetMaxLife(const float _maxLife);
	void AddLife(const float _value);
	void SetMana(const float _mana);
	void SetMaxMana(const float _maxMana);
	void TakeDamage(const float _dmg);
	void AddMana(const float _value);
	void DecreaseMana(const float _value);
	virtual void Move() = 0;
#pragma endregion methods
};

