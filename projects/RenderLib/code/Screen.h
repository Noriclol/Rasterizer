#pragma once
#include <GL/glew.h>
#include <vector>
#include  <map>
#include <sstream>
#include "Vector3.h"


/**
 * \Node Container containing Data for the things we want to render
 */
//class Screen
//{
//public:
//
//
//	//fields
//	std::vector<Vector3> verticies;
//	std::vector<Vector3> normals;
//	std::vector<Vector3> UVs;
//	std::vector<float> vBuffer;		   //VertexBuffer
//	std::vector<unsigned int> iBuffer; //IndexBuffer
//	unsigned int stride;
//
//	unsigned int iIBufferHandle;
//	unsigned int iVBufferHandle;
//
//	//functions
//
//	//	-Buffers
//	void GenerateBuffer();
//	void BindBuffer();
//	void BindVertexAttribute();
//	void BindTexture();
//	void UnbindTexture();
//	void UnbindBuffers();
//	void DeleteBuffers();
//
//	//	-Drawing
//	void DrawCall();
//	void DrawTexture();
//	Screen();
//};
//
