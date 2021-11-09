/* 
 * File:   atom_mdat.cpp
 * Author: jcatena@diwaves.com
 */

#include "atom_mdat.h"

using namespace std;

atom_mdat::atom_mdat(const atom_size& size, const atom_type& type)
    : atom_base::atom_base(size, type)
{
}

atom_mdat::~atom_mdat()
{
}

atom_result atom_mdat::read(std::streambuf* in)
{
    uint32_t count_left = m_size.m_value - 8;
    const uint32_t bufsize = 0x80;
    uint32_t count, count2;
    char buf[bufsize];
    
    cout << "Content of mdat box is: ";
    while (count_left) {
        count = min(count_left, bufsize);
        count2 = in->sgetn(buf, count);
        if (!count2) 
            break;
        cout << string(buf, count2);
        count_left -= count2;
        
    }
    return count2 ? OK : READ;
}
