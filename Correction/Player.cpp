#include "Player.h"
#include "Inventory.h"
#include "Utils.h"
#include "Vector2.h"
#include "Case.h"
#include "Map.h"

Player::Player(const std::string& _name, Map* _currentMap, Vector2* _position, const float _maxLife, const float _maxMana)
    :Entity(_name,_currentMap, _position, _maxLife, _maxMana)
{
    inventory = new Inventory(_name + " Inventory", this);
}

Player::Player(const Player& _copy) : Entity(_copy)
{
    inventory = _copy.inventory;
}

Player::~Player()
{
    delete inventory;
}

Inventory* Player::GetInventory() const
{
    return inventory;
}

void Player::Move()
{
    char _input = Utils::UserChoice<char>("(z,q,s,d) for mouvement: ");
    Vector2 _position = *Position();
    switch (std::tolower(_input))
    {
    case 'z':
        //_position.Set(Vector2(_position.X(), _position.Y() - 1));
        _position -= Vector2(0, 1);
        break;
    case 's':
        //_position.Set(Vector2(_position.X(), _position.Y() + 1));
        _position += Vector2(0, 1);
        break;
    case 'q':
        //_position.Set(Vector2(_position.X() - 1, _position.Y()));
        _position -= Vector2(1, 0);
        break;
    case 'd':
        //_position.Set(Vector2(_position.X() + 1, _position.Y()));
        _position += Vector2(1, 0);
        break;
    default:break;
    }
    Case* _case = GetMap()->GetCaseAtPosition(_position);
    if (_case == nullptr || _case->IsWall()) return;
    Position()->Set(_position);

}
