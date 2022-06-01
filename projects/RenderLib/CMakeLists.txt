#--------------------------------------------------------------------------
# RenderLib project
#--------------------------------------------------------------------------

PROJECT(RenderLib)
FILE(GLOB RenderLib_headers code/*.h)
FILE(GLOB RenderLib_sources code/*.cc)

SET(files_headers ${RenderLib_headers})
SET(files_sources ${RenderLib_sources})

SOURCE_GROUP("Header Files" FILES ${files_headers})
SOURCE_GROUP("Source Files" FILES ${files_sources})

ADD_LIBRARY(RenderLib STATIC ${files_headers} ${files_sources})
TARGET_LINK_LIBRARIES(RenderLib core render GraphicsLib MathLib)
ADD_DEPENDENCIES(RenderLib core render GraphicsLib MathLib)

TARGET_INCLUDE_DIRECTORIES(RenderLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/code/)