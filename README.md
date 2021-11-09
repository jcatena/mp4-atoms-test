# mp4-atoms-test

Test that outputs boxes found in a mp4 file.

## Design choices

The primary design decissions criteria has been to show the most relevant skills related with the test definition and scope, while keeping development cost and complexity at a minimum.

Many details that are usually needed to comply with established development architectures and strategies have not been defined. We are assumming that these are not evaluated for this test, and no efforts have been invested in showing skills related with those. These details include use of frameworks and common libraries, dependencies management, testing/CI/CD integration, threading model, etc. 

The iso boxes handling has been implemented as a collection of classes to show OOP abstraction and skills. The input data is implemented using streams and minimizing memory usage. This implementation allows handling of files of huge sizes with very little memory usage.

## external dependencies

No dependency or package management have been used. This test requires all the dependencies separately installed and configured.

### boost

Boost library has been chosen to help with general needs and some specific requirements:
- Endian conversions will be needed when the architecture endianess differ from mp4 fields endianess.
- The test input is an HTTP resource. I'd choose a custom C++ library for powerful multiprotocol network client based in libcurl. But it would be overkill for a quick test and I'll use boost::beast instead.
- The bonus 2 solution would require xml deserialization. For best network streaming performance I'd choose a stream based parser, so that data is parsed as it is being received instead of having to wait for all the data before starting parsing. Additionally, a streaming parser allows to implement it in a way that very little memory would be needed regardless of the resource size. But this would take too much effort for a quick test.

