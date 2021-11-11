/* 
 * File:   atom_base.h
 * Author: jcatena@diwaves.com
 */

#ifndef ATOM_BASE_H
#define ATOM_BASE_H

#include <boost/endian/conversion.hpp>
#include <cstdint>
#include <iostream>
#include <memory>


/*
#if boost::endian::order::native == boost::endian::order::big
#@define endian_reverse()
 */

// error codes
enum atom_result {
    OK = 0
    , READ = 1
};

struct atom_size {
    uint32_t m_value;

    atom_result read(std::istream* s);
};

struct atom_type {
    char m_fourc[4];

    atom_result read(std::istream* s);
    bool equals(const char *id);
};

class atom_base {
public:
    atom_base(const atom_size& size, const atom_type& type);
    virtual ~atom_base();
    virtual atom_result read(std::istream* s);

protected:
    atom_size m_size;
    atom_type m_type;
};

/* helper function for blocking stream reads */
atom_result atom_read(std::istream* s, void *buf, std::streamsize n);

#endif /* ATOM_BASE_H */

