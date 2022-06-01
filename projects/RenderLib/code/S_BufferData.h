#pragma once

#include "S_Vertex.h"
#include <vector>

//Datastruct for containing Everything on the screen
//Contains
struct BufferData
{
	Vertex vBuffer;
	unsigned int* iBuffer;
	size_t vBufferSize, iBufferSize;

	BufferData()
	{
		//this->vBufferSize = 0;
		//this->iBufferSize = 0;
		//this->vBuffer = new Vertex[vBufferSize];
		//this->iBuffer = new unsigned int[iBufferSize];

	};

	BufferData(float* vBuffer, unsigned int* iBuffer, size_t vBufferSize, size_t iBufferSize)
	{
		//when creating new bufferdata pass in relevant data

		//this->vBuffer = (Vertex*)vBuffer;
		//this->iBuffer = iBuffer;
		//this->vBufferSize = vBufferSize / 8;
		//this->iBufferSize = iBufferSize;
	};
};