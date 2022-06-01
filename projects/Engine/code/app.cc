#include "config.h"
#include <cstring>
#include "app.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "Resource_Mesh.h"

using namespace Display;
using namespace std;

bool Application::Open()
{
	App::Open();

	this->window = new Display::Window;

	if (this->window->Open())
	{
		//set size and title
		this->window->SetSize(DISPLAY_WIDTH, DISPLAY_HEIGHT);
		this->window->SetTitle(DISPLAY_NAME);



		// INPUT

		input.SetWindow(window);
		input.SetWindowSizeRef();
		input.setMouseInputMode();
		window->SetMousePressFunction([this](int button, int action, int mods) {
			std::cout << "MousePress Activated" << std::endl;
			input.MousePress(button, action, mods);
		});
		window->SetMouseMoveFunction([this](double xPos, double yPos) {
			//std::cout << "\nX: " << xPos << " Y: " << yPos;
			input.MouseMove(xPos, yPos);
		});
		window->SetKeyPressFunction([this](int key, int scancode, int action, int mods) {
			//std::cout << "KeyPress Activated" << std::endl;
			input.KeyPress(key, scancode, action, mods);
		});


		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		return true;
	}
	return false;
}



void Application::Run()
{
	//culling and depth // Handled by OpenGL
	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);


	//Models

	//auto GN_Ball = new GraphicsNode(CIRCLE_OBJ, SHADER_VERTEX_STANDARD, SHADER_FRAGMENT_COLOR);
	//auto GN_Box = new GraphicsNode(SHAPE_CUBE, SHADER_VERTEX_LEGACY, SHADER_FRAGMENT_COLOR);
	auto GN_Cat = new GraphicsNode(CAT_OBJ, SHADER_VERTEX_LEGACY, SHADER_FRAGMENT_COLOR);


	//Camera
	cam = Camera(CAM_NEAR, CAM_FAR, CAM_FOV);
	cam.LookAt();
	cam.position = Vector3(0, 0, 3);






	//bind Input;
	//input.BindTransform(&GN_Cat->transform);
	//input.BindTransform(&GN_Box->transform);
	//input.BindTransform(&GN_Ball->transform);

	//SoftwareRenderer Pass Lambda functions
	//SoftwareRenderer renderer;
	//renderer.frameBuffer.SetFrameBufferSize(1024, 1024);
	//renderer.SetVertexShader([this](const Uniforms& uniform, const VertexRaw& v, Vector3& position, Vector3& uv, Vector3& normal, Vector3& worldPosition)
	//{
	//should use transpose * mvp
	//	position = *uniform.mvp * v.Position();
	//	worldPosition = *(uniform.m) * v.Position();
	//	uv = v.Texture();
	//	normal = (*(uniform.n) * v.Normal()).normalize();
	//});
	//renderer.SetFragmentShader([this](const Uniforms& uniform, const Vector3& position, const Vector3& uv, const Vector3& normal, const Vector3& worldPosition, Color3& outColor)
	//{
	//	Vector3 L = (*uniform.lPos - position).normalize();
	//	Vector3 V = (*uniform.cPos - position).normalize();
	//	Vector3 H = (L + V).normalize();
	//	Color3 colorMix = *uniform.dColor + uniform.texture->Sample(uv);
	//	Color3 D = colorMix * L.DotProduct(normal) * *uniform.lColor;
	//	Color3 S = *uniform.sColor * powf(normal.DotProduct(H), uniform.shine);
	//	outColor = *uniform.aColor + D + S;
	//});

	//running loop
	while (this->window->IsOpen())
	{
		// clearing framebuffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Listen for input
		input.KeyActionList();
		input.MouseActionList();


		//GN_Box->Draw(cam.View, cam.Perspective);
		GN_Cat->Draw(cam.View, cam.Perspective);
		//GN_Ball->Draw(cam.View, cam.Perspective);


		this->window->Update();
		this->window->SwapBuffers();
		
	}
}