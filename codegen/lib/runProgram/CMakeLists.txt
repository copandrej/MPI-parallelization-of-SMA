###########################################################################
# CMakeLists.txt generated for component runProgram
# Product type: STATIC library
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(runProgram)

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

# Definition of target "runProgram".
add_library(runProgram STATIC ${START_DIR}/codegen/lib/runProgram/coder_posix_time.c
    ${START_DIR}/codegen/lib/runProgram/runProgram_data.c
    ${START_DIR}/codegen/lib/runProgram/rt_nonfinite.c
    ${START_DIR}/codegen/lib/runProgram/rtGetNaN.c
    ${START_DIR}/codegen/lib/runProgram/rtGetInf.c
    ${START_DIR}/codegen/lib/runProgram/runProgram_initialize.c
    ${START_DIR}/codegen/lib/runProgram/runProgram_terminate.c
    ${START_DIR}/codegen/lib/runProgram/runProgram.c
    ${START_DIR}/codegen/lib/runProgram/tic.c
    ${START_DIR}/codegen/lib/runProgram/timeKeeper.c
    ${START_DIR}/codegen/lib/runProgram/rand.c
    ${START_DIR}/codegen/lib/runProgram/eml_rand_mt19937ar.c
    ${START_DIR}/codegen/lib/runProgram/Get_Functions_SMA.c
    ${START_DIR}/codegen/lib/runProgram/linspace.c
    ${START_DIR}/codegen/lib/runProgram/spline.c
    ${START_DIR}/codegen/lib/runProgram/ppval.c
    ${START_DIR}/codegen/lib/runProgram/diff.c
    ${START_DIR}/codegen/lib/runProgram/mean.c
    ${START_DIR}/codegen/lib/runProgram/unifrnd.c
    ${START_DIR}/codegen/lib/runProgram/abs.c
    ${START_DIR}/codegen/lib/runProgram/sum.c
    ${START_DIR}/codegen/lib/runProgram/mod.c
    ${START_DIR}/codegen/lib/runProgram/toc.c
    ${START_DIR}/codegen/lib/runProgram/sprintf.c
    ${START_DIR}/codegen/lib/runProgram/CoderTimeAPI.c
    ${START_DIR}/codegen/lib/runProgram/eml_rand_mt19937ar_stateful.c
    ${START_DIR}/codegen/lib/runProgram/pause.c
    ${START_DIR}/codegen/lib/runProgram/sort.c
    ${START_DIR}/codegen/lib/runProgram/sortIdx.c
    ${START_DIR}/codegen/lib/runProgram/atanh.c
    ${START_DIR}/codegen/lib/runProgram/SMA.c
    ${START_DIR}/codegen/lib/runProgram/runProgram_emxutil.c)

# Set properties for target "runProgram".
set_target_properties(runProgram PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/codegen/lib/runProgram/$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/codegen/lib/runProgram/$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/codegen/lib/runProgram/$<0:>")

# Specify language features required for target "runProgram".
target_compile_features(runProgram PUBLIC c_std_99)

# Specify compiler preprocessor definitions for target "runProgram".
target_compile_definitions(runProgram PRIVATE -DMODEL=runProgram)

# Specify include directories for target "runProgram".
target_include_directories(runProgram PUBLIC $<BUILD_INTERFACE:${START_DIR}/codegen/lib/runProgram>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/codegen/lib/runProgram>
    $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>)

# Specify library link dependencies for target "runProgram". CMake 
# generator expressions are used to create a CMakeLists.txt file that 
# supports multiple platforms with differently named system library 
# dependencies.
target_link_libraries(runProgram PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>
    OpenMP::OpenMP_C
    OpenMP::OpenMP_CXX)


###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET runProgram POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created STATIC library: $<TARGET_FILE:runProgram>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(runProgram)
endif()
