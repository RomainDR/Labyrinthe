#pragma once
#include <iostream>
class Utils
{
#pragma region methods
public:
	template<typename T>
	static T Clamp(const T& _value, const T& _min, const T& _max);

    template<typename T>
    static T UserChoice(const std::string _msg);
    static void Log(const std::string& _msg);

#pragma endregion methods
};

template<typename T>
T Utils::Clamp(const T& _value, const T& _min, const T& _max)
{
    if (_value < _min) return _min;
    if (_value > _max) return _max;
    return _value;
    //return _value < _min ? _min : _value > _max ? _max : _value;
}

template<typename T>
T Utils::UserChoice(const std::string _msg)
{
    if (_msg != "") std::cout << _msg << std::endl;
    T _result = T();
    std::cin >> _result;
    return _result;
}
