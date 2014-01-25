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

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC604diab
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/GitHub
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/FRC1885-2014



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC604
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tPPC604FH:vxworks63
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
DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
DEBUGFLAGS_Linker = -XO -Xsize-opt
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif


#Project Targets
PROJECT_TARGETS = WPILib/$(MODE_DIR)/WPILib.a \
	 JavaCameraLib/$(MODE_DIR)/JavaCameraLib.a


#Rules

# WPILib
ifeq ($(DEBUG_MODE),1)
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
WPILib/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
WPILib/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
WPILib/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
WPILib/$(MODE_DIR)/% : IDE_DEFINES = 
WPILib/$(MODE_DIR)/% : PROJECT_TYPE = DKM
WPILib/$(MODE_DIR)/% : DEFINES = 
WPILib/$(MODE_DIR)/% : EXPAND_DBG = 0
WPILib/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
WPILib/$(MODE_DIR)/% : CPU = PPC604
WPILib/$(MODE_DIR)/% : TOOL_FAMILY = diab
WPILib/$(MODE_DIR)/% : TOOL = diab
WPILib/$(MODE_DIR)/% : TOOL_PATH = 
WPILib/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPC604FH:vxworks63
WPILib/$(MODE_DIR)/% : LIBPATH = 
WPILib/$(MODE_DIR)/% : LIBS = 
WPILib/$(MODE_DIR)/% : OBJ_DIR := WPILib/$(MODE_DIR)

OBJECTS_WPILib =

WPILib/$(MODE_DIR)/WPILib.a : $(OBJECTS_WPILib)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS_WPILib)

WPILib/$(MODE_DIR)/WPILib_compile_file : $(FILE) ;

_clean :: WPILib/$(MODE_DIR)/WPILib_clean

WPILib/$(MODE_DIR)/WPILib_clean : 
	$(TRACE_FLAG)if [ -d "WPILib" ]; then cd "WPILib"; rm -rf $(MODE_DIR); fi


# JavaCameraLib
ifeq ($(DEBUG_MODE),1)
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
JavaCameraLib/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
JavaCameraLib/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
JavaCameraLib/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
JavaCameraLib/$(MODE_DIR)/% : IDE_DEFINES = 
JavaCameraLib/$(MODE_DIR)/% : PROJECT_TYPE = DKM
JavaCameraLib/$(MODE_DIR)/% : DEFINES = 
JavaCameraLib/$(MODE_DIR)/% : EXPAND_DBG = 0
JavaCameraLib/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
JavaCameraLib/$(MODE_DIR)/% : CPU = PPC604
JavaCameraLib/$(MODE_DIR)/% : TOOL_FAMILY = diab
JavaCameraLib/$(MODE_DIR)/% : TOOL = diab
JavaCameraLib/$(MODE_DIR)/% : TOOL_PATH = 
JavaCameraLib/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPC604FH:vxworks63
JavaCameraLib/$(MODE_DIR)/% : LIBPATH = 
JavaCameraLib/$(MODE_DIR)/% : LIBS = 
JavaCameraLib/$(MODE_DIR)/% : OBJ_DIR := JavaCameraLib/$(MODE_DIR)

OBJECTS_JavaCameraLib =

JavaCameraLib/$(MODE_DIR)/JavaCameraLib.a : $(OBJECTS_JavaCameraLib)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dar crus "$@" $(OBJECTS_JavaCameraLib)

JavaCameraLib/$(MODE_DIR)/JavaCameraLib_compile_file : $(FILE) ;

_clean :: JavaCameraLib/$(MODE_DIR)/JavaCameraLib_clean

JavaCameraLib/$(MODE_DIR)/JavaCameraLib_clean : 
	$(TRACE_FLAG)if [ -d "JavaCameraLib" ]; then cd "JavaCameraLib"; rm -rf $(MODE_DIR); fi

force : 



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

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
