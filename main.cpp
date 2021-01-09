#include <iostream>

using namespace std;

class Player
{
private:
    std::string _name;
    int _health;
    int _xp;

public:
    std::string get_name() { return _name; }
    int get_health() { return _health; }
    int get_xp() { return _xp; }

    Player(std::string name_val = "None", int health_val = 0, int xp_val = 0);
    Player(const Player &source);

    ~Player()
    {
        std::cout << "Destructor called for Player: " << _name << std::endl;
    }
};

Player::Player(std::string name_val, int health_val, int xp_val) : _name{name_val}, _health{health_val}, _xp{xp_val}
{
    std::cout << "Three-args constructor called for " << _name << std::endl;
}

Player::Player(const Player &source) : _name{source._name}, _health{source._health}, _xp{source._xp}
{
    std::cout << "\nCopy constructor - made a copy of " << _name << std::endl;
}

void display_player(Player p)
{
    std::cout << p.get_health() << std::endl;
    std::cout << p.get_name() << std::endl;
    std::cout << p.get_xp() << std::endl;
}

int main()
{
    Player Alex{"Alex", 10, 15};
    Player Mike{"Mike", 20, 25};

    Player Player_1{Alex};
    Player Player_2{Mike};

    display_player(Alex);
    display_player(Mike);

    return 0;
}
