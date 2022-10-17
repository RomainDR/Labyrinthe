#pragma once
#include "MapDatabse.h"

class Vector2;
class Case
{
	/*
	* Position => getter
	* Etat => getter
	* Case() = default;
	* Case(etat, position);
	* ~Case(copy);
	* ~Case();
	* 
	*/

private:
	char caseValue = MapDatabse::Wall;
	Vector2* position = nullptr;

#pragma region constructor
public:
	Case() = default;
	Case(const char _value, Vector2* _position);
	Case(const Case& _copy);
	virtual ~Case();
#pragma endregion constructor

#pragma region methods
public:
	bool IsWall() const;
	bool HasMob() const;
	bool IsEnter() const;
	bool IsExit() const;
	char CaseValue() const;
Vector2* Position() const;
#pragma endregion methods
};

