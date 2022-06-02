#pragma once
#include "config.h"
#include "render/window.h"
#include "GraphicsNode.h"
#include <vector>

class InputListener {
private:
	Display::Window* window;
	int widthRef, heightRef;

	std::vector<Transform*> ctrlArr;
	Transform transformChange;
	Vector3 viewRotation;

	

	//mouse variables
	bool firstMouse = true;
	float lastX = 1000, lastY = 1000;
	float xOffset, yOffset;
	float yaw = 0, pitch = 0;
	float yawBuffer = 0, pitchBuffer = 0;

	int count = 0;
public:
	float CameraSpeed = 0;
	bool CPURender = false;

	bool keyButtonActiveArr[9] =	{	0,0,0,0,0,
										0,0,0,0
									};
	bool mouseButtonActiveArr[2] = { 0,0 };

	InputListener();
	void setMouseInputMode();
	void SetWindow(Display::Window* window);
	void BindTransform(Transform* transform);
	void UnBindTransform(Transform* transform);
	void SetWindowSizeRef();
	void KeyPress(int key, int scancode, int action, int mods);
	void KeyActionList();
	void SetKeyPressFunction();

	void MouseActionList();
	void MousePress(int button, int action, int mods);
	void MouseMove(double& xPos, double& yPos);
	void SetMousePressFunction();
	void SetMouseMoveFunction();
};
