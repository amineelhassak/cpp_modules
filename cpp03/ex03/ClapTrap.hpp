#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap  {
    protected:
        std::string name;
        int         Hit_points;
        int         Energy_points;
        int         Attack_damage;
    public:
        ClapTrap ( void );
        ClapTrap (const ClapTrap &);
        ClapTrap &operator = (const ClapTrap&);
        void attack (const std::string& target);
        void takeDamage (unsigned int amount);
        void beRepaired (unsigned int amount);
        ClapTrap (std::string);
        ~ClapTrap ( void );
};
#endif