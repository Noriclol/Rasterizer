#--------------------------------------------------------------------------
# MathLib project
#--------------------------------------------------------------------------

PROJECT(MathLib)
FILE(GLOB MathLib_headers code/*.h)
FILE(GLOB MathLib_sources code/*.cc)

SET(files_headers ${MathLib_headers})
SET(files_sources ${MathLib_sources})


SOURCE_GROUP("Header Files" FILES ${files_headers})
SOURCE_GROUP("Source Files" FILES ${files_sources})

ADD_LIBRARY(MathLib STATIC ${files_headers} ${files_sources})
TARGET_LINK_LIBRARIES(MathLib core render)
ADD_DEPENDENCIES(MathLib core render)

TARGET_INCLUDE_DIRECTORIES(MathLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)