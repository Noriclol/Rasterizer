#include "config.h"
#include "Input.h"
#include <iostream>
#include "Matrix4.h"
#include "Vector3.h"
#define PI std::acosf(-1.0f)

InputListener::InputListener(): window(nullptr){}

void InputListener::setMouseInputMode()
{
	glfwSetInputMode((GLFWwindow*)window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void InputListener::SetWindow(Display::Window* newWindow)
{
	//std::cout << "SetWindow" << std::endl;
	window = newWindow;
}

void InputListener::BindTransform(Transform* transform)
{
	ctrlArr.push_back(transform);
}

void InputListener::UnBindTransform(Transform* transform)
{
	//not implemented
}

void InputListener::SetWindowSizeRef()
{
	window->GetSize(widthRef, heightRef);
}

//keyboard
void InputListener::KeyPress(int key, int scancode, int action, int mods) { // input listener

	//W
	if (key == GLFW_KEY_W && action == GLFW_PRESS && keyButtonActiveArr[0] == 0)   { keyButtonActiveArr[0] = 1; }
	if (key == GLFW_KEY_W && action == GLFW_RELEASE && keyButtonActiveArr[0] == 1) { keyButtonActiveArr[0] = 0; }

	//A
	if (key == GLFW_KEY_A && action == GLFW_PRESS && keyButtonActiveArr[1] == 0)   { keyButtonActiveArr[1] = 1; }
	if (key == GLFW_KEY_A && action == GLFW_RELEASE && keyButtonActiveArr[1] == 1) { keyButtonActiveArr[1] = 0; }

	//S
	if (key == GLFW_KEY_S && action == GLFW_PRESS && keyButtonActiveArr[2] == 0)   { keyButtonActiveArr[2] = 1; }
	if (key == GLFW_KEY_S && action == GLFW_RELEASE && keyButtonActiveArr[2] == 1) { keyButtonActiveArr[2] = 0; }

	//D
	if (key == GLFW_KEY_D && action == GLFW_PRESS && keyButtonActiveArr[3] == 0)   { keyButtonActiveArr[3] = 1; }
	if (key == GLFW_KEY_D && action == GLFW_RELEASE && keyButtonActiveArr[3] == 1) { keyButtonActiveArr[3] = 0; }

	//down/C
	if (key == GLFW_KEY_C && action == GLFW_PRESS && keyButtonActiveArr[4] == 0)	{ keyButtonActiveArr[4] = 1; }
	if (key == GLFW_KEY_C && action == GLFW_RELEASE && keyButtonActiveArr[4] == 1)	{ keyButtonActiveArr[4] = 0; }

	//up/Space
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && keyButtonActiveArr[5] == 0)	{ keyButtonActiveArr[5] = 1; }
	if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE && keyButtonActiveArr[5] == 1)	{ keyButtonActiveArr[5] = 0; }

	//toggle Wireframe/1
	if (key == GLFW_KEY_1 && action == GLFW_PRESS) 
	{

		if (keyButtonActiveArr[6] == 1) 
		{
			keyButtonActiveArr[6] = 0;
			std::cout << "Wireframe Set to Fill\n";
		}

		else if (keyButtonActiveArr[6] == 0) 
		{
			keyButtonActiveArr[6] = 1;
			std::cout << "Wireframe Set to Line\n";

		}
	}
	//toggle Renderer/2
	if (key == GLFW_KEY_2 && action == GLFW_PRESS) 
	{
		if (keyButtonActiveArr[7] == 1) {
			keyButtonActiveArr[7] = 0;
			//std::cout << keyButtonActiveArr[7];
		}

		else if (keyButtonActiveArr[7] == 0) {
			keyButtonActiveArr[7] = 1;
			//std::cout << keyButtonActiveArr[7];
		}
	}
	//toggle Shader/3
	if (key == GLFW_KEY_3 && action == GLFW_PRESS) 
	{
		if (keyButtonActiveArr[8] == 1) {
			keyButtonActiveArr[8] = 0;
			//std::cout << keyButtonActiveArr[7];
		}
		else if (keyButtonActiveArr[8] == 0) {
			     keyButtonActiveArr[8] = 1;
			//std::cout << keyButtonActiveArr[7];
		}
	}
}

//keyboard

//mouse

void InputListener::MousePress(int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS && mouseButtonActiveArr[0] == 0) { mouseButtonActiveArr[0] = 1; /*std::cout << "mb r" << std::endl;*/ }
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE && mouseButtonActiveArr[0] == 1) { mouseButtonActiveArr[0] = 0; }

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && mouseButtonActiveArr[1] == 0) { mouseButtonActiveArr[1] = 1; /*std::cout << "mb l" << std::endl;*/ }
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE && mouseButtonActiveArr[1] == 1) { mouseButtonActiveArr[1] = 0; }
}

void InputListener::MouseMove(double& xPos, double& yPos) {


	if (mouseButtonActiveArr[1] == 1) {
		if (firstMouse) 
		{
			lastX = xPos;
			lastY = yPos;
			firstMouse = false;
		}

		xOffset = xPos - lastX;
		yOffset = yPos - lastY;

		viewRotation[0] = yaw + xOffset / widthRef; //X
		viewRotation[1] = pitch + yOffset / heightRef; //Y

	}
	else
	{
		firstMouse = true;
		yaw += xOffset / widthRef;
		pitch += yOffset / heightRef;

		xOffset = 0;
		yOffset = 0;
	}
}

void InputListener::KeyActionList() 
{	//key actions to be performed
	//right now only used for movement as wireframe and renderer and shaderswitch gets handled in main render loop

	//WASD
	
	float speed = 0.05f;

	//W
	if (keyButtonActiveArr[0] == 1)
	{
		int i = 0;
		for (i; i < ctrlArr.size(); i++)
		{
			if (ctrlArr[i] == nullptr)
				return;

			ctrlArr[i]->Move(Vector3(Vector3::forward) * speed);

			auto pos = ctrlArr[i]->GetPos();
			std::cout << "modelTransform	x: " << std::to_string(pos.x) << " y: " << std::to_string(pos.y) << " z: " << std::to_string(pos.z) << "\n";
		}
	}

	//A
	if (keyButtonActiveArr[1] == 1)
	{
		int i = 0;
		for (i; i < ctrlArr.size(); i++)
		{
			if (ctrlArr[i] == nullptr)
				return;

			ctrlArr[i]->Move(Vector3(Vector3::right) * speed);

			auto pos = ctrlArr[i]->GetPos();
			std::cout << "modelTransform	x: " << std::to_string(pos.x) << " y: " << std::to_string(pos.y) << " z: " << std::to_string(pos.z) << "\n";
		}
	}

	//S
	if (keyButtonActiveArr[2] == 1)
	{
		int i = 0;
		for (i; i < ctrlArr.size(); i++)
		{
			if (ctrlArr[i] == nullptr)
				return;

			ctrlArr[i]->Move(Vector3(Vector3::forward) * -speed);

			auto pos = ctrlArr[i]->GetPos();
			std::cout << "modelTransform	x: " << std::to_string(pos.x) << " y: " << std::to_string(pos.y) << " z: " << std::to_string(pos.z) << "\n";
		}
	}

	//D
	if (keyButtonActiveArr[3] == 1)
	{
		int i = 0;
		for (i; i < ctrlArr.size(); i++)
		{
			if (ctrlArr[i] == nullptr)
				return;

			ctrlArr[i]->Move(Vector3(Vector3::right) * -speed);

			auto pos = ctrlArr[i]->GetPos();
			std::cout << "modelTransform	x: " << std::to_string(pos.x) << " y: " << std::to_string(pos.y) << " z: " << std::to_string(pos.z) << "\n";
		}
	}


	//UP
	if (keyButtonActiveArr[4] == 1)
	{
		int i = 0;
		for (i; i < ctrlArr.size(); i++)
		{
			if (ctrlArr[i] == nullptr)
				return;

			ctrlArr[i]->Move(Vector3(Vector3::up) * speed);

			auto pos = ctrlArr[i]->GetPos();
			std::cout << "modelTransform	x: " << std::to_string(pos.x) << " y: " << std::to_string(pos.y) << " z: " << std::to_string(pos.z) << "\n";
		}
	}
	//DOWN
	if (keyButtonActiveArr[5] == 1)
	{
		int i = 0;
		for (i; i < ctrlArr.size(); i++)
		{
			if (ctrlArr[i] == nullptr)
				return;

			ctrlArr[i]->Move(Vector3(Vector3::up) * -speed);

			auto pos = ctrlArr[i]->GetPos();
			std::cout << "modelTransform	x: " << std::to_string(pos.x) << " y: " << std::to_string(pos.y) << " z: " << std::to_string(pos.z) << "\n";
		}
	}

	//Place to implement Code that should run on different buttons

	//Wireframe

	if (keyButtonActiveArr[6] == 0) {
		//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	if (keyButtonActiveArr[6] == 1) {
		
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	//rasterizer

	
}

void InputListener::MouseActionList() {
	
	if(mouseButtonActiveArr[1] == 1) 
	{
		int i = 0;
		for (i; i < ctrlArr.size(); i++)
		{
			if (ctrlArr[i] == nullptr)
				return;

			ctrlArr[i]->RotateY(viewRotation[0]);
			ctrlArr[i]->RotateX(viewRotation[1]);

			//std::cout << "X: " << viewRotation[0] << std::endl;
			//std::cout << "Y: " << viewRotation[1] << std::endl;
			//std::cout << "---------" << std::endl;
		}
	}

	if (mouseButtonActiveArr[1] == 0) 
	{
		int i = 0;
		for (i; i < ctrlArr.size(); i++)
		{
			if (ctrlArr[i] == nullptr)
				return;

			ctrlArr[i]->RotateY(viewRotation[0]);
			ctrlArr[i]->RotateX(viewRotation[1]);
		}
	}
}
	

#undef PI