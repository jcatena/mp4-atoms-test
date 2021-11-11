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

atom_result atom_mdat::read(std::istream* s)
{
    atom_result res = OK;
    const uint32_t bufsize = 0x80;
    char buf[bufsize];
    uint32_t count_left = m_size.m_value - 8;
    uint32_t count;

    cout << "Content of mdat box is: ";
    while (count_left)
    {
        count = min(count_left, bufsize);
        res = atom_read(s, buf, count);
        if (res != OK)
            break;
        cout << string(buf, count);
        count_left -= count;
    }
    cout << endl;
    return res;
}
