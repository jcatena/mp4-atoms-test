#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/atom_base.o \
	${OBJECTDIR}/src/atom_factory.o \
	${OBJECTDIR}/src/atom_list.o \
	${OBJECTDIR}/src/atom_mdat.o \
	${OBJECTDIR}/src/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/usr/local/lib -Wl,-rpath,'/usr/local/lib' /usr/local/lib/libPocoNet.so /usr/local/lib/libPocoFoundation.so /usr/local/lib/libPocoNetSSL.so

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mp4-atoms-test

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mp4-atoms-test: /usr/local/lib/libPocoNet.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mp4-atoms-test: /usr/local/lib/libPocoFoundation.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mp4-atoms-test: /usr/local/lib/libPocoNetSSL.so

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mp4-atoms-test: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mp4-atoms-test ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/atom_base.o: src/atom_base.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atom_base.o src/atom_base.cpp

${OBJECTDIR}/src/atom_factory.o: src/atom_factory.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atom_factory.o src/atom_factory.cpp

${OBJECTDIR}/src/atom_list.o: src/atom_list.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atom_list.o src/atom_list.cpp

${OBJECTDIR}/src/atom_mdat.o: src/atom_mdat.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/atom_mdat.o src/atom_mdat.cpp

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} -r ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libPocoNet.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libPocoFoundation.so ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libPocoNetSSL.so
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/mp4-atoms-test

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
