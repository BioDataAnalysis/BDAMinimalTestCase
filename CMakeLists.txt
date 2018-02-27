#
# Developed by:  Mario Emmenlauer (mario@emmenlauer.de)
#                Balanstrasse 43, 81669 Munich
#                http://www.biodataanalysis.de/
#
# With contributions by: Kai Wolf (kwolf@biodataanalysis.de)
#
#
# Copyright (c) 2014-2017, BioDataAnalysis GmbH
# All Rights Reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are not permitted. All information contained herein
# is, and remains the property of BioDataAnalysis GmbH.
# Dissemination of this information or reproduction of this material
# is strictly forbidden unless prior written permission is obtained
# from BioDataAnalysis GmbH.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(BDAMinimalTestCase)
set(COMPANY "BioDataAnalysis GmbH")
set(COPYRIGHT "Copyright (c) 2017 BioDataAnalysis GmbH. All rights reserved.")

find_package(Boost 1.60.0 COMPONENTS program_options REQUIRED)

set(SOURCES
    src/MinimalTestCase.cc)

add_executable(MinimalTestCase ${SOURCES})

set_target_properties(MinimalTestCase PROPERTIES
  POSITION_INDEPENDENT_CODE ON
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS NO)

target_compile_options(MinimalTestCase
  PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-Wall;-pedantic;-Wextra>)

target_compile_definitions(MinimalTestCase
  PUBLIC
    BOOST_ALL_NO_LIB=1 BOOST_DYN_LINK=1
  PRIVATE
    $<$<CONFIG:Debug>:DEBUG;_DEBUG;_DEBUG_>
    $<$<CXX_COMPILER_ID:MSVC>:NOMINMAX>)

target_include_directories(MinimalTestCase
  PRIVATE
    ${Boost_INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(MinimalTestCase
  PRIVATE
    ${Boost_LIBRARIES})

