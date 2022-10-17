#include <iostream>
#include "Map.h"
#include "Environment.h"
#include "Player.h"
#include "Vector2.h"
#include "Path.h"
#include "Case.h"
#include "Utils.h"
#include "MapSelector.h"

int main()
{
	MapSelector selector = MapSelector("Maps");
	selector.ShowMaps();	
	
	Map map = Map(selector.SelectMap());
	if(!map.IsValid()) return -4;

	while (!map.GetPlayer()->Position()->Equals(map.Exit()->Position()))
	{
		system("cls");
		map.Display();
		map.GetPlayer()->Move();
	}
	system("cls");
	Utils::Log(map.GetPlayer()->Name() + " find the exit");
}
