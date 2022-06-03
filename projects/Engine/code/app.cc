#include "config.h"
#include <cstring>
#include "app.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include "Renderer.h"
#include "Resource_Mesh.h"
#include "Screen.h"

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
		input.CameraSpeed = CAM_SPEED;
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




	//MODELS
	auto scale = 0.001f;

	auto GN_Ball = new GraphicsNode(CIRCLE_OBJ,  CIRCLE_PNG, SHADER_VERTEX_STANDARD, SHADER_FRAGMENT_UNLIT, Vector3::zero, scale);
	//auto GN_Box = new GraphicsNode(SHAPE_CUBE, CUBE_PNG, SHADER_VERTEX_STANDARD, SHADER_FRAGMENT_COLOR, Vector3::zero, scale);
	//auto GN_Cat = new GraphicsNode(CAT_OBJ,  SHADER_VERTEX_STANDARD, SHADER_FRAGMENT_UV, Vector3::zero, scale);




	//CAMERA

	//float aspect = DISPLAY_WIDTH / DISPLAY_HEIGHT;
	//cam = new Camera(aspect, CAM_NEAR, CAM_FAR, CAM_FOV);
	//cam->position =(Vector3(0, 0, -50));

	Vector3 camPosition = Vector3(0, 0, -2);

	Matrix4 perspecMat;
	perspecMat.ProjectionPerspec(0.005f, 150.0f, 75.0f);
	//perspecMat = perspecMat.Transpose();

	Matrix4 viewMat;
	viewMat.LookAt(camPosition, Vector3::zero, Vector3::up);;




	//INPUT BINDINGS

	//input.BindTransform(&GN_Cat->transform);
	//input.BindTransform(&GN_Box->transform);
	input.BindTransform(&GN_Ball->transform);


	//RENDERER

	const auto vertexShader = [](Vertex& vertex, Matrix4& model, Matrix4& view, Matrix4& projection) -> Vertex
	{
		const Vector3 position = (projection * view * model).Transpose() * vertex.position;
		return { position, vertex.normal, vertex.uv };
	};

	const auto fragmentShader = [this]()->Color3
	{
		//For now just spit out red
		return { 1, 0, 0 };
	};

	//Renderer renderer;
	//renderer.SetVertexShader(vertexShader);
	//renderer.SetFragmentShader(fragmentShader);

	//Screen screen = Screen(renderer);
	//screen.AddRenderableObject(GN_Ball);



	//running loop
	while (this->window->IsOpen())
	{
		// clearing framebuffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Listen for input
		input.KeyActionList();
		input.MouseActionList();


		if (input.CPURender)
		{
			//screen.Draw(viewMat.Transpose(), perspecMat);
		}
		else
		{
			GN_Ball->Draw(viewMat.Transpose(), perspecMat);
		}


		this->window->Update();
		this->window->SwapBuffers();
		
	}
}
