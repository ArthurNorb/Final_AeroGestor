# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "AeroGestor_autogen"
  "CMakeFiles\\AeroGestor_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\AeroGestor_autogen.dir\\ParseCache.txt"
  )
endif()
