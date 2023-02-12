# Install script for directory: C:/Users/Administrador/ncs/v1.8.0/zephyr/subsys

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Zephyr-Kernel")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Users/Administrador/ncs/v1.8.0/toolchain/opt/bin/arm-none-eabi-objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/debug/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/logging/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/fs/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/ipc/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/mgmt/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/random/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/storage/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/fb/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/portability/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/pm/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/stats/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/task_wdt/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/testsuite/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/tracing/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/canbus/cmake_install.cmake")
  include("C:/Users/Administrador/Documents/Nordic/Project_v1/bls-hsm/build/spm/zephyr/subsys/modbus/cmake_install.cmake")

endif()
