# mp4-atoms-test

Test that outputs boxes found in a mp4 file.

## Bonus questions

### Bonus 1: Which problem can occur if the content of the MDAT box is very large?

This implementation does not impose a limit neither in file or MDAT box sizes. All data is read from the stream in small chunks, and memory allocated for those is freed when processed and before new chunks are allocated.

If we tried instead to allocate memory for a whole box, a large box could exhaust the available memory.

### Bonus 2: The MDAT box contains base64­encoded images. Extract those images to files.

The MDAT box in the sample is a ttml subtitles stream, based in XML.

Extraction of the embedded images requires parsing of the ttml file using an XML parser.

The best kind of parser to use in this kind of application is an streaming one, that parses the stream as it is received instead of waiting to receive the whole XML before start parsing it. Furthermore, this way the available memory will not limit the size of the box to handle.

There are many xml deserialization libraries available. Even so, writting the code to parse the ttml in streaming mode would take several hours for a very naive and trivial demo that would not show special design skills. Doing it to show how well can it be done would take too much time for the purpose of this test IMHO.

I propose instead to explain the details of an advanced serialization library I developed for HP, supporting XML and json, doc and streaming operation modes, and automatic binding to native C++ objects. Although I could not show any code (proprietary).

## Design choices

The primary design decissions criteria has been to show the most relevant skills related with the test definition and scope, while keeping development cost and complexity at a minimum.

Many details that are usually needed to comply with established development architectures and strategies have not been defined. We are assumming that these are not evaluated for this test, and no efforts have been invested in showing skills related with those. These details include use of frameworks and common libraries, dependencies management, testing/CI/CD integration, threading model, etc. 

The iso boxes handling has been implemented as a collection of classes to show OOP abstraction and skills. The input data is implemented using streams and minimizing memory usage. This implementation allows handling of files of huge sizes with very little memory usage.

I decided to implement and test it under Linux, because a Linux host is most often the best choice for cross platform development. Even If I had to setup a new linux devel workstation.

I used NetBeans for projects setup simplicity. It is not one of my preferred IDEs but looked like a quick started, I hope that adequate for a test like this. Though I ended spending more time than expected fixing NetBeans configuration.

## external dependencies

No dependency or package management have been used. This test requires all the dependencies separately installed and configured.

### POCO

POCO is being used to perform HTTP GET to read the HTTP test file. Chosen for simplicity and because it uses standard C++ stream interfaces.

For production code I'd consider a custon general purpose C++ networking client library using libcurl. I designed in the past such a library for HP, very sophisticated yet relatively simple, with features like comprehensive list of standard protocols with common abstract API, homogeneous sync and async operation, automatic error recovery with retries/pause/resuming, bandwidth usage and caps measurement and limiting, pluggable authentication including auth modules for AWS and other popular ones, and a lot more. I could answer any question on how I did it, although I cannot show any code (proprietary).

### boost

Boost library has been chosen to help with general needs and some specific requirements:
- Endian conversions will be needed when the architecture endianess differ from mp4 fields endianess. That's very trivial anyway.
- The bonus 2 solution would require xml deserialization. Boost provides this functionality, but it is neither simple to use or best quality. For best network streaming performance I'd choose a stream based parser, so that data is parsed as it is being received instead of having to wait for all the data before starting parsing. Additionally, a streaming parser allows to implement it in a way that very little memory would be needed regardless of the resource size. But this would take too much effort for a quick test.

## Invested time

I invested a total of 14 hours to complete this test as is.

This included 3 hours of preliminary investigation of esporadic failures reading from POCO stream. I stopped investigating further after verifying that the problem is not caused by the test code or related with the solution presented. 

I spend even more time setting up a Linux development host and solving a few configuration issues, although this time is not to be assigned to the solution presented.

