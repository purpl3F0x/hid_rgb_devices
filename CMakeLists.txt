cmake_minimum_required(VERSION 3.13)
project(asus_addressable_rgb)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE  "/O2")



include_directories("hidapi-0.7.0/hidapi/")
link_directories("./hidapi/Debug" debug)
link_directories("./hidapi/Release" optimized)

configure_file("./hidapi/Debug/hidapi.dll" ${PROJECT_BINARY_DIR} COPYONLY)

if (CMAKE_BUILD_TYPE EQUAL "DEBUG")
    configure_file("./hidapi/Debug/hidapi.dll" ${PROJECT_BINARY_DIR} COPYONLY)
elseif(CMAKE_BUILD_TYPE EQUAL "DEBUG")
    configure_file("./hidapi/Release/hidapi.dll" ${PROJECT_BINARY_DIR} COPYONLY)
endif (CMAKE_BUILD_TYPE EQUAL "DEBUG")

add_executable(hof_link hof_link.cpp)
add_executable(hid_test hid_devices.cpp hid_devices.hpp aura_hid.cpp aura_hid.hpp main.cpp galax_hof_link.cpp galax_hof_link.hpp)

