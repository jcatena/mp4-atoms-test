/* 
 * File:   atom_list.h
 * Author: jcatena@diwaves.com
 */

#ifndef ATOM_LIST_H
#define ATOM_LIST_H

#include "atom_base.h"

class atom_list : public atom_base {
public:
    atom_list(const atom_size& size, const atom_type& type);
    virtual ~atom_list();
    atom_result read(std::streambuf* in);
private:

};

#endif /* ATOM_LIST_H */

