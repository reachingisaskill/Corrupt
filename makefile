####################################################################################################
# 
# Corrupt Makefile
#
# Don't fucken break it!
#
####################################################################################################
#
# Configuration
#

# CCC_FLAGS = 
CCC = g++ -g -Wall -pedantic -Wextra


# Installation
INSTALL_DIR =


# The Basics:
INC_DIR = inc
BIN_DIR = bin
SRC_DIR = src
TMP_DIR = .temp

# Default Final Program
EXE_SRC = Corrupt.cxx


LT_DIR = $(realpath libraries/logtastic)
RG_DIR = $(realpath libraries/regolith)

# Library targets
LOGTASTIC = ${LT_DIR}/lib/liblogtastic.so
REGOLITH = ${RG_DIR}/lib/libRegolith.a



#Also Includes and Libs
INC_FLAGS += -I${LT_DIR}/include -I${RG_DIR}/include -I${INC_DIR}
LIB_FLAGS += -L${LT_DIR}/lib -L${RG_DIR}/lib
export INC_FLAGS
export LIB_FLAGS



SHARED_LIBS = -llogtastic -ljsoncpp -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lpthread
STATIC_LIBS = ${REGOLITH}


####################################################################################################
#
# Setup
#

# Find The Files
#SRC_FILES = ${shell ls $(SRC_DIR)}
SRC_FILES = ${shell find $(SRC_DIR) -type f | cut -d '/' -f 2-}
#INC_FILES = ${shell ls $(INC_DIR)}
INC_FILES = ${shell find $(INC_DIR) -type f | cut -d '/' -f 2-}

INCLUDE = $(patsubst %.h,${INC_DIR}/%.h,$(filter %.h,$(INC_FILES)))
INCLUDE+= $(patsubst %.hpp,${INC_DIR}/%.hpp,$(filter %.hpp,$(INC_FILES)))

#SOURCES = $(patsubst %.cpp,${SRC_DIR}/%.cpp,$(filter %.cpp,$(SRC_FILES)))
#SOURCES+= $(patsubst %.cxx,${SRC_DIR}/%.cpp,$(filter %.cxx,$(SRC_FILES)))
SOURCES = $(filter %.cpp,$(SRC_FILES))

OBJECTS = $(patsubst %.cpp,$(TMP_DIR)/%.o,$(filter %.cpp,$(SRC_FILES)))
EXE_OBJ = $(patsubst %.cxx,$(TMP_DIR)/%.o,$(filter %.cxx,$(SRC_FILES)))

PROGRAM = ${BIN_DIR}/$(basename ${EXE_SRC})


####################################################################################################
#
# Recipes
#


.PHONY : program all _all build install clean clean_libraries buildall directories includes intro check_install

all : _all


_all : intro directories ${LOGTASTIC} ${REGOLITH} ${PROGRAM}
	@echo
	@echo "Target : '"$(basename ${EXE_SRC})"' Succesfully Built"

intro:
	@echo "Building Target : " $(basename ${EXE_SRC})
	@echo "Please Wait..."


${PROGRAM} : ${OBJECTS} ${EXE_OBJ}
	@echo " - Building Target"
	@${CCC} -o $@ $^ ${STATIC_LIBS} ${INC_FLAGS} ${LIB_FLAGS} ${SHARED_LIBS}


${EXE_OBJ} : ${SRC_DIR}/${EXE_SRC} ${INCLUDE}
	@echo " - Compiling Target : " $(notdir $(basename $@))
	@${CCC} -c $< -o $@ ${INC_FLAGS}


${OBJECTS} : ${TMP_DIR}/%.o : ${SRC_DIR}/%.cpp ${INCLUDE}
	@echo " - Compiling Source : " $(notdir $(basename $@))
	@mkdir -p $(dir $@)
	@${CCC} -c $< -o $@ ${INC_FLAGS}


${LOGTASTIC} :
	@echo "Building Logtastic"
	@echo
	@$(MAKE) -C ${LT_DIR} library
	@echo


${REGOLITH} :
	@echo "Building Regolith"
	@echo
	@$(MAKE) -C ${RG_DIR} library
	@echo



directories : ${BIN_DIR} ${SRC_DIR} ${INC_DIR} ${TMP_DIR}

${BIN_DIR} :
	mkdir -p ${BIN_DIR}

${SRC_DIR} :
	mkdir -p ${SRC_DIR}

${INC_DIR} :
	mkdir -p ${INC_DIR}

${TMP_DIR} :
	mkdir -p ${TMP_DIR}



clean :
	rm -rf ${TMP_DIR}/*
	rm -f ${BIN_DIR}/*
	rm -f ${PROGRAM}


clean_libraries :
	@$(MAKE) -C ${LT_DIR} clean
	@$(MAKE) -C ${RG_DIR} clean


install : check_install
	@echo
	@echo "Installing Program/Libraries"
	@cp ${PROGRAM} ${INSTALL_DIR}/bin/$(notdir $(CURDIR))_$(basename ${EXE_SRC})
	@cp ${INC_DIR}/*.h* ${INSTALL_DIR}/include
	@echo

check_install :
	@if [ -z "${INSTALL_DIR}" ]; then          \
		echo                                    ;\
		echo "  INSTALLATION DIRECTORY NOT SET" ;\
		echo                                    ;\
		exit 1                                  ;\
		fi


