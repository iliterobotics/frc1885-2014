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

BUILD_SPEC = PPC32gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/GitHub
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/frc1885-2014



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC32
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mhard-float -mstrict-align -mno-implicit-fp -DPPC32_fp60x
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
PROJECT_TARGETS = frc1885-2014a/$(MODE_DIR)/frc1885-2014a.out \
	 frc1885-2014a_partialImage/$(MODE_DIR)/frc1885-2014a_partialImage.o


#Rules

# frc1885-2014a
ifeq ($(DEBUG_MODE),1)
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
frc1885-2014a/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
frc1885-2014a/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
frc1885-2014a/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
frc1885-2014a/$(MODE_DIR)/% : IDE_DEFINES = 
frc1885-2014a/$(MODE_DIR)/% : PROJECT_TYPE = DKM
frc1885-2014a/$(MODE_DIR)/% : DEFINES = 
frc1885-2014a/$(MODE_DIR)/% : EXPAND_DBG = 0
frc1885-2014a/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
frc1885-2014a/$(MODE_DIR)/% : CPU = PPC32
frc1885-2014a/$(MODE_DIR)/% : TOOL_FAMILY = gnu
frc1885-2014a/$(MODE_DIR)/% : TOOL = gnu
frc1885-2014a/$(MODE_DIR)/% : TOOL_PATH = 
frc1885-2014a/$(MODE_DIR)/% : CC_ARCH_SPEC = -mhard-float -mstrict-align -mno-implicit-fp -DPPC32_fp60x
frc1885-2014a/$(MODE_DIR)/% : LIBPATH = 
frc1885-2014a/$(MODE_DIR)/% : LIBS = 
frc1885-2014a/$(MODE_DIR)/% : OBJ_DIR := frc1885-2014a/$(MODE_DIR)

OBJECTS_frc1885-2014a = frc1885-2014a_partialImage/$(MODE_DIR)/frc1885-2014a_partialImage.o

frc1885-2014a/$(MODE_DIR)/frc1885-2014a.out : $(OBJECTS_frc1885-2014a)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_frc1885-2014a) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_frc1885-2014a) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

frc1885-2014a/$(MODE_DIR)/frc1885-2014a_compile_file : $(FILE) ;

_clean :: frc1885-2014a/$(MODE_DIR)/frc1885-2014a_clean

frc1885-2014a/$(MODE_DIR)/frc1885-2014a_clean : 
	$(TRACE_FLAG)if [ -d "frc1885-2014a" ]; then cd "frc1885-2014a"; rm -rf $(MODE_DIR); fi


# frc1885-2014a_partialImage
ifeq ($(DEBUG_MODE),1)
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
frc1885-2014a_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
frc1885-2014a_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
frc1885-2014a_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
frc1885-2014a_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
frc1885-2014a_partialImage/$(MODE_DIR)/% : DEFINES = 
frc1885-2014a_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
frc1885-2014a_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
frc1885-2014a_partialImage/$(MODE_DIR)/% : CPU = PPC32
frc1885-2014a_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
frc1885-2014a_partialImage/$(MODE_DIR)/% : TOOL = gnu
frc1885-2014a_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
frc1885-2014a_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mhard-float -mstrict-align -mno-implicit-fp -DPPC32_fp60x
frc1885-2014a_partialImage/$(MODE_DIR)/% : LIBPATH = 
frc1885-2014a_partialImage/$(MODE_DIR)/% : LIBS = 
frc1885-2014a_partialImage/$(MODE_DIR)/% : OBJ_DIR := frc1885-2014a_partialImage/$(MODE_DIR)

frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Actuator.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_Actuator.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Autonomous.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_Autonomous.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Button.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_Button.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Compressor.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_Compressor.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Drivetrain.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_Drivetrain.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Limit.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_Limit.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Manipulator.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_Manipulator.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_MutextRobot.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_MutextRobot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_PID.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_PID.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Robot.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_Robot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Target.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_Target.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_VisionInput.o : $(PRJ_ROOT_DIR)/beta_framework/bhs_VisionInput.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_frc1885-2014a_partialImage = frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Actuator.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Autonomous.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Button.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Compressor.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Drivetrain.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Limit.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Manipulator.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_MutextRobot.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_PID.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Robot.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Target.o \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_VisionInput.o

frc1885-2014a_partialImage/$(MODE_DIR)/frc1885-2014a_partialImage.o : $(OBJECTS_frc1885-2014a_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_frc1885-2014a_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

frc1885-2014a_partialImage/$(MODE_DIR)/frc1885-2014a_partialImage_compile_file : $(FILE) ;

_clean :: frc1885-2014a_partialImage/$(MODE_DIR)/frc1885-2014a_partialImage_clean

frc1885-2014a_partialImage/$(MODE_DIR)/frc1885-2014a_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "frc1885-2014a_partialImage" ]; then cd "frc1885-2014a_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Actuator.d frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Autonomous.d frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Button.d \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Compressor.d frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Drivetrain.d frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Limit.d \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Manipulator.d frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_MutextRobot.d frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_PID.d \
	 frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Robot.d frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_Target.d frc1885-2014a_partialImage/$(MODE_DIR)/Objects/frc1885-2014/beta_framework/bhs_VisionInput.d
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
