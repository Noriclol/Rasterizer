#pragma once
#include <vector>
#include <functional>
#include <map>
#include <vector>

#include "Matrix4.h"
#include "Vector3.h"

#include "Camera.h"
#include "Transform.h"

#include  "S_Vertex.h"
#include "S_Pixel.h"
#include "S_BufferData.h"
#include "S_Color.h"


#include "Resource_Texture.h"


//Uniforms are fields that need to gets passed to the shader
//struct Uniforms 
//{
//	Matrix4* mvp; //Model * View * Projection
//	Matrix4* m;
//	Matrix4* n;
//	TextureResource* texture;
//	Color3* aColor;
//	Color3* dColor;
//	Color3* sColor;
//	float shine;
//	Color3* lColor;
//	Vector3* lPos;
//	Vector3* cPos;
//
//};
//
//
//class FrameBuffer 
//{
//private:
//	
//	Pixel* colorBuffer;
//	int FBX, FBY;
//	unsigned short depthBuffer;
//
//public:
//	
//	void SetFrameBufferSize(size_t width, size_t height);
//	Pixel* GetPointerFB();
//	unsigned short* GetPointerDB();
//	
//	//void SetFBufferRGBatIndex(Pixel rgb, int Index);
//	int GetHeightFB();
//	int GetWidthFB();
//};
//
//class SoftwareRenderer 
//{
//private:
//
//	std::function<void(const Uniforms& uniform, const Vertex& v, Vector3& position, Vector3& uv, Vector3& normal, Vector3& worldPosition)> vertexShader;
//	std::function<void(const Uniforms& uniform, const Vector3& position, const Vector3& uv, const Vector3& normal, const Vector3& worldPosition, Color3& outColor)> fragmentShader;
//
//	unsigned int iBuffer;
//	float* vBuffer;
//	Uniforms uniforms;
//	Camera* camera;
//	std::map<unsigned int, BufferData> BufferMap;
//	
//	Vector3 BaryCalc(Vector3& v0, Vector3& v1, Vector3& v2, Vector3& point);
//
//	void SetCamera(Camera& camera);
//	void SetPixel(FrameBuffer& frameBufferRef, Color3& color, unsigned int X, unsigned int Y);
//	void SetDepth(unsigned short depth, unsigned int X, unsigned int Y);
//
//	// Rasterization
//	void RasterizeTriangle(Vertex& v0, Vertex& v1, Vertex& v2);
//	void DrawFlatTop(Vertex& v0, Vertex& v1, Vertex& v2);
//	void DrawFlatBottom(Vertex& v0, Vertex& v1, Vertex& v2);
//
//public:
//
//	FrameBuffer frameBuffer; //setting framebuffer to public so i can access variables.
//	unsigned int AddBuffers(float* vBuffer, size_t vBufferSize, unsigned int* iBuffer, size_t iBufferSize);
//	void DrawBuffers(unsigned int bufferHandle);
//
//
//
//	//should return vertex to be used on frag shader
//	inline void SetVertexShader(std::function<void(const Uniforms& uniform, const Vertex& v, Vector3& position, Vector3& uv, Vector3& normal, Vector3& worldPosition)> vertexShader) 
//	{
//		this->vertexShader = vertexShader;
//	};
//
//	inline void SetFragmentShader(std::function<void(const Uniforms& uniform, const Vector3& position, const Vector3& uv, const Vector3& normal, const Vector3& worldPosition, Color3& outColor)> fragmentShader)
//	{
//		this->fragmentShader = fragmentShader;
//	};
//
//	void SetTextureResource() 
//	{
//
//	}
//};