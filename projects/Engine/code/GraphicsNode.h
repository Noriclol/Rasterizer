#pragma once

#include "Camera.h"
#include "Transform.h"
#include "S_Material.h"
#include "Resource_Mesh.h"
#include "Resource_Shader.h"
#include "Resource_Texture.h"
#include "LightNode.h"

class GraphicsNode
{
public:

	GraphicsNode() = default;
	GraphicsNode(const std::string& modelPath, const std::string& texturePath, const std::string& vShaderPath, const std::string& fShaderPath, const Vector3& pos = Vector3::zero,  const float scale = 0.2f);
	GraphicsNode(const std::string& modelPath, const std::string& vShaderPath, const std::string& fShaderPath, const Vector3& pos = Vector3::zero, const float scale = 0.2f);

	~GraphicsNode()
	{
		mesh->Destroy();
	}


	//Functions
	void Draw(Matrix4 view, Matrix4 projection);
	void DrawSimple();


	//Setters
	void SetMesh(MeshResource& mesh)			{ this->mesh	= std::make_shared<MeshResource>(mesh); }
	void SetTexture(TextureResource& texture)	{ this->texture = std::make_shared<TextureResource>(texture); }
	void SetShader(ShaderResource& shader)		{ this->shader	= std::make_shared<ShaderResource>(shader); }

	//Getters
	std::shared_ptr<MeshResource> GetMesh()			const { return std::shared_ptr(mesh); }
	std::shared_ptr<TextureResource> GetTexture()	const { return std::shared_ptr(texture); }
	std::shared_ptr<ShaderResource> GetShader()		const { return std::shared_ptr(shader); }



	Transform transform;
	Material material = Material();

	//Light
	LightNode* light;
	int _uniform;

private:

	//Mesh
	std::shared_ptr< MeshResource> mesh;
	std::shared_ptr< TextureResource> texture;
	std::shared_ptr< ShaderResource> shader;



};