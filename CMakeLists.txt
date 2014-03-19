cmake_minimum_required(VERSION 2.8.9)

project(libccmodbus)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE} "-o3")

option(DEBUG_MODE "Debug or release?" ON)
if(DEBUG_MODE)
  set(CMAKE_BUILD_TYPE DEBUG)
else(DEBUG_MODE)
  set(CMAKE_BUILD_TYPE RELEASE)
endif(DEBUG_MODE)

option(LIBRARY_TYPE_SHARED "Static or shared?" ON)
if(LIBRARY_TYPE_SHARED)
  set(BUILD_SHARED_LIBS TRUE)
else(LIBRARY_TYPE_SHARED)
  set(BUILD_SHARED_LIBS FALSE)
endif(LIBRARY_TYPE_SHARED)

set(CMAKE_PREFIX_PATH /opt/Qt5.2.0/5.2.0/gcc/lib/cmake)
find_package(Qt5Network)

# Instruct CMake to run moc automatically when needed.
#set(CMAKE_AUTOMOC ON)
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(Code)

set(libccmodbus_Code
  Code/Communication/comm_interface.cc
  Code/Communication/Ethernet/eth_tcp.cc
  Code/Communication/RTU/serial_portrs_232.cc
)

add_library(ccmodbus
  ${libccmodbus_Code}
)

# Use the Network module from Qt 5.
qt5_use_modules(ccmodbus Network)

#add_subdirectory(tests)
#add_subdirectory(Doc)
