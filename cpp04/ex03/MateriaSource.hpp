#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    protected :
        AMateria *box[4];
    public :

        /********************************************************/
        MateriaSource ( void ) ;
        MateriaSource &operator = (const MateriaSource &_MateriaSource);
        MateriaSource (const MateriaSource &_MateriaSource);
        ~MateriaSource ( void ) ;

        /********************************************************/
        void learnMateria(AMateria*);
        AMateria * createMateria(std::string const &);
};

#endif