###########################################################################
# CMakeLists.txt generated for component runProgramNew
# Product type: STATIC library
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(runProgramNew)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()


###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR ../../.. ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
set(MATLAB_ROOT C:/Program\ Files/MATLAB/R2024b CACHE PATH "")

# Additional variables that are defined conditionally.
if("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()
if(APPLE)
    if("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL x86_64)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/maci64)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/sys/os/maci64)
        list(APPEND MATLAB_ROOT_SYSINCLUDE_PATHS ${MATLAB_ROOT}/toolbox/eml/externalDependency/omp/maci64/include)
    elseif("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL arm64)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/maca64)
        list(APPEND MATLAB_ROOT_SYSINCLUDE_PATHS ${MATLAB_ROOT}/toolbox/eml/externalDependency/omp/maca64/include)
    endif()
elseif(UNIX AND ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL x86_64) AND ("${CMAKE_SYSTEM_NAME}" STREQUAL Linux))
    list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/glnxa64)
elseif(WIN32 AND ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL AMD64))
    if(MSVC)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/extern/lib/win64/microsoft)
    elseif(MINGW)
        list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/extern/lib/win64/mingw64)
    endif()
    list(APPEND MATLAB_ROOT_SYSLIB_PATHS ${MATLAB_ROOT}/bin/win64
        ${MATLAB_ROOT}/lib/win64)
endif()


if(DEFINED MATLAB_ROOT_SYSLIB_PATHS)
    list(APPEND CMAKE_LIBRARY_PATH ${MATLAB_ROOT_SYSLIB_PATHS})
    link_directories(${MATLAB_ROOT_SYSLIB_PATHS})
endif()
if(DEFINED MATLAB_ROOT_SYSINCLUDE_PATHS)
    list(APPEND CMAKE_INCLUDE_PATH ${MATLAB_ROOT_SYSINCLUDE_PATHS})
endif()



###########################################################################
## Required packages
###########################################################################
find_package(OpenMP REQUIRED)

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

# Definition of target "runProgramNew".
add_library(runProgramNew STATIC ${START_DIR}/codegen/lib/runProgramNew/coder_posix_time.c
    ${START_DIR}/codegen/lib/runProgramNew/runProgramNew_data.c
    ${START_DIR}/codegen/lib/runProgramNew/rt_nonfinite.c
    ${START_DIR}/codegen/lib/runProgramNew/rtGetNaN.c
    ${START_DIR}/codegen/lib/runProgramNew/rtGetInf.c
    ${START_DIR}/codegen/lib/runProgramNew/runProgramNew_initialize.c
    ${START_DIR}/codegen/lib/runProgramNew/runProgramNew_terminate.c
    ${START_DIR}/codegen/lib/runProgramNew/runProgramNew.c
    ${START_DIR}/codegen/lib/runProgramNew/CreateModelSMA.c
    ${START_DIR}/codegen/lib/runProgramNew/tic.c
    ${START_DIR}/codegen/lib/runProgramNew/timeKeeper.c
    ${START_DIR}/codegen/lib/runProgramNew/rand.c
    ${START_DIR}/codegen/lib/runProgramNew/eml_rand_mt19937ar.c
    ${START_DIR}/codegen/lib/runProgramNew/Get_Functions_SMA.c
    ${START_DIR}/codegen/lib/runProgramNew/linspace.c
    ${START_DIR}/codegen/lib/runProgramNew/spline.c
    ${START_DIR}/codegen/lib/runProgramNew/ppval.c
    ${START_DIR}/codegen/lib/runProgramNew/diff.c
    ${START_DIR}/codegen/lib/runProgramNew/mean.c
    ${START_DIR}/codegen/lib/runProgramNew/unifrnd.c
    ${START_DIR}/codegen/lib/runProgramNew/abs.c
    ${START_DIR}/codegen/lib/runProgramNew/sum.c
    ${START_DIR}/codegen/lib/runProgramNew/mod.c
    ${START_DIR}/codegen/lib/runProgramNew/toc.c
    ${START_DIR}/codegen/lib/runProgramNew/sprintf.c
    ${START_DIR}/codegen/lib/runProgramNew/CoderTimeAPI.c
    ${START_DIR}/codegen/lib/runProgramNew/eml_rand_mt19937ar_stateful.c
    ${START_DIR}/codegen/lib/runProgramNew/pause.c
    ${START_DIR}/codegen/lib/runProgramNew/sort.c
    ${START_DIR}/codegen/lib/runProgramNew/sortIdx.c
    ${START_DIR}/codegen/lib/runProgramNew/atanh.c
    ${START_DIR}/codegen/lib/runProgramNew/SMA.c
    ${START_DIR}/codegen/lib/runProgramNew/runProgramNew_emxutil.c)

# Set properties for target "runProgramNew".
set_target_properties(runProgramNew PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/codegen/lib/runProgramNew/$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/codegen/lib/runProgramNew/$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/codegen/lib/runProgramNew/$<0:>")

# Specify language features required for target "runProgramNew".
target_compile_features(runProgramNew PUBLIC c_std_99)

# Specify compiler preprocessor definitions for target "runProgramNew".
target_compile_definitions(runProgramNew PRIVATE -DMODEL=runProgramNew)

# Specify include directories for target "runProgramNew".
target_include_directories(runProgramNew PUBLIC $<BUILD_INTERFACE:${START_DIR}/codegen/lib/runProgramNew>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/codegen/lib/runProgramNew>
    $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>)

# Specify library link dependencies for target "runProgramNew". CMake 
# generator expressions are used to create a CMakeLists.txt file that 
# supports multiple platforms with differently named system library 
# dependencies.
target_link_libraries(runProgramNew PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>
    OpenMP::OpenMP_C
    OpenMP::OpenMP_CXX)


###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET runProgramNew POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created STATIC library: $<TARGET_FILE:runProgramNew>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(runProgramNew)
endif()
