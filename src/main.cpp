/* 
 * File:   main.cpp
 * Author: jcatena@diwaves.com
 */

#include "atom.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <memory>

#include <Poco/URI.h>
#include "Poco/URIStreamOpener.h"

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPStreamFactory.h>
#include <Poco/Net/HTTPSStreamFactory.h>

using namespace std;
using namespace Poco;
using namespace Net;

using Poco::URIStreamOpener;
using Poco::URI;
using Poco::Exception;
using Poco::Net::HTTPStreamFactory;
using Poco::Net::HTTPSStreamFactory;

static const char* in_file_name = "/dv/src/test/mp4-atoms-test/test/text0.mp4";
static const char* in_uri_dft = "http://demo.castlabs.com/tmp/text0.mp4";

/*
 * 
 */
int main(int argc, char** argv)
{
    int res = 0;
    istream* in_stream = nullptr;
    HTTPStreamFactory::registerFactory();
    HTTPSStreamFactory::registerFactory();

    try
    {
        URI uri(argc >= 2 ? argv[1] : in_uri_dft);
        in_stream = (URIStreamOpener::defaultOpener().open(uri));
        while (atom_factory::read(in_stream) == OK);
        res = 0;
    }
    catch (Exception& exc)
    {
        cerr << exc.displayText() << endl;
        res = 1;
    }

    if (in_stream)
        delete (in_stream);

    return res;
}

