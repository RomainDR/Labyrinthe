#include "File.h"
#include <fstream>

std::vector<std::string> File::GetAllLines(const std::string& _path)
{
	std::ifstream _stream = std::ifstream(_path);
	if (!_stream.good())
		throw std::exception("invalid path or path not found");
	std::vector<std::string> _result = std::vector<std::string>();
	std::string _str = "";
	while (std::getline(_stream, _str))
		_result.push_back(_str);
	return _result;
}
