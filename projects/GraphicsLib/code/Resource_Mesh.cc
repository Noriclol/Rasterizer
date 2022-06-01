#include "Resource_Mesh.h"
#include "Vector3.h"
#include "Matrix4.h"
#include "S_Color.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "S_Vertex.h"
//Rendering

/**
 * Create Mesh Using Filepath
 */
MeshResource::MeshResource(const std::string& path)
{
	std::cout << "\n__Init Mesh Resource_.obj BEGIN_\n\n";


	colorsEnabled = false;
	if (ReadFile(path))
	{
		VertexBufferCompile();
		Init();
		std::cout << "Mesh found at path and Initialized\n";
	}
	else
	{
		std::cout << "No Valid Mesh at path\n";
	}

	std::cout << "\n\n__Init Mesh Resource_.obj COMPLETE_\n";
}

MeshResource::MeshResource(float size)
{
	std::cout << "\n__Init Mesh Resource_cube BEGIN_\n\n";

	normalsEnabled = false;
	uvEnabled = false;
	colorsEnabled = false;
	//front
	positions.push_back(Vector3(-size, -size, size)); //A0  0
	positions.push_back(Vector3(-size, size, size)); //B1  1
	positions.push_back(Vector3(size, -size, size)); //C2 2 
	positions.push_back(Vector3(size, size, size)); //D3 3
	//back
	positions.push_back(Vector3(-size, -size, -size)); //F5 4
	positions.push_back(Vector3(-size, size, -size));  //E4 5
	positions.push_back(Vector3(size, -size, -size)); //H7 6
	positions.push_back(Vector3(size, size, -size)); //G6 7

	//top
	positions.push_back(Vector3(-size, size, size)); //B1 8
	positions.push_back(Vector3(-size, size, -size)); //F5 9
	positions.push_back(Vector3(size, size, size)); //D3 10
	positions.push_back(Vector3(size, size, -size)); //H7 11
	//bottom
	positions.push_back(Vector3(-size, -size, -size));  //E4 12
	positions.push_back(Vector3(-size, -size, size)); //A0 13
	positions.push_back(Vector3(size, -size, -size)); //G6 14
	positions.push_back(Vector3(size, -size, size)); //C2 15

	//left
	positions.push_back(Vector3(-size, -size, -size));  //E4 16
	positions.push_back(Vector3(-size, size, -size)); //F5 17
	positions.push_back(Vector3(-size, -size, size)); //A0 18
	positions.push_back(Vector3(-size, size, size)); //B1 19
	//right
	positions.push_back(Vector3(size, -size, size)); //C2 20
	positions.push_back(Vector3(size, size, size)); //D3 21
	positions.push_back(Vector3(size, -size, -size)); //G6 22
	positions.push_back(Vector3(size, size, -size)); //H7 23


	if (uvEnabled) {
		//front
		uvs.push_back(Vector3(0.3333f, 0.5f));
		uvs.push_back(Vector3(0.3333f, 0.75f));
		uvs.push_back(Vector3(0.6666f, 0.5f));
		uvs.push_back(Vector3(0.6666f, 0.75f));

		//back
		uvs.push_back(Vector3(0.6666f, 0.25f));
		uvs.push_back(Vector3(0.6666f, 0.0f));
		uvs.push_back(Vector3(0.3333f, 0.25f));
		uvs.push_back(Vector3(0.3333f, 0.0f));

		//top
		uvs.push_back(Vector3(0.3333f, 0.75f));
		uvs.push_back(Vector3(0.3333f, 1.0f));
		uvs.push_back(Vector3(0.6666f, 0.75f));
		uvs.push_back(Vector3(0.6666f, 1.0f));

		//bottom
		uvs.push_back(Vector3(0.3333f, 0.25f));
		uvs.push_back(Vector3(0.3333f, 0.5f));
		uvs.push_back(Vector3(0.6666f, 0.25f));
		uvs.push_back(Vector3(0.6666f, 0.5f));

		//left
		uvs.push_back(Vector3(0.0f, 0.5f));
		uvs.push_back(Vector3(0.0f, 0.75f));
		uvs.push_back(Vector3(0.3333f, 0.5f));
		uvs.push_back(Vector3(0.3333f, 0.75f));

		//right
		uvs.push_back(Vector3(0.6666f, 0.5f));
		uvs.push_back(Vector3(0.6666f, 0.75f));
		uvs.push_back(Vector3(1.0f, 0.5f));
		uvs.push_back(Vector3(1.0f, 0.75f));

	}


	//front
	IndexBuffer.push_back(1); IndexBuffer.push_back(0); IndexBuffer.push_back(2);
	IndexBuffer.push_back(2); IndexBuffer.push_back(3); IndexBuffer.push_back(1);

	//back
	IndexBuffer.push_back(4); IndexBuffer.push_back(5); IndexBuffer.push_back(7);
	IndexBuffer.push_back(7); IndexBuffer.push_back(6); IndexBuffer.push_back(4);

	//top
	IndexBuffer.push_back(9); IndexBuffer.push_back(8); IndexBuffer.push_back(10);
	IndexBuffer.push_back(10); IndexBuffer.push_back(11); IndexBuffer.push_back(9);

	//bottom
	IndexBuffer.push_back(13); IndexBuffer.push_back(12); IndexBuffer.push_back(14);
	IndexBuffer.push_back(14); IndexBuffer.push_back(15); IndexBuffer.push_back(13);


	//left
	IndexBuffer.push_back(17); IndexBuffer.push_back(16); IndexBuffer.push_back(18);
	IndexBuffer.push_back(18); IndexBuffer.push_back(19); IndexBuffer.push_back(17);

	//right
	IndexBuffer.push_back(21); IndexBuffer.push_back(20); IndexBuffer.push_back(22);
	IndexBuffer.push_back(22); IndexBuffer.push_back(23); IndexBuffer.push_back(21);

	VertexBufferCompile();
	std::cout << "Indexbuffer size: " << IndexBuffer.size() << "\n";
	Init();

	std::cout << "\n\n__Init Mesh Resource_cube COMPLETE_\n";
}

MeshResource::MeshResource()
{
	std::cout << "\n__Init Mesh Resource_triangle BEGIN_\n\n";

	normalsEnabled = false;
	uvEnabled = false;
	colorsEnabled = true;

	positions.push_back(Vector3(-0.5, -0.5, -1)); //A0  0
	positions.push_back(Vector3(-0, 0.5, -1)); //B1  1
	positions.push_back(Vector3(0.5f, -0.5f, -1));

	if (colorsEnabled)
	{
		colors.push_back(Color4(1, 0, 0, 1));
		colors.push_back(Color4(0, 1, 0, 1));
		colors.push_back(Color4(0, 0, 1, 1));
	}

	VertexBufferCompile();

	Init();

	std::cout << "\n\n__Init Mesh Resource_triangle COMPLETE_\n";
}


void MeshResource::Init()
{


	GLenum v, i;

	//Generating Buffers
	glGenBuffers(1, &VertexBuffer_Handle);
	v = glGetError();

	glGenBuffers(1, &IndexBuffer_Handle);
	i = glGetError();

	std::cout << "Generating Buffers:	Vertex: " << std::to_string(v) << "	Index: " << std::to_string(i) << "\n";


	//Binding Buffers
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer_Handle);
	v = glGetError();

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer_Handle);
	i = glGetError();

	std::cout << "Binding Buffers:	Vertex: " << std::to_string(v) << "	Index: " << std::to_string(i) << "\n";


	//Copy Retrieved BufferData into GL BufferObjects
	auto VertexBufferSize = sizeof(GLfloat) * VertexBuffer.size();
	auto IndexBufferSize = sizeof(GLfloat) * IndexBuffer.size();

	glBufferData(GL_ARRAY_BUFFER, VertexBufferSize, &VertexBuffer[0], GL_STATIC_DRAW);
	v = glGetError();

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, IndexBufferSize, &IndexBuffer[0], GL_STATIC_DRAW);
	i = glGetError();

	std::cout << "Setting Buffer Data:	Vertex: " << std::to_string(v) << "	Index: " << std::to_string(i) << "\n";
}


/**
 * \Main Draw Function for Mesh
 */
void MeshResource::Draw() const
{
	//std::cout << "\n\n___Draw_BEGIN__\n";
	unsigned int totLen = 0;
	auto glStride = sizeof(GLfloat) * stride;
	GLenum error;


	//std::cout << "\n__Buffers Bind and Update Data_BEGIN_\n\n";

	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer_Handle); //1282
	//error = glGetError();
	//std::cout << "Binding VertexBuffer_Handle to GL_ARRAY BUFFER: " << std::to_string(error) << "\n";

	glBufferSubData(GL_ARRAY_BUFFER, NULL, sizeof(GLfloat) * VertexBuffer.size(), (GLvoid*)VertexBuffer.data());
	//error = glGetError();
	//std::cout << "Fill Buffer with Data" << std::to_string(error) << "\n";

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IndexBuffer_Handle);
	//error = glGetError();
	//std::cout << "Binding VertexBuffer_Handle to GL_ARRAY BUFFER: " << std::to_string(error) << "\n";

	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, NULL, sizeof(GLfloat) * IndexBuffer.size(), (GLvoid*)IndexBuffer.data());
	//error = glGetError();
	//std::cout << "Fill Buffer with Data" << std::to_string(error) << "\n";


	//std::cout << "\n__Buffers Bind and Update Data_COMPLETE_\n\n";





	//Pass Enabled Vertex attributes to vertex shader
	//std::cout << "\n__Attribute Error Check_BEGIN_\n";
	//Positions
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, glStride, NULL);
	totLen += 3;

	//error = glGetError();
	//std::cout << "position Attributes: " << std::to_string(error) << "\n";

	//Normals
	if (normalsEnabled)
	{
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, glStride, (GLvoid*)(sizeof(GLfloat) * totLen));
		totLen += 3;

		//error = glGetError();
		//std::cout << "normal Attributes: " << std::to_string(error) << "\n";
	}

	//UVs
	if (uvEnabled)
	{
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, glStride, (GLvoid*)(sizeof(GLfloat) * totLen));
		totLen += 2;

		//error = glGetError();
		//std::cout << "texture Attributes: " << std::to_string(error) << "\n";

	}
	//UVs
	if (colorsEnabled)
	{
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, glStride, (GLvoid*)(sizeof(GLfloat) * totLen));
		totLen += 4;

		//error = glGetError();
		//std::cout << "texture Attributes: " << std::to_string(error) << "\n\n";

	}

	//std::cout << "\n__Attribute Error Check_COMPLETE_\n\n";




	glDrawElements(GL_TRIANGLES, IndexBuffer.size(), GL_UNSIGNED_INT, nullptr);
	//error = glGetError();
	//std::cout << "GLDrawElements Called: " << std::to_string(error) << "\n";



	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);



	//std::cout << "Disable vertex arrays\n";

	glDisableVertexAttribArray(0);
	if (normalsEnabled)
		glDisableVertexAttribArray(1);
	if (uvEnabled)
		glDisableVertexAttribArray(2);
	if (colorsEnabled)
		glDisableVertexAttribArray(3);

	//std::cout << "\n___Draw_COMPLETE__\n\n";

}

void MeshResource::Destroy() {
	glBindBuffer(GL_ARRAY_BUFFER, NULL);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
	glDeleteBuffers(1, &VertexBuffer_Handle);
	glDeleteBuffers(1, &IndexBuffer_Handle);
}

void MeshResource::Transform(Matrix4& matrix) {
	unsigned int j = 0;
	for (unsigned int i = 0; i < VertexBuffer.size(); i += stride) {

		Vector3 newVec = matrix * positions[j];
		j++;
		VertexBuffer[i] = newVec[0];
		VertexBuffer[i + 1] = newVec[1];
		VertexBuffer[i + 2] = newVec[2];
	}
}

/**
 * Compiles The vertex attribute values into a long list of floats that is the Vertexbuffer
 */
void MeshResource::VertexBufferCompile() 
{
	//Decide Stride
	stride = 3;
	if (normalsEnabled)
		stride += 3;
	if (uvEnabled)
		stride += 2;
	if (colorsEnabled)
		stride += 4;
	// VertexBuffer should have length = stride * amount of positions
	VertexBuffer = std::vector<float>(stride * positions.size());

	size_t currentOffset = 0;

	for (size_t j = 0; j < positions.size(); j++)
	{
		for (unsigned int i = 0; i < 3; i++) 
		{
			VertexBuffer[currentOffset] = positions[j][i]; currentOffset++;
		}

		if (normalsEnabled)
		{
			for (unsigned int i = 0; i < 3; i++)
			{
				VertexBuffer[currentOffset] = normals[j][i]; currentOffset++;
			}
		}

		if (uvEnabled)
		{
			for (unsigned int i = 0; i < 2; i++)
			{
				VertexBuffer[currentOffset] = uvs[j][i]; currentOffset++;
			}
		}
	}

	std::cout << "Vertexbuffer size: " << VertexBuffer.size() << "\n";


}
//TODO: Add a VertexBufferCompileGPU() that converts the Loaded Attribute Data into A list of Vertex Objects to be Used in The Renderer


//File Handling
bool MeshResource::ReadFile(const std::string& path) 
{
	std::ifstream file(path);
	unsigned int vI[4], nI[4], uI[4];
	int n;
	Vector3 v;
	Vector3 vt;
	Vector3 vn;

	if (!file.is_open()) 
		return false;

	//local cache of verts
	while (!file.eof()) 
	{
		char line[512];
		file.getline(line, 512);

		std::stringstream s;
		s << line;

		char junk;

		if (line[0] == 'v' && line[1] == ' ') {
			s >> junk >> v[0] >> v[1] >> v[2];
			positions.push_back(v);
		}
		else if (line[0] == 'v' && line[1] == 't' && line[2] == ' ') {
			if (uvEnabled == false) { uvEnabled = true; }
			s >> junk >> junk >> vt[0] >> vt[1];
			uvs.push_back(vt);
		}
		else if (line[0] == 'v' && line[1] == 'n' && line[2] == ' ') {
			if (normalsEnabled == false) { normalsEnabled = true; }
			s >> junk >> junk >> vn[0] >> vn[1] >> vn[2];
			normals.push_back(vn);
		}
		else if (line[0] == 'f' && line[1] == ' ') {
			if (uvEnabled && normalsEnabled) {
				n = sscanf_s(s.str().c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &vI[0], &uI[0], &nI[0], &vI[1], &uI[1], &nI[1], &vI[2], &uI[2], &nI[2], &vI[3], &uI[3], &nI[3]);
			}
			else if (normalsEnabled) {
				n = sscanf_s(s.str().c_str(), "f %d//%d %d//%d %d//%d %d//%d", &vI[0], &nI[0], &vI[1], &nI[1], &vI[2], &nI[2], &vI[3], &nI[3]);
			}
			else if (uvEnabled) {
				n = sscanf_s(s.str().c_str(), "f %d/%d %d/%d %d/%d %d/%d", &vI[0], &uI[0], &vI[1], &uI[1], &vI[2], &uI[2], &vI[3], &uI[3]);
			}
			else {
				n = sscanf_s(s.str().c_str(), "f %d %d %d %d", &vI[0], &vI[1], &vI[2], &vI[3]);
			}
			//if quad
			if (n == 4 || n == 8 || n == 12) {
				//triangle 1
				vertexIndex.push_back(vI[0] - 1u);
				if (uvEnabled) textureIndex.push_back(uI[0] - 1u);
				if (normalsEnabled) normalIndex.push_back(nI[0] - 1u);
				vertexIndex.push_back(vI[1] - 1u);
				if (uvEnabled) textureIndex.push_back(uI[1] - 1u);
				if (normalsEnabled) normalIndex.push_back(nI[1] - 1u);
				vertexIndex.push_back(vI[2] - 1u);
				if (uvEnabled) textureIndex.push_back(uI[2] - 1u);
				if (normalsEnabled) normalIndex.push_back(nI[2] - 1u);
				//triangle 2
				vertexIndex.push_back(vI[0] - 1u);
				if (uvEnabled) textureIndex.push_back(uI[0] - 1u);
				if (normalsEnabled) normalIndex.push_back(nI[0] - 1u);
				vertexIndex.push_back(vI[2] - 1u);
				if (uvEnabled) textureIndex.push_back(uI[2] - 1u);
				if (normalsEnabled) normalIndex.push_back(nI[2] - 1u);
				vertexIndex.push_back(vI[3] - 1u);
				if (uvEnabled) textureIndex.push_back(uI[3] - 1u);
				if (normalsEnabled) normalIndex.push_back(nI[3] - 1u);
			}
			else {
				//is triangle
				vertexIndex.push_back(vI[0] - 1u);
				if (uvEnabled) textureIndex.push_back(uI[0] - 1u);
				if (normalsEnabled) normalIndex.push_back(nI[0] - 1u);
				vertexIndex.push_back(vI[1] - 1u);
				if (uvEnabled) textureIndex.push_back(uI[1] - 1u);
				if (normalsEnabled) normalIndex.push_back(nI[1] - 1u);
				vertexIndex.push_back(vI[2] - 1u);
				if (uvEnabled) textureIndex.push_back(uI[2] - 1u);
				if (normalsEnabled) normalIndex.push_back(nI[2] - 1u);
			}
			
		}
	}
	std::map<Vertex, unsigned int> vertexMap;
	VertexMapConstruct(vertexMap);

	positions.clear();
	uvs.clear();
	normals.clear();
	positions.resize(IndexBuffer.size());
	uvs.resize(IndexBuffer.size());
	normals.resize(IndexBuffer.size());
	for (auto& element : vertexMap) 
	{
		positions[element.second] = element.first.position;
		uvs[element.second] = element.first.uv;
		normals[element.second] = element.first.normal;
	}
	return true;
}



Vertex MeshResource::VertexConstruct(unsigned int vertex,  unsigned int normal, unsigned int uv ) {

	if (normalsEnabled && uvEnabled) {
		return Vertex(positions[vertex], normals[normal], uvs[uv]);
	}
	else if (normalsEnabled) {
		return Vertex(positions[vertex], normals[normal], Vector3::zero);
		}
	else if (uvEnabled) {
		return Vertex(positions[vertex], Vector3::zero, uvs[uv]);
	}
	else {
		return Vertex(positions[vertex], Vector3::zero, Vector3::zero);
	}
}

bool MeshResource::VertexDoubleCheck(Vertex& vert, std::map<Vertex, unsigned int>& vertMap, unsigned int& inputResult) {
	const auto Duplicate = vertMap.find(vert);
	if (Duplicate == vertMap.end()) {
		return false;
	}
	inputResult = Duplicate->second;
	return true;
}

void MeshResource::VertexMapConstruct(std::map<Vertex, unsigned int>& vertexMap) {
	Vertex vertex;
	for (size_t i = 0; i < vertexIndex.size(); i++) {
		if (uvEnabled && normalsEnabled) {
			vertex = VertexConstruct(vertexIndex[i], normalIndex[i], textureIndex[i]);
		}
		else if (uvEnabled) {
			vertex = VertexConstruct(vertexIndex[i], 0, textureIndex[i]);
		}
		else if (normalsEnabled) {
			vertex = VertexConstruct(vertexIndex[i], normalIndex[i], 0);
		}
		else {
			vertex = VertexConstruct(vertexIndex[i], 0, 0);
		}

		unsigned int index;
		if (VertexDoubleCheck(vertex, vertexMap, index))
		{ // if isDouble
			IndexBuffer.push_back(index);
		}
		else
		{ // if isnew
			int next = i;
			IndexBuffer.push_back(next);
			vertexMap.emplace(std::pair<Vertex, unsigned int>(vertex, next));
		}
	}

	std::cout << "Indexbuffer size: " << IndexBuffer.size() << "\n";
}






