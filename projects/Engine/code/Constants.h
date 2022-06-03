#pragma once
#include <string>

static constexpr int DISPLAY_WIDTH = 800;
static constexpr int DISPLAY_HEIGHT = 800;
static constexpr std::string_view DISPLAY_NAME = "My 3D Renderer";

static constexpr float CAM_NEAR = 0.005f;
static constexpr float CAM_FAR = 150000.0f;
static constexpr float CAM_FOV = 90.0f;
static constexpr float CAM_SPEED = 0.03f;

//Cat
static constexpr std::string_view CAT_OBJ = "meshes/cat.obj";
static constexpr std::string_view CAT_PNG = "textures/cat.jpg";

//Circle
static constexpr std::string_view CIRCLE_OBJ = "meshes/circle.obj";
static constexpr std::string_view CIRCLE_PNG = "textures/circle.png";

//Minecraft Cube / uses SHAPE_CUBE
static constexpr std::string_view CUBE_PNG = "textures/cube2.png";

//Basic Shapes
static constexpr std::string_view SHAPE_TRIANGLE = "SHAPE_TRIANGLE";
static constexpr std::string_view SHAPE_CUBE = "SHAPE_CUBE";


//Shaders
static constexpr std::string_view SHADER_VERTEX_STANDARD = "shaders/Vertex_Standard.glsl";
static constexpr std::string_view SHADER_VERTEX_LEGACY = "shaders/Vertex_Legacy.glsl";

static constexpr std::string_view SHADER_FRAGMENT_UV = "shaders/Frag_UV.glsl";
static constexpr std::string_view SHADER_FRAGMENT_COLOR = "shaders/Frag_Color.glsl";
static constexpr std::string_view SHADER_FRAGMENT_UNLIT = "shaders/Frag_Unlit.glsl";

//Rasterizer Shaders

static constexpr std::string_view SHADER_VERTEX_SCREEN = "shaders/Vertex_Screen.glsl";
static constexpr std::string_view SHADER_FRAGMENT_SCREEN = "shaders/Frag_Screen.glsl";