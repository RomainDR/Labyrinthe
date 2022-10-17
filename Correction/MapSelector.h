#pragma once
#include <vector>
#include <string>


class MapSelector
{
private:
	std::string path = "";
	std::vector<std::string> maps = std::vector<std::string>();
public:
	MapSelector() = default;
	MapSelector(const std::string _folder);
	MapSelector(const MapSelector& _copy);

public:
	void LoadMaps();
	void ShowMaps();
	std::string SelectMap();
};

