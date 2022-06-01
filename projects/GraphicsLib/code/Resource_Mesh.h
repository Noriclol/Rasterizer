#pragma once
#include <GL/glew.h>

#include <vector>
#include  <map>
#include <sstream>

#include "Vector3.h"
#include "S_Material.h"
#include "S_Color.h"
#include "S_Vertex.h"

class Matrix4;


/**
 * \ Handles the Initialization, storage, modification and usage of Mesh Data Loaded to it
 *
 */
class MeshResource
{
public:

	//Buffers
	std::vector<float> VertexBuffer;
	std::vector<unsigned int> IndexBuffer;

	unsigned int IndexBuffer_Handle;
	unsigned int VertexBuffer_Handle;

	MeshResource(const std::string& path);
	MeshResource(float size);
	MeshResource();

	void Init();
	void Draw() const;
	void Destroy();
	
	void Transform(Matrix4& transformMatrix);


	void VertexBufferCompile();

	bool ReadFile(const std::string& path);

	Vertex VertexConstruct(unsigned int vertex, unsigned int uv, unsigned int normal);
	bool VertexDoubleCheck(Vertex& vert, std::map<Vertex, unsigned int>& vertMap, unsigned int& inputResult);
	void VertexMapConstruct(std::map<Vertex, unsigned int>& vertexMap);


private:

	//VertexAttribs
	bool colorsEnabled = false;
	bool uvEnabled = false;
	bool normalsEnabled = false;
	int stride = 0;


	//vertexData for Attribs
	std::vector<Vector3> positions;
	std::vector<Vector3> normals;
	std::vector<Color4> colors;
	std::vector<Vector3> uvs;

	//IndexData for Attribs
	std::vector<int> vertexIndex;
	std::vector<int> normalIndex;
	std::vector<int> textureIndex;

};

