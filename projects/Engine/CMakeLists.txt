#--------------------------------------------------------------------------
# Engine project
#--------------------------------------------------------------------------

PROJECT(Engine)
FILE(GLOB Engine_headers code/*.h)
FILE(GLOB Engine_sources code/*.cc)
FILE(GLOB Engine_shaders ../../bin/shaders/*.glsl)

SET(files_headers ${Engine_headers})
SET(files_sources ${Engine_sources})
SET(files_shaders ${Engine_shaders})

SOURCE_GROUP("Header Files" FILES ${Engine_headers})
SOURCE_GROUP("Source Files" FILES ${Engine_sources})
SOURCE_GROUP("Shaders" FILES ${Engine_shaders})

ADD_EXECUTABLE(Engine ${Engine_headers} ${Engine_sources} ${Engine_shaders})
TARGET_LINK_LIBRARIES(Engine core render MathLib GraphicsLib RenderLib)
ADD_DEPENDENCIES(Engine core render MathLib GraphicsLib RenderLib)

ADD_CUSTOM_COMMAND(
	TARGET Engine POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/res/
	${CMAKE_SOURCE_DIR}/bin/
)

SET_PROPERTY (DIRECTORY PROPERTY VS_STARTUP_PROJECT "Engine")

SET_TARGET_PROPERTIES(Engine PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/)