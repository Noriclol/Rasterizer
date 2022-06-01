#include "GraphicsNode.h"

#include <iostream>
#include <GL/glew.h>
#include "Camera.h"
#include "Input.h"



GraphicsNode::GraphicsNode
(const std::string& modelPath, const std::string& texturePath, const std::string& vShaderPath, const std::string& fShaderPath, const Vector3& pos, const float scale)
: mesh(nullptr), texture(nullptr), shader(nullptr)

{
	//Initialize model, texture and Shaders
	this->shader = std::make_shared<ShaderResource>(fShaderPath, vShaderPath);

	//allows for creation of simple meshes instead of loaded .obj files
	if (modelPath == "SHAPE_CUBE") { this->mesh = std::make_shared<MeshResource>(scale); }
	else if (modelPath == "SHAPE_TRIANGLE") { this->mesh = std::make_shared<MeshResource>(); }
	else { this->mesh = std::make_shared<MeshResource>(modelPath); }
	
	this->texture = std::make_shared<TextureResource>(texturePath);

	transform.SetPos(pos);
	transform.SetScale(Vector3(scale, scale, scale));

	_uniform = glGetUniformLocation(shader->program, "mvp");
}

GraphicsNode::GraphicsNode(const std::string& modelPath, const std::string& vShaderPath, const std::string& fShaderPath, const Vector3& pos, const float scale)
: mesh(nullptr), shader(nullptr)
{

	std::cout << "\n__Init Graphics Node_BEGIN_\n\n";

	this->shader = std::make_shared<ShaderResource>(fShaderPath, vShaderPath);

	//allows for creation of simple meshes instead of loaded .obj files
	if (modelPath == "SHAPE_CUBE")			{ this->mesh = std::make_shared<MeshResource>(scale); }
	else if (modelPath == "SHAPE_TRIANGLE")	{ this->mesh = std::make_shared<MeshResource>();  }
	else								{ this->mesh = std::make_shared<MeshResource>(modelPath); }
	
	

	transform.SetPos(pos);
	transform.SetScale(Vector3(scale, scale, scale));

	_uniform = glGetUniformLocation(shader->program, "mvp");


	std::cout << "\n\n__Init Graphics Node_COMPLETE_\n";
}

void GraphicsNode::Draw(Matrix4 view, Matrix4 projection)
{
	//GLenum err;
	Matrix4 model = transform.transform;
	const Matrix4 modelview = view * model;

	auto mvp = projection * view  * transform.transform;

	shader->Bind();

	//Uniforms
	shader->SetValue("Projection", projection);
	shader->SetValue("ModelView", modelview);
	shader->SetValue("Model", model);
	shader->SetUniformMatrix4fv(_uniform, mvp);

	mesh->Draw();

	shader->Unbind();
}

void GraphicsNode::DrawSimple()
{


	// do stuff
	
}





