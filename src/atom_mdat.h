/* 
 * File:   atom_mdat.h
 * Author: jcatena@diwaves.com
 */

#ifndef ATOM_MDAT_H
#define ATOM_MDAT_H

#include "atom_base.h"

class atom_mdat : public atom_base {
public:
    atom_mdat(const atom_size& size, const atom_type& type);
    virtual ~atom_mdat();
    atom_result read(std::istream* s);
};

#endif /* ATOM_MDAT_H */

