#--------------------------------------------------------------------------
# GraphicsLib project
#--------------------------------------------------------------------------

PROJECT(GraphicsLib)
FILE(GLOB GraphicsLib_headers code/*.h)
FILE(GLOB GraphicsLib_sources code/*.cc)

SET(files_headers ${GraphicsLib_headers})
SET(files_sources ${GraphicsLib_sources})

SOURCE_GROUP("Header Files" FILES ${files_headers})
SOURCE_GROUP("Source Files" FILES ${files_sources})

ADD_LIBRARY(GraphicsLib STATIC ${files_headers} ${files_sources})
TARGET_LINK_LIBRARIES(GraphicsLib core render MathLib)
ADD_DEPENDENCIES(GraphicsLib core render MathLib)

TARGET_INCLUDE_DIRECTORIES(GraphicsLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)