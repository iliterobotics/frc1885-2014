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

BUILD_SPEC = PPC32diab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := W:/FRC/frc1885-2014
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/TestDTInput



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 

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
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = TestDTInput/$(MODE_DIR)/TestDTInput.out \
	 TestDTInput_partialImage/$(MODE_DIR)/TestDTInput_partialImage.o


#Rules

# TestDTInput
ifeq ($(DEBUG_MODE),1)
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TestDTInput/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
TestDTInput/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
TestDTInput/$(MODE_DIR)/% : IDE_LIBRARIES = 
TestDTInput/$(MODE_DIR)/% : IDE_DEFINES = 
TestDTInput/$(MODE_DIR)/% : PROJECT_TYPE = DKM
TestDTInput/$(MODE_DIR)/% : DEFINES = 
TestDTInput/$(MODE_DIR)/% : EXPAND_DBG = 0
TestDTInput/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
TestDTInput/$(MODE_DIR)/% : CPU = PPC32
TestDTInput/$(MODE_DIR)/% : TOOL_FAMILY = diab
TestDTInput/$(MODE_DIR)/% : TOOL = diab
TestDTInput/$(MODE_DIR)/% : TOOL_PATH = 
TestDTInput/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
TestDTInput/$(MODE_DIR)/% : LIBPATH = 
TestDTInput/$(MODE_DIR)/% : LIBS = 
TestDTInput/$(MODE_DIR)/% : OBJ_DIR := TestDTInput/$(MODE_DIR)

OBJECTS_TestDTInput = TestDTInput_partialImage/$(MODE_DIR)/TestDTInput_partialImage.o

TestDTInput/$(MODE_DIR)/TestDTInput.out : $(OBJECTS_TestDTInput)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_TestDTInput) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tPPCFH:vxworks63 -X -r5 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_TestDTInput) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

TestDTInput/$(MODE_DIR)/TestDTInput_compile_file : $(FILE) ;

_clean :: TestDTInput/$(MODE_DIR)/TestDTInput_clean

TestDTInput/$(MODE_DIR)/TestDTInput_clean : 
	$(TRACE_FLAG)if [ -d "TestDTInput" ]; then cd "TestDTInput"; rm -rf $(MODE_DIR); fi


# TestDTInput_partialImage
ifeq ($(DEBUG_MODE),1)
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
TestDTInput_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
TestDTInput_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
TestDTInput_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
TestDTInput_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
TestDTInput_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
TestDTInput_partialImage/$(MODE_DIR)/% : DEFINES = 
TestDTInput_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
TestDTInput_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
TestDTInput_partialImage/$(MODE_DIR)/% : CPU = PPC32
TestDTInput_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
TestDTInput_partialImage/$(MODE_DIR)/% : TOOL = diab
TestDTInput_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
TestDTInput_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
TestDTInput_partialImage/$(MODE_DIR)/% : LIBPATH = 
TestDTInput_partialImage/$(MODE_DIR)/% : LIBS = 
TestDTInput_partialImage/$(MODE_DIR)/% : OBJ_DIR := TestDTInput_partialImage/$(MODE_DIR)

TestDTInput_partialImage/$(MODE_DIR)/Objects/TestDTInput/DriveTrain.o : $(PRJ_ROOT_DIR)/DriveTrain.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_TestDTInput_partialImage = TestDTInput_partialImage/$(MODE_DIR)/Objects/TestDTInput/DriveTrain.o

TestDTInput_partialImage/$(MODE_DIR)/TestDTInput_partialImage.o : $(OBJECTS_TestDTInput_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tPPCFH:vxworks63 -X -r5  -o "$@" $(OBJECTS_TestDTInput_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

TestDTInput_partialImage/$(MODE_DIR)/TestDTInput_partialImage_compile_file : $(FILE) ;

_clean :: TestDTInput_partialImage/$(MODE_DIR)/TestDTInput_partialImage_clean

TestDTInput_partialImage/$(MODE_DIR)/TestDTInput_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "TestDTInput_partialImage" ]; then cd "TestDTInput_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := TestDTInput_partialImage/$(MODE_DIR)/Objects/TestDTInput/DriveTrain.d
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
