#include "Map.h"
#include "Path.h"
#include "Environment.h"
#include "File.h"
#include "Vector2.h"
#include "Case.h"
#include "Player.h"
#include "Utils.h"

#include <iostream>

#pragma region constructor/destructor
Map::Map(const std::string _mapName)
{
	mapName = _mapName;
	player = new Player(Utils::UserChoice<std::string>("Enter your username: "), this, new Vector2(0, 0));
	Init();
	if (!IsValid()) return;
}

Map::Map(const Map& _copy)
{
	mapName = _copy.mapName;
	cases = _copy.cases;
}

Map::~Map()
{
	cases.clear();
}

#pragma endregion constructor/destructor

#pragma region methods
void Map::Init()
{

	const std::string& _path = Path::Combine(Environment::CurrentDirectory(), "Maps", mapName);
	std::vector<std::string> _lines = File::GetAllLines(_path);
	const size_t _size = _lines.size();
	for (size_t y = 0; y < _size; y++)
	{
		const std::string _line = _lines[y];
		const size_t _length = _line.length();
		for (size_t x = 0; x < _length; x++)
		{
			Vector2* _position = new Vector2((int)x, (int)y);
			Case* _case = new Case(_line[x], _position);
			if (_case->IsEnter()) {
				enter = _case;
				player->Position()->Set(*_position);
			}
			else if (_case->IsExit()) exit = _case;
			cases.push_back(_case);
		}
		cases.push_back(new Case('\n', new Vector2(-1, -1))); //TODO to change !
	}
}
void Map::Display()
{
	const size_t _size = cases.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (player->Position()->Equals(cases[i]->Position()))
			std::cout << MapDatabse::Player;
		else
			std::cout << cases[i]->CaseValue();
	}
}
bool Map::IsValid() const
{
	return enter != nullptr && exit != nullptr;
}
Case* Map::GetCaseAtPosition(const Vector2& _position)
{
	const size_t _size = cases.size();
	for (size_t i = 0; i < _size; i++)
	{
		if (cases[i]->Position()->Equals(&_position))
			return cases[i];
	}
	return nullptr;
}
Case* Map::Enter() const
{
	return enter;
}
Case* Map::Exit() const
{
	return exit;
}
Player* Map::GetPlayer() const
{
	return player;
}
#pragma endregion methods
