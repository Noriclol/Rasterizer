#include "Renderer.h"






//
//
//void FrameBuffer::SetFrameBufferSize(size_t width, size_t height)
//{
// 	colorBuffer = new Pixel[width * height];
//	FBX = width;
//	FBY = height;
//}
//
//Pixel* FrameBuffer::GetPointerFB()
//{
//	return colorBuffer;
//}
//
//unsigned short* FrameBuffer::GetPointerDB()
//{
//	return &depthBuffer;
//}
//
////void FrameBuffer::SetFBufferPixelatIndex(Pixel Pixel, int index)
////{
////	//colorBuffer[index] = Pixel;
////}
//
//int FrameBuffer::GetHeightFB()
//{
//	return FBY;
//}
//
//int FrameBuffer::GetWidthFB()
//{
//	return FBX;
//}
//
//
//
//
//
//
//
//
////SOFTWARE RENDERER
//
//Vector3 SoftwareRenderer::BaryCalc(Vector3& v0, Vector3& v1, Vector3& v2, Vector3& p)
//{
//	//take 3 vector to spit out 1 vector
//	Vector3 weight;
//
//	weight[0] = (v1.y - v2.y) * (p.x - v2.x) + (v2.x - v1.x) * (p.y - v2.y) / (v1.y - v2.y) * (v0.x - v2.x) + (v2.x - v1.x) * (v0.y - v2.y); // Weight 1
//	weight[1] = (v2.y - v0.y) * (p.x - v2.x) + (v0.x - v2.x) * (p.y - v2.y) / (v1.y - v2.y) * (v0.x - v2.x) + (v2.x - v1.x) * (v0.y - v2.y); // Weight 2
//	weight[2] = 1 - weight[0] - weight[1]; // Weight 3
//
//	return weight;
//}
//
//void SoftwareRenderer::SetCamera(Camera& camera)
//{
//	this->camera = &camera;
//	uniforms.cPos = &camera.position;
//}
//
////setting Pixel and depth in respective location
//
//void SoftwareRenderer::SetPixel(FrameBuffer& frameBufferRef, Color3& color, unsigned int X, unsigned int Y) 
//{
//	//frameBufferRef.SetFBufferPixelatIndex(Pixel(color.r,color.g, color.b), X + Y * frameBufferRef.GetWidthFB());
//}
//
//void SoftwareRenderer::SetDepth(unsigned short depth, unsigned int X, unsigned int Y)
//{
//
//}
//
//void SoftwareRenderer::RasterizeTriangle(Vertex& v0, Vertex& v1, Vertex& v2)
//{
//	//Vector3 p0, p1, p2;
//	//Vector3 wp0, wp1, wp2;
//	//Vector3 t0, t1, t2;
//	//Vector3 n0, n1, n2;
//
//	//vertexShader(uniforms, v0, p0, t0, n0, wp0);
//	//vertexShader(uniforms, v1, p1, t1, n1, wp1);
//	//vertexShader(uniforms, v2, p2, t2, n2, wp2);
//
//	//// near/far plane culling - if outside scope, return
//	//if (p0.z < camera->near || p1.z < camera->near || p2.z < camera->near ||
//	//	p0.z > camera->far  || p1.z > camera->far  || p2.z > camera->far) 
//	//	return; 
//
//	//p0 = p0 / p0.w;
//	//p1 = p1 / p1.w;
//	//p2 = p2 / p2.w;
//	//
//	////sorting by y to get top triangle first
//	////WARNING this probably will break the vertexshader outputs and fuck shit up.
//	//if (p1.y < p0.y) std::swap(v0, v1);
//	//if (p2.y < p1.y) std::swap(v1, v2);
//	//if (p1.y < p0.y) std::swap(v0, v1);
//
//	//// natural flat top
//	//if (p0.y == p1.y) 
//	//{ 
//	//	//sort top verticies by X
//	//	if (p0.x < p1.x) 
//	//		std::swap(v0, v1);
//	//
//	//	DrawFlatTop(v0, v1, v2);
//	//}
//
//	//// natural flat bottom
//	//else if (p1.y == p2.y) 
//	//{ 
//	//	if (p1.x < p2.x) 
//	//		std::swap(v1, v2);
//
//	//	DrawFlatBottom(v0, v1, v2);
//	//}
//
//	////general triangle
//	//else 
//	//{
//	//	//find splitting vertex
//	//	const float alphaSplit = (p1.y - p0.y) / (p2.y - p0.y);
//	//	Vertex vi{};
//	//	vi.position = p0 + (p2 - p0) * alphaSplit; //WARNING Color and normal might get fucked up by this.
//
//	//	if (p1.x < vi.position.x) // major right
//	//	{
//	//		DrawFlatBottom(v0, v1, vi);
//	//		DrawFlatTop(v1, vi, v2);
//	//	}
//	//	else // major left
//	//	{
//	//		DrawFlatBottom(v0, vi,v1);
//	//		DrawFlatTop(vi, v1, v2);
//	//	}
//	//}
//}
//
//void SoftwareRenderer::DrawFlatTop(Vertex& v0, Vertex& v1, Vertex& v2)
//{ 
//	Color3 pixelColor;
//	Vector3 p0, p1, p2;
//	Vector3 wp0, wp1, wp2;
//	Vector3 t0, t1, t2;
//	Vector3 n0, n1, n2;
//
//	vertexShader(uniforms, v0, p0, t0, n0, wp0);
//	vertexShader(uniforms, v1, p1, t1, n1, wp1);
//	vertexShader(uniforms, v2, p2, t2, n2, wp2);
//
//	float m0 = (v2.position.x - v0.position.x) / (v2.position.y - v0.position.y);
//	float m1 = (v2.position.x - v0.position.x) / (v2.position.y - v0.position.y);
//
//	const int yStart = (int)ceil(v0.position.y - 0.5f);
//	const int yEnd =   (int)ceil(v2.position.y - 0.5f);
//
//	for (int y = yStart; y < yEnd; y = y++)
//	{
//		const float px0 = m0 * (float(y) + 0.5f - v0.position.y) + v0.position.x;
//		const float px1 = m1 * (float(y) + 0.5f - v0.position.y) + v0.position.x;
//
//		const int xStart = (int)ceil(px0 - 0.5f);
//		const int xEnd	 = (int)ceil(px1 - 0.5f);
//		
//		for (int x = xStart; x < xEnd; x++)
//		{
//			//barycentric calc to get stuff for fragment shader
//			fragmentShader(uniforms, BaryCalc(p0,p1,p2, Vector3(x,y,0.0)), BaryCalc(t0, t1, t2, Vector3(x, y, 0.0)), BaryCalc(n0, n1, n2, Vector3(x, y, 0.0)), BaryCalc(wp0, wp1, wp2, Vector3(x, y, 0.0)), pixelColor);
//			SetPixel(frameBuffer, pixelColor, x, y);
//		}
//	}
//}
//
//void SoftwareRenderer::DrawFlatBottom(Vertex& v0, Vertex& v1, Vertex& v2)
//{
//	Color3 pixelColor;
//	Vector3 p0, p1, p2;
//	Vector3 wp0, wp1, wp2;
//	Vector3 t0, t1, t2;
//	Vector3 n0, n1, n2;
//
//	vertexShader(uniforms, v0, p0, t0, n0, wp0);
//	vertexShader(uniforms, v1, p1, t1, n1, wp1);
//	vertexShader(uniforms, v2, p2, t2, n2, wp2);
//
//	float m0 = (v2.position.x - v0.position.x) / (v2.position.y - v0.position.y);
//	float m1 = (v2.position.x - v0.position.x) / (v2.position.y - v0.position.y);
//
//	const int yStart = (int)ceil(v0.position.y - 0.5f);
//	const int yEnd = (int)ceil(v2.position.y - 0.5f);
//	
//	for (int y = yStart; y < yEnd; y = y++) {
//		const float px0 = m0 * (float(y) + 0.5f - v0.position.y) + v0.position.x;
//		const float px1 = m1 * (float(y) + 0.5f - v0.position.y) + v0.position.x;
//
//		const int xStart = (int)ceil(px0 - 0.5f);
//		const int xEnd = (int)ceil(px1 - 0.5f);
//
//		for (int x = xStart; x < xEnd; x++)
//		{
//			//barycentric calc to get stuff for fragment shader
//			fragmentShader(uniforms, BaryCalc(p0, p1, p2, Vector3(x, y, 0.0)), BaryCalc(t0, t1, t2, Vector3(x, y, 0.0)), BaryCalc(n0, n1, n2, Vector3(x, y, 0.0)), BaryCalc(wp0, wp1, wp2, Vector3(x, y, 0.0)), pixelColor);
//			SetPixel(frameBuffer, pixelColor, x, y);
//		}
//	}
//
//}
//
//unsigned int SoftwareRenderer::AddBuffers(float* vBuffer, size_t vBufferSize, unsigned int* iBuffer, size_t iBufferSize) 
//{
//	//unsigned int handle = BufferMap.size();
//	//BufferMap.emplace(handle, BufferData(vBuffer, vBufferSize, iBuffer, iBufferSize));
//	//return handle;
//}
//
//void SoftwareRenderer::DrawBuffers(unsigned int indexBufferHandle) 
//{
//	//BufferData selectedbuffer = BufferMap[indexBufferHandle];
//	//for (size_t i = 0; i < selectedbuffer.iBufferSize; i + 3) 
//	//{
//	//	RasterizeTriangle(selectedbuffer.vBuffer[selectedbuffer.iBuffer[i]], 
//	//					  selectedbuffer.vBuffer[selectedbuffer.iBuffer[i + 1]], 
//	//					  selectedbuffer.vBuffer[selectedbuffer.iBuffer[i + 2]]);
//	//}
//}

