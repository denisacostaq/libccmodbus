cmake_minimum_required(VERSION 2.8.9)

project(libccmodbus)

set(libccmodbus_VERSION_MAJOR 0)
set(libccmodbus_VERSION_MINOR 0)
set(libccmodbus_VERSION_PATCH 0)
#configure_file(
#"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
#"${PROJECT_BINARY_DIR}/TutorialConfig.h"
#)
#include_directories("${PROJECT_BINARY_DIR}")

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE} "-o3")


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
    "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(warnings "-Wall -Wextra -Werror")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(warnings "/W4 /WX /EHsc")
endif()
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${warnings}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}")


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

option(ETHERNET_ENGINE "What is the selected engine?" OFF)
if(ETHERNET_ENGINE)
  set(ENGINE_SRC
      Code/Communication/Ethernet/qtcp_socket_adapter.cc)
endif(ETHERNET_ENGINE)

include_directories(Code)

set(libccmodbus_Code
  Code/Communication/comm_interface.cc
  Code/Communication/comm_adapter_interface.cc
  ${ENGINE_SRC}
  Code/Communication/Ethernet/tcp_socket.cc
  Code/Communication/RTU/serial_portrs_232.cc
  Code/Communication/RTU/qserial_port_adapter.cc
  Code/modbus_client.cc
  Code/modbus_interface.cc
  Code/modbus_tcp.cc
  Code/modbus_factory.cc
)

add_library(ccmodbus
  ${libccmodbus_Code}
)

# Use the Network module from Qt 5.
qt5_use_modules(ccmodbus Network SerialPort)

#CMAKE_INSTALL_PREFIX(/tmp)
#add_subdirectory(tests)
#add_subdirectory(Doc)

install(TARGETS ccmodbus DESTINATION lib)
install(FILES Code/modbus_point.h DESTINATION include)
#install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

include(CMakeCpack.txt)
include(Doc/CMakeDoc.txt)

