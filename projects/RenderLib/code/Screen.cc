#include "Screen.h"

//void Screen::GenerateBuffer()
//{
//	glGenBuffers(1, &iVBufferHandle);
//	glGenBuffers(1, &iIBufferHandle);
//	glBindBuffer(GL_ARRAY_BUFFER, iVBufferHandle);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iIBufferHandle);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vBuffer.size(), &vBuffer[0], GL_STATIC_DRAW);
//	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * iBuffer.size(), &iBuffer[0], GL_STATIC_DRAW);
//}
//
//void Screen::BindBuffer()
//{
//
//	glBindBuffer(GL_ARRAY_BUFFER, iVBufferHandle);
//	glBufferSubData(GL_ARRAY_BUFFER, NULL, sizeof(GLfloat) * vBuffer.size(), (GLvoid*)vBuffer.data());
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iIBufferHandle);
//	glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, NULL, sizeof(GLfloat) * iBuffer.size(), (GLvoid*)iBuffer.data());
//}
//
//void Screen::BindVertexAttribute()
//{
//	unsigned int totLen = 0;
//	unsigned int len = 3;
//	glEnableVertexAttribArray(0);
//	glVertexAttribPointer(0, len, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * stride, NULL);
//	totLen += len;
//	len = 4;
//	glEnableVertexAttribArray(1);
//	glVertexAttribPointer(1, len, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * stride, (GLvoid*)(sizeof(GLfloat) * totLen));
//	totLen += len;
//	len = 2;
//	glEnableVertexAttribArray(2);
//	glVertexAttribPointer(2, len, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * stride, (GLvoid*)(sizeof(GLfloat) * totLen));
//	totLen += len;
//	len = 3;
//	glEnableVertexAttribArray(3);
//	glVertexAttribPointer(3, len, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * stride, (GLvoid*)(sizeof(GLfloat) * totLen));
//	totLen += len;
//}
//
//void Screen::BindTexture()
//{
//
//}
//
//void Screen::UnbindTexture()
//{
//	glActiveTexture(GL_TEXTURE0);
//	glBindTexture(GL_TEXTURE_2D, NULL);
//}
//
//void Screen::UnbindBuffers()
//{
//	glBindBuffer(GL_ARRAY_BUFFER, NULL);
//	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
//}
//
//void Screen::DeleteBuffers()
//{
//	glDeleteBuffers(1, &iVBufferHandle);
//	glDeleteBuffers(1, &iIBufferHandle);
//}
//
//void Screen::DrawCall()
//{
//	BindBuffer();
//	BindTexture();
//	BindVertexAttribute();
//	glDrawElements(GL_TRIANGLES, iBuffer.size(), GL_UNSIGNED_INT, (GLvoid*)0);
//	UnbindBuffers();
//}
//
//void Screen::DrawTexture()
//{
//
//}
//
//Screen::Screen(){
//	this->verticies.push_back(Vector3(0.0f,0.0f,0.0f));
//	this->verticies.push_back(Vector3(1.0f, 0.0f, 0.0f));
//	this->verticies.push_back(Vector3(0.0f, 1.0f, 0.0f));
//	this->verticies.push_back(Vector3(1.0f, 1.0f, 0.0f));
//
//	this->iBuffer.push_back(0); this->iBuffer.push_back(2); this->iBuffer.push_back(1);
//	this->iBuffer.push_back(1); this->iBuffer.push_back(2); this->iBuffer.push_back(3);
//}
