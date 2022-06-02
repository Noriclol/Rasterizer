#pragma once
#include <string>

static int DISPLAY_WIDTH = 800;
static int DISPLAY_HEIGHT = 800;
static std::string DISPLAY_NAME = "My 3D Renderer";

static float CAM_NEAR = 0.005f;
static float CAM_FAR = 150000.0f;
static float CAM_FOV = 90.0f;
static float CAM_SPEED = 0.03f;
//Cat
const std::string CAT_OBJ = "meshes/cat.obj";
const std::string CAT_PNG = "textures/cat.jpg";

//Circle
const std::string CIRCLE_OBJ = "meshes/circle.obj";
const std::string CIRCLE_PNG = "textures/circle.png";

//Minecraft Cube / uses SHAPE_CUBE
const std::string CUBE_PNG = "textures/cube2.png";

//Basic Shapes
const std::string SHAPE_TRIANGLE = "SHAPE_TRIANGLE";
const std::string SHAPE_CUBE = "SHAPE_CUBE";


//Shaders
const std::string SHADER_VERTEX_STANDARD = "shaders/Vertex_Standard.glsl";
const std::string SHADER_VERTEX_LEGACY = "shaders/Vertex_Legacy.glsl";

const std::string SHADER_FRAGMENT_UV = "shaders/Frag_UV.glsl";
const std::string SHADER_FRAGMENT_COLOR = "shaders/Frag_Color.glsl";
const std::string SHADER_FRAGMENT_UNLIT = "shaders/Frag_Unlit.glsl";