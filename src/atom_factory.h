/* 
 * File:   atom_factory.h
 * Author: jcatena@diwaves.com
 */

#ifndef ATOM_FACTORY_H
#define ATOM_FACTORY_H

#include "atom_base.h"

class atom_factory {
public:
    atom_factory();
    virtual ~atom_factory();
    static atom_result read(std::istream* s);
private:
};

#endif /* ATOM_FACTORY_H */

