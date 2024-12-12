# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ProiectQT_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ProiectQT_autogen.dir\\ParseCache.txt"
  "ProiectQT_autogen"
  )
endif()
