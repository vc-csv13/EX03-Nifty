# Minimum version can be no higher than 3.5 as Ubuntu package management uses this version.
cmake_minimum_required(VERSION 3.5)

project (EX03-Nifty)

set(SOURCE_PREFIX "nifty")
set(EXEC_NAME "Nifty")
set(CMAKE_CXX_STANDARD 11)

if(EXISTS ${CMAKE_HOME_DIRECTORY}/csv13-lib/CMakeLists.txt)
    include(csv13-lib/CMakeLists.txt)
    add_dependencies(${EXEC_NAME}_GTest ${EXEC_NAME})
elseif(EXISTS /usr/local/csv13-lib/CMakeLists.txt)
    include(/usr/local/csv13-lib/CMakeLists.txt)
    add_dependencies(${EXEC_NAME}_GTest ${EXEC_NAME})
else()
    add_custom_target(add-submodules ALL git clone https://github.com/vc-csv13/csv13-lib.git)
endif()