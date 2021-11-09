/* 
 * File:   atom_list.cpp
 * Author: jcatena@diwaves.com
 */

#include "atom_list.h"
#include "atom_factory.h"

using namespace std;

atom_list::atom_list(const atom_size& size, const atom_type& type)
    : atom_base::atom_base(size, type)
{
}

atom_list::~atom_list()
{
}

atom_result atom_list::read(std::streambuf* in)
{
    atom_result res = OK;
    uint32_t count = m_size.m_value - 8;
    
    while (count -= 8) {
        res = atom_factory::read(in);
        if (res != OK)
            break;
    }
    
    return OK;
}
