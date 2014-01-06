# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := Z:/Users/Silu/frc1885-2014
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/DriverDTOnly



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = DriverDTOnly/$(MODE_DIR)/DriverDTOnly.out \
	 DriverDTOnly_partialImage/$(MODE_DIR)/DriverDTOnly_partialImage.o


#Rules

# DriverDTOnly
ifeq ($(DEBUG_MODE),1)
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DriverDTOnly/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
DriverDTOnly/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
DriverDTOnly/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
DriverDTOnly/$(MODE_DIR)/% : IDE_DEFINES = 
DriverDTOnly/$(MODE_DIR)/% : PROJECT_TYPE = DKM
DriverDTOnly/$(MODE_DIR)/% : DEFINES = 
DriverDTOnly/$(MODE_DIR)/% : EXPAND_DBG = 0
DriverDTOnly/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
DriverDTOnly/$(MODE_DIR)/% : CPU = PPC603
DriverDTOnly/$(MODE_DIR)/% : TOOL_FAMILY = gnu
DriverDTOnly/$(MODE_DIR)/% : TOOL = gnu
DriverDTOnly/$(MODE_DIR)/% : TOOL_PATH = 
DriverDTOnly/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp
DriverDTOnly/$(MODE_DIR)/% : LIBPATH = 
DriverDTOnly/$(MODE_DIR)/% : LIBS = 
DriverDTOnly/$(MODE_DIR)/% : OBJ_DIR := DriverDTOnly/$(MODE_DIR)

OBJECTS_DriverDTOnly = DriverDTOnly_partialImage/$(MODE_DIR)/DriverDTOnly_partialImage.o

DriverDTOnly/$(MODE_DIR)/DriverDTOnly.out : $(OBJECTS_DriverDTOnly)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_DriverDTOnly) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_DriverDTOnly) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

DriverDTOnly/$(MODE_DIR)/DriverDTOnly_compile_file : $(FILE) ;

_clean :: DriverDTOnly/$(MODE_DIR)/DriverDTOnly_clean

DriverDTOnly/$(MODE_DIR)/DriverDTOnly_clean : 
	$(TRACE_FLAG)if [ -d "DriverDTOnly" ]; then cd "DriverDTOnly"; rm -rf $(MODE_DIR); fi


# DriverDTOnly_partialImage
ifeq ($(DEBUG_MODE),1)
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
DriverDTOnly_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
DriverDTOnly_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
DriverDTOnly_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
DriverDTOnly_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
DriverDTOnly_partialImage/$(MODE_DIR)/% : DEFINES = 
DriverDTOnly_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
DriverDTOnly_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
DriverDTOnly_partialImage/$(MODE_DIR)/% : CPU = PPC603
DriverDTOnly_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
DriverDTOnly_partialImage/$(MODE_DIR)/% : TOOL = gnu
DriverDTOnly_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
DriverDTOnly_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp
DriverDTOnly_partialImage/$(MODE_DIR)/% : LIBPATH = 
DriverDTOnly_partialImage/$(MODE_DIR)/% : LIBS = 
DriverDTOnly_partialImage/$(MODE_DIR)/% : OBJ_DIR := DriverDTOnly_partialImage/$(MODE_DIR)

DriverDTOnly_partialImage/$(MODE_DIR)/Objects/DriverDTOnly/robot.o : $(PRJ_ROOT_DIR)/robot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_DriverDTOnly_partialImage = DriverDTOnly_partialImage/$(MODE_DIR)/Objects/DriverDTOnly/robot.o

DriverDTOnly_partialImage/$(MODE_DIR)/DriverDTOnly_partialImage.o : $(OBJECTS_DriverDTOnly_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_DriverDTOnly_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

DriverDTOnly_partialImage/$(MODE_DIR)/DriverDTOnly_partialImage_compile_file : $(FILE) ;

_clean :: DriverDTOnly_partialImage/$(MODE_DIR)/DriverDTOnly_partialImage_clean

DriverDTOnly_partialImage/$(MODE_DIR)/DriverDTOnly_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "DriverDTOnly_partialImage" ]; then cd "DriverDTOnly_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := DriverDTOnly_partialImage/$(MODE_DIR)/Objects/DriverDTOnly/robot.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

JOBS?=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS);\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
