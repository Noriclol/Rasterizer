#pragma once

#include "core/app.h"
#include "render/window.h"

#include "Camera.h"
#include "Transform.h"

//Local
#include "Input.h"
#include "GraphicsNode.h"
#include "LightNode.h"
#include "Constants.h"



class Application : public Core::App
{
public:

	Application() = default;

	bool Open() override;
	void Run() override;
	void Close() override {};
	void Exit() override {};

	~Application() = default;

private:

	//window
	Display::Window* window;

	//Camera
	Camera cam;

	//Input
	InputListener input = InputListener();
	Transform inputTransform;

};
