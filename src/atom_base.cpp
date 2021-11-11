/* 
 * File:   atom_base.cpp
 * Author: jcatena@diwaves.com
 */

#include "atom_base.h"

using namespace std;

atom_result atom_read(istream* s, void *buf, streamsize n)
{
    streambuf* sb = s->rdbuf();
    char* bufc = (char *) buf;
    streamsize n2;

    while (n)
    {
        n2 = sb->sgetn(bufc, n);
        if (n2 == 0)
            break;
        bufc += n2;
        n -= n2;
    }

    return n == 0 ? OK : READ;
}

atom_result atom_size::read(std::istream* s)
{
    atom_result res = atom_read(s, &m_value, 4);
    if (res == OK)
    {
        boost::endian::big_to_native_inplace(m_value);
    }
    return res;
}

atom_result atom_type::read(std::istream* s)
{
    return atom_read(s, m_fourc, 4);
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

atom_result atom_base::read(std::istream* s)
{
    atom_result res = OK;
    uint32_t count_left = m_size.m_value - 8;
    uint32_t count;
    const uint32_t bufsize = 0x80;
    char buf[bufsize];

    while (count_left)
    {
        count = min(count_left, bufsize);
        res = atom_read(s, buf, count);
        if (res != OK)
            break;
        count_left -= count;
    }
    return res;
}

