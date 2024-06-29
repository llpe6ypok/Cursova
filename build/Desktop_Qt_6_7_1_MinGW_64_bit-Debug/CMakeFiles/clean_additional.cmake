# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\EigenCalculator_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EigenCalculator_autogen.dir\\ParseCache.txt"
  "EigenCalculator_autogen"
  )
endif()
