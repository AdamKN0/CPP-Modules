#include <iostream>
class ClapTrap
{
protected:
    std::string _name;
    int _hitpoints;
    int _energyPoints;
    int _attackDamage;

public:
    ClapTrap()
    {
        _name = "ClapTrap_Default";
        _hitpoints = 10;
        _energyPoints = 10;
        _attackDamage = 0;
        std::cout << "ClapTrap default " << _name << " is created." << std::endl;
    }
    ClapTrap(const std::string &name)
    {
        _name = name;
        _hitpoints = 10;
        _energyPoints = 10;
        _attackDamage = 0;
        std::cout << "ClapTrap " << _name << " is created." << std::endl;
    }
    ClapTrap(const ClapTrap &other)
    {
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "ClapTrap " << _name << " is copied." << std::endl;
    }
    ~ClapTrap()
    {
        std::cout << "ClapTrap " << _name << " is destroyed." << std::endl;
    }
    ClapTrap &operator=(const ClapTrap &other)
    {
        if (this == &other)
            return *this;
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "ClapTrap " << _name << " is assigned." << std::endl;
        return *this;
    }
    void attack(const std::string &target)
    {
        if (_energyPoints <= 0 || _hitpoints <= 0)
        {
            std::cout << "ClapTrap " << _name << " can't attack. No energy or hitpoints left." << std::endl;
            return;
        }
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    void takeDamage(unsigned int amount)
    {
        _hitpoints -= amount;
        if (_hitpoints < 0)
            _hitpoints = 0;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage. Remaining hitpoints: " << _hitpoints << std::endl;
    }
    void beRepaired(unsigned int amount)
    {
        if (_energyPoints <= 0 || _hitpoints <= 0)
        {
            std::cout << "ClapTrap " << _name << " can't be repaired. No energy or hitpoints left." << std::endl;
            return;
        }
        _hitpoints += amount;
        _energyPoints--;
        std::cout << "ClapTrap " << _name << " is repaired by " << amount << " points. New hitpoints: " << _hitpoints << std::endl;
    }
};
class ScavTrap : public ClapTrap
{
public:
    ScavTrap()
    {
        _name = "ScavTrap_Default";
        _hitpoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
        std::cout << "ScavTrap default " << _name << " is created." << std::endl;
    }
    ScavTrap(const std::string &name)
    {
        _name = name;
        _hitpoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
        std::cout << "ScavTrap " << _name << " is created." << std::endl;
    }
    ScavTrap(const ScavTrap &other)
    {
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "ScavTrap " << _name << " is copied." << std::endl;
    }
    ~ScavTrap()
    {
        std::cout << "ScavTrap " << _name << " is destroyed." << std::endl;
    }
    ScavTrap &operator=(const ScavTrap &other)
    {
        if (this == &other)
            return *this;
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "ScavTrap " << _name << " is assigned." << std::endl;
        return *this;
    }
    void attack(const std::string &target)
    {
        if (_energyPoints <= 0 || _hitpoints <= 0)
        {
            std::cout << "ScavTrap " << _name << " can't attack. No energy or hitpoints left." << std::endl;
            return;
        }
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints--;
    }
    void guardGate()
    {
        if (_energyPoints <= 0 || _hitpoints <= 0)
        {
            std::cout << "ScavTrap " << _name << " can't guard gate. No energy or hitpoints left." << std::endl;
            return;
        }
        std::cout << "ScavTrap " << _name << " has entered Gatekeeper mode." << std::endl;
        _energyPoints--;
    }
};

class FragTrap : public ClapTrap
{
public:
    FragTrap()
    {
        _name = "FragTrap_Default";
        _hitpoints = 100;
        _energyPoints = 100;
        _attackDamage = 30;
        std::cout << "FragTrap default " << _name << " is created." << std::endl;
    }
    FragTrap(const std::string &name)
    {
        _name = name;
        _hitpoints = 100;
        _energyPoints = 100;
        _attackDamage = 30;
        std::cout << "FragTrap " << _name << " is created." << std::endl;
    }
    FragTrap(const FragTrap &other)
    {
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "FragTrap " << _name << " is copied." << std::endl;
    }
    ~FragTrap()
    {
        std::cout << "FragTrap " << _name << " is destroyed." << std::endl;
    }
    FragTrap &operator=(const FragTrap &other)
    {
        if (this == &other)
            return *this;
        _name = other._name;
        _hitpoints = other._hitpoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
        std::cout << "FragTrap " << _name << " is assigned." << std::endl;
        return *this;
    }
    void highFivesGuys()
    {
        std::cout << "FragTrap " << _name << " is requesting a high five!" << std::endl;
    }
};
int main()
{
    // ClapTrap :
    ClapTrap defaultClap; // Default constructor
    defaultClap.attack("enemy");
    defaultClap.takeDamage(5);
    defaultClap.beRepaired(3);

    ClapTrap clap("Clap"); // Name constructor
    clap.attack("enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    ClapTrap clap2 = clap; // Copy constructor
    clap2.attack("enemy");
    clap2.takeDamage(5);
    clap2.beRepaired(3);

    ClapTrap clap3; // Default constructor
    clap3 = clap;   // Assignation operator
    clap3.attack("enemy");
    clap3.takeDamage(5);
    clap3.beRepaired(3);

    // ScavTrap :
    ScavTrap defaultScav; // Default constructor
    defaultScav.attack("enemy");
    defaultScav.takeDamage(5);
    defaultScav.beRepaired(3);
    defaultScav.guardGate();

    ScavTrap scav("Scav"); // Name constructor
    scav.attack("enemy");
    scav.takeDamage(5);
    scav.beRepaired(3);
    scav.guardGate();

    ScavTrap scav2 = scav; // Copy constructor
    scav2.attack("enemy");
    scav2.takeDamage(5);
    scav2.beRepaired(3);
    scav2.guardGate();

    ScavTrap scav3; // Default constructor
    scav3 = scav;   // Assignation operator
    scav3.attack("enemy");
    scav3.takeDamage(5);
    scav3.beRepaired(3);
    scav3.guardGate();

    // FragTrap :
    FragTrap defaultFrag; // Default constructor
    defaultFrag.attack("enemy");
    defaultFrag.takeDamage(5);
    defaultFrag.beRepaired(3);
    defaultFrag.highFivesGuys();

    FragTrap frag("Frag"); // Name constructor
    frag.attack("enemy");
    defaultFrag.takeDamage(5);
    defaultFrag.beRepaired(3);
    defaultFrag.highFivesGuys();

    FragTrap frag2 = frag; // Copy constructor
    frag2.attack("enemy");
    defaultFrag.takeDamage(5);
    defaultFrag.beRepaired(3);
    defaultFrag.highFivesGuys();

    FragTrap frag3; // Default constructor
    frag3 = frag;   // Assignation operator
    frag3.attack("enemy");
    defaultFrag.takeDamage(5);
    defaultFrag.beRepaired(3);
    defaultFrag.highFivesGuys();

    return 0;
}