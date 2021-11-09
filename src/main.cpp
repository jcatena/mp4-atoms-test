/* 
 * File:   main.cpp
 * Author: jcatena@diwaves.com
 */

#include "atom.h"

#include <cstdlib>
#include <iostream>
#include <fstream>


using namespace std;

static const char *in_file_name = "/home/jcatena/dv/test/mp4-atoms-test/test/text0.mp4";

/*
 * 
 */
int main(int argc, char** argv) {
    fstream* in_stream = new fstream(in_file_name, ios_base::in | ios::binary);
    filebuf* in_streambuf = in_stream->rdbuf();
    atom_size size;
    atom_type type;

    cout << in_streambuf->is_open() << endl;
    // cout << in_streambuf << endl;
    
    while (atom_factory::read(in_streambuf));
    size.read(in_streambuf);
    type.read(in_streambuf);
    
    in_stream->close();
    delete in_stream;
    
    return 0;
}

