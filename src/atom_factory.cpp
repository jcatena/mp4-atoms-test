/* 
 * File:   atom_factory.cpp
 * Author: jcatena@diwaves.com
 */

#include "atom_factory.h"
#include "atom_base.h"
#include "atom_list.h"
#include "atom_mdat.h"

using namespace std;

atom_factory::atom_factory()
{
}

atom_factory::~atom_factory()
{
}

atom_result atom_factory::read(std::istream* s)
{
    atom_result res;
    atom_size size;
    atom_type type;
    atom_base *atom;

    res = size.read(s);
    if (res != OK)
        return res;
    res = type.read(s);
    if (res != OK)
        return res;

    if (type.equals("moof"))
        atom = new atom_list(size, type);
    else if (type.equals("traf"))
        atom = new atom_list(size, type);
    else if (type.equals("mdat"))
        atom = new atom_mdat(size, type);
    else
        atom = new atom_base(size, type);

    res = atom->read(s);

    return res;
}
