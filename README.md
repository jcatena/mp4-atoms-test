# mp4-atoms-test

Test that outputs atoms found in a mp4 file.

## Design choices

Because this is a test and we cannot make assumptions outside its scope, we choose to include external libraries as git submodules, in order to show git knowledge and provide simple dependency integration. In real world scenarios with common dependencies that are used in many projects, usage of a package manager (such as conan, for example) would be preferred in order to avoid downloading and compiling the same dependencies multiple times without need.

Boost library has been chosen to help with general needs and some specific requirements:
- The requirements include downloading a file from HTTP.
- Endian conversions will be needed when the architecture endianess differ from mp4 fields endianess.
- The bonus 2 solution requires xml deserialization.

## external dependencies

### boost
sudo apt-get install libboost-all-dev

