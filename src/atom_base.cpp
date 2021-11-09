/* 
 * File:   atom_base.cpp
 * Author: jcatena@diwaves.com
 */

#include "atom_base.h"

using namespace std;

atom_result atom_size::read(std::streambuf* in)
{
    std::streamsize ssize;
    ssize = in->sgetn((char *)&m_value, 4);
    if (ssize != 4)
        return READ;
    boost::endian::big_to_native_inplace(m_value);
    return OK;
}


atom_result atom_type::read(std::streambuf* in)
{
    std::streamsize ssize;
    ssize = in->sgetn(m_fourc, 4);
    return ssize == 4 ? OK : READ;
}

bool atom_type::equals(const char *id)
{
    return strncmp(m_fourc, id, 4) == 0 ? true : false;
}


atom_base::atom_base(const atom_size& size, const atom_type& type)
    : m_size(size), m_type(type)
{
    cout << "Found box of type " << string(m_type.m_fourc, 4) << " and size " << m_size.m_value << endl;
}

atom_base::~atom_base()
{
}

atom_result atom_base::read(std::streambuf* in)
{
    uint32_t count_left = m_size.m_value - 8;
    const uint32_t bufsize = 0x80;
    uint32_t count, count2;
    char buf[bufsize];
    
    while (count_left) {
        count = min(count_left, bufsize);
        count2 = in->sgetn(buf, count);
        if (count2 != count)
            return READ;
        count_left -= count;
    }
    return OK;
}

