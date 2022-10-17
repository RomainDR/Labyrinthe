#pragma once
#include <vector>
#include <string>

class Case;
class Player;
class Vector2;

class Map
{

#pragma region f/p
private:
	std::vector<Case*> cases = std::vector<Case*>();
	std::string mapName = "map";

	Case* exit = nullptr;
	Case* enter = nullptr;
	Player* player = nullptr;
#pragma endregion f/p

#pragma region constructor/destructor
public:
	Map() = default;
	Map(const std::string _mapName);
	Map(const Map& _copy);
	~Map();
#pragma endregion constructor/destructor

#pragma region methods
private:
	void Init();
public:
	void Display();
	bool IsValid() const;

	Case* GetCaseAtPosition(const Vector2& _position);
	Case* Enter() const;
	Case* Exit() const;
	Player* GetPlayer() const;
	#pragma endregion methods
};

