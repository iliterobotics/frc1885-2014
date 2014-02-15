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
WS_ROOT_DIR := C:/Users/Robot/Desktop/GitHub/frc1885-2014
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/Robot



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

IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

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
PROJECT_TARGETS = Robot/$(MODE_DIR)/Robot.out \
	 Robot_partialImage/$(MODE_DIR)/Robot_partialImage.o


#Rules

# Robot
ifeq ($(DEBUG_MODE),1)
Robot/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Robot/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Robot/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
Robot/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Robot/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Robot/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Robot/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
Robot/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
Robot/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
Robot/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Robot/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Robot/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
Robot/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
Robot/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
Robot/$(MODE_DIR)/% : IDE_DEFINES = 
Robot/$(MODE_DIR)/% : PROJECT_TYPE = DKM
Robot/$(MODE_DIR)/% : DEFINES = 
Robot/$(MODE_DIR)/% : EXPAND_DBG = 0
Robot/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
Robot/$(MODE_DIR)/% : CPU = PPC32
Robot/$(MODE_DIR)/% : TOOL_FAMILY = diab
Robot/$(MODE_DIR)/% : TOOL = diab
Robot/$(MODE_DIR)/% : TOOL_PATH = 
Robot/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
Robot/$(MODE_DIR)/% : LIBPATH = 
Robot/$(MODE_DIR)/% : LIBS = 
Robot/$(MODE_DIR)/% : OBJ_DIR := Robot/$(MODE_DIR)

OBJECTS_Robot = Robot_partialImage/$(MODE_DIR)/Robot_partialImage.o

Robot/$(MODE_DIR)/Robot.out : $(OBJECTS_Robot)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_Robot) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -Xforce-declarations $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tPPCFH:vxworks63 -X -r5 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_Robot) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

Robot/$(MODE_DIR)/Robot_compile_file : $(FILE) ;

_clean :: Robot/$(MODE_DIR)/Robot_clean

Robot/$(MODE_DIR)/Robot_clean : 
	$(TRACE_FLAG)if [ -d "Robot" ]; then cd "Robot"; rm -rf $(MODE_DIR); fi


# Robot_partialImage
ifeq ($(DEBUG_MODE),1)
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -XO -Xsize-opt
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -XO -Xsize-opt
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -XO -Xsize-opt
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Robot_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -XO -Xsize-opt
endif
Robot_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
Robot_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
Robot_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
Robot_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
Robot_partialImage/$(MODE_DIR)/% : DEFINES = 
Robot_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
Robot_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
Robot_partialImage/$(MODE_DIR)/% : CPU = PPC32
Robot_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
Robot_partialImage/$(MODE_DIR)/% : TOOL = diab
Robot_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
Robot_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tPPCFH:vxworks63 -Xstmw-slow -DPPC32_fp60x
Robot_partialImage/$(MODE_DIR)/% : LIBPATH = 
Robot_partialImage/$(MODE_DIR)/% : LIBS = 
Robot_partialImage/$(MODE_DIR)/% : OBJ_DIR := Robot_partialImage/$(MODE_DIR)

Robot_partialImage/$(MODE_DIR)/Objects/Robot/PID.o : $(PRJ_ROOT_DIR)/PID.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Autonomous.o : $(PRJ_ROOT_DIR)/bhs_Autonomous.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Catcher.o : $(PRJ_ROOT_DIR)/bhs_Catcher.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Compressor.o : $(PRJ_ROOT_DIR)/bhs_Compressor.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_DriverInput.o : $(PRJ_ROOT_DIR)/bhs_DriverInput.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Drivetrain.o : $(PRJ_ROOT_DIR)/bhs_Drivetrain.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDCatcher.o : $(PRJ_ROOT_DIR)/bhs_GDCatcher.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDDrivetrain.o : $(PRJ_ROOT_DIR)/bhs_GDDrivetrain.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDIntake.o : $(PRJ_ROOT_DIR)/bhs_GDIntake.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDShooter.o : $(PRJ_ROOT_DIR)/bhs_GDShooter.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDTusks.o : $(PRJ_ROOT_DIR)/bhs_GDTusks.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GlobalData.o : $(PRJ_ROOT_DIR)/bhs_GlobalData.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Intake.o : $(PRJ_ROOT_DIR)/bhs_Intake.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_MutexRobot.o : $(PRJ_ROOT_DIR)/bhs_MutexRobot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_OutputManager.o : $(PRJ_ROOT_DIR)/bhs_OutputManager.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Robot.o : $(PRJ_ROOT_DIR)/bhs_Robot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_SensorInput.o : $(PRJ_ROOT_DIR)/bhs_SensorInput.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Shooter.o : $(PRJ_ROOT_DIR)/bhs_Shooter.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Tusks.o : $(PRJ_ROOT_DIR)/bhs_Tusks.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only -Xforce-declarations  -Xmake-dependency=0xd $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_Robot_partialImage = Robot_partialImage/$(MODE_DIR)/Objects/Robot/PID.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Autonomous.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Catcher.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Compressor.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_DriverInput.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Drivetrain.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDCatcher.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDDrivetrain.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDIntake.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDShooter.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDTusks.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GlobalData.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Intake.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_MutexRobot.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_OutputManager.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Robot.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_SensorInput.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Shooter.o \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Tusks.o

Robot_partialImage/$(MODE_DIR)/Robot_partialImage.o : $(OBJECTS_Robot_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tPPCFH:vxworks63 -X -r5  -o "$@" $(OBJECTS_Robot_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

Robot_partialImage/$(MODE_DIR)/Robot_partialImage_compile_file : $(FILE) ;

_clean :: Robot_partialImage/$(MODE_DIR)/Robot_partialImage_clean

Robot_partialImage/$(MODE_DIR)/Robot_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "Robot_partialImage" ]; then cd "Robot_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := Robot_partialImage/$(MODE_DIR)/Objects/Robot/PID.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Autonomous.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Catcher.d \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Compressor.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_DriverInput.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Drivetrain.d \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDCatcher.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDDrivetrain.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDIntake.d \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDShooter.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GDTusks.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_GlobalData.d \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Intake.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_MutexRobot.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_OutputManager.d \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Robot.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_SensorInput.d Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Shooter.d \
	 Robot_partialImage/$(MODE_DIR)/Objects/Robot/bhs_Tusks.d
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
