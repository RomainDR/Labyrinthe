#include "MapSelector.h"
#include "Environment.h"
#include "StringUtils.h"
#include "Utils.h"
#include <filesystem>
#include <iostream>

MapSelector::MapSelector(const std::string _folder)
{
	path = Environment::CurrentDirectory() + "\\" + _folder + "/";
	LoadMaps();
}

MapSelector::MapSelector(const MapSelector& _copy)
{
	path = _copy.path;
}

void MapSelector::LoadMaps()
{
	int number = 0;
	for (const std::filesystem::directory_entry file : std::filesystem::directory_iterator(path))
	{
		std::string filePath = StringUtils::Replace(file.path().string(), '\\', '/');
		std::string fileName = filePath.substr(filePath.find_last_of('/') + 1, filePath.npos);
		maps.push_back(fileName);
	}
}

void MapSelector::ShowMaps()
{
	for (int i = 0; i < maps.size(); i++)
	{
		std::cout << "[" << (i + 1) << "]" << maps.at(i) << std::endl;
	}
}

std::string MapSelector::SelectMap()
{
	int mapNumber = Utils::UserChoice<int>("Select map number: ");
	if (mapNumber < 0 || mapNumber > maps.size()) mapNumber = 0;
	return maps.at(mapNumber-1);
}
