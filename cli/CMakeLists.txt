# SPDX-License-Identifier: Apache-2.0


cmake_minimum_required(VERSION 3.13.1)
list(APPEND ZEPHYR_EXTRA_MODULES
   ${CMAKE_CURRENT_SOURCE_DIR}/../secure_module)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(cli)

add_definitions(-DNRF)

target_sources(app PRIVATE src/main.c
../lib/bls_hsm_ns.c
../lib/common.c
)

zephyr_library_include_directories(
  ../lib/
  )

add_library(testlib STATIC IMPORTED)
target_link_libraries(app PUBLIC ${APPLICATION_SOURCE_DIR}/../lib/libblst.a)