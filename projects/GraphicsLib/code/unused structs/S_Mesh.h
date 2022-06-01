#pragma once
#include <fstream>
#include <iostream>
#include <vector>

#include "CString.h"
#include "S_Vertex.h"
#include "cstringt.h"

using namespace std;



enum MeshType
{
	Cube
};




/**
 * A Data stucture containing the nessesary TriangleData used to create a mesh.
 * This struct contains the raw Meshdata that is to be used by the Resource_Mesh Class
 */
struct Mesh
{

	//mesh
	string name = "New_Mesh";

	bool colorsEnabled = false;
	bool uvEnabled = false;
	bool normalsEnabled = false;

	vector<Vertex> vertices;

	vector<int> indices;


	

	//Mesh Loading Functions

	bool ReadFile(const string& path) 
	{
		//string file_ending = path.substr(path.size() - 4, 4);

		//if (file_ending != ".obj")
		//{
		//	cout << "Invalid format, this is not an .obj file " << path << "\n";
		//	return false;
		//}

		//std::ifstream file(path);
		//if (!file.is_open())
		//{
		//	cout << "Failed to find the requested file: " << path << "\n";
		//	return false;
		//}

		//std::cout << "Loading file: " << path << "\n";


		////vertexData for Attribs
		//vector<Vector3> temp_pos;
		//vector<Vector3> temp_normal;
		//vector<Vector3> temp_uv;

		////IndexData for Attribs
		//vector<unsigned int> normalIndex;
		//vector<unsigned int> textureIndex;

		//std::string line;

		//while (getline(file, line))
		//{
		//	if (line.empty())
		//		continue;

		//	auto lineSplit = CString::Split(line, ' ');

		//	if (lineSplit[0] == "mtllib") // material name
		//	{
		//		materialNames.push_back(lineSplit[1]);
		//	}
		//	else if (lineSplit[0] == "v") // vertex position
		//	{
		//		Vector4 vertex;
		//		vertex.X = std::stof(lineSplit[1]);
		//		vertex.Y = std::stof(lineSplit[2]);
		//		vertex.Z = stof(lineSplit[3]);
		//		tmpVerts.push_back(vertex);
		//	}
		//	else if (lineSplit[0] == "vt") // texture coordinate
		//	{
		//		Vector2 vertex;
		//		vertex.X = stof(lineSplit[1]);
		//		vertex.Y = 1 - stof(lineSplit[2]);
		//		tmpTextureCoords.push_back(vertex);
		//	}
		//	else if (lineSplit[0] == "vn") // normal
		//	{
		//		Vector4 vertex;
		//		vertex.X = stof(lineSplit[1]);
		//		vertex.Y = stof(lineSplit[2]);
		//		vertex.Z = stof(lineSplit[3]);
		//		tmpNormals.push_back(vertex);
		//	}
		//	else if (lineSplit[0] == "f") //  face 
		//	{
		//		std::vector<std::string> v1 = CString::Split(lineSplit[1], '/');
		//		std::vector<std::string> v2 = CString::Split(lineSplit[2], '/');
		//		std::vector<std::string> v3 = CString::Split(lineSplit[3], '/');

		//		VertexIndices.push_back(stoi(v1[0]) - 1);
		//		VertexIndices.push_back(stoi(v2[0]) - 1);
		//		VertexIndices.push_back(stoi(v3[0]) - 1);

		//		textureIndices.push_back(stoi(v1[1]) - 1);
		//		textureIndices.push_back(stoi(v2[1]) - 1);
		//		textureIndices.push_back(stoi(v3[1]) - 1);

		//		normalIndices.push_back(stoi(v1[2]) - 1);
		//		normalIndices.push_back(stoi(v2[2]) - 1);
		//		normalIndices.push_back(stoi(v3[2]) - 1);
		//	}
		//}
		//file.close();


		return false;
	}

	void VertexMapConstruct(std::map<Vertex, unsigned int>& vertexMap)
	{
		//Vertex vertex;
		//for (size_t i = 0; i < vertexIndex.size(); i++) {
		//	if (uvEnabled && normalsEnabled) {
		//		vertex = VertexConstruct(vertexIndex[i], textureIndex[i], normalIndex[i]);
		//	}
		//	//else if (uvEnabled) {
		//	//	vertex = VertexConstruct(vertexIndex[i], textureIndex[i], 0);
		//	//}
		//	//else if (normalsEnabled) {
		//	//	vertex = VertexConstruct(vertexIndex[i], 0, normalIndex[i]);
		//	//}
		//	//else {
		//	//	vertex = VertexConstruct(vertexIndex[i], 0, 0);
		//	//}

		//	unsigned int index;
		//	if (VertexDoubleCheck(vertex, vertexMap, index))
		//	{ // if isDouble
		//		Buffer_Index.push_back(index);
		//	}
		//	else
		//	{ // if isnew
		//		int next = i;
		//		Buffer_Index.push_back(next);
		//		vertexMap.emplace(std::pair<Vertex, unsigned int>(vertex, next));
		//	}
		//}
	}

	Vertex VertexConstruct(unsigned int vertex, unsigned int uv, unsigned int normal)
	{
		//if (normalsEnabled && uvEnabled) {
		//	return Vertex(verticies[vertex], uvs[uv], normals[normal]);
		//}
		//else if (normalsEnabled) {
		//	return Vertex(verticies[vertex], Vector3::zero, normals[normal]);
		//}
		//else if (uvEnabled) {
		//	return Vertex(verticies[vertex], uvs[uv], Vector3::zero);
		//}
		//else {
		//	return Vertex(verticies[vertex], Vector3::zero, Vector3::zero);
		//}
	}

	bool VertexDoubleCheck(Vertex& vert, std::map<Vertex, unsigned int>& vertMap, unsigned int& inputResult)
	{
		//const auto Duplicate = vertMap.find(vert);
		//if (Duplicate == vertMap.end()) {
		//	return false;
		//}
		//inputResult = Duplicate->second;
		//return true;
	}




	//Constructors
	Mesh() = default;

	Mesh(std::string path);

	Mesh(MeshType type);

};



inline Mesh::Mesh(std::string path)
{

}

inline Mesh::Mesh(MeshType type)
{
	{
		switch (type)
		{

		}
	}
}
