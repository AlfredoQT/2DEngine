#pragma once

typedef unsigned int GLuint;
typedef int GLint;

struct GraphicsContext
{
	GLuint mProgram;
	GLint mUniformAngle;
	GLuint mVBOPoint;
	GLuint mVAOPoint;
	float mAngle;
};