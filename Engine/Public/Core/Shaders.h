#pragma once

#include "GL\glew.h"

namespace Shaders
{
	GLuint CompileShader(GLenum type, const GLchar* source)
	{
		GLuint shader = glCreateShader(type);
		glShaderSource(shader, 1, &source, nullptr);
		glCompileShader(shader);

		GLint param;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &param);

		if (!param)
		{
			GLchar log[4096];
			glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
		}

		return shader;
	}

	GLuint LinkProgram(GLuint vert, GLuint frag)
	{
		GLuint program = glCreateProgram();
		glAttachShader(program, vert);
		glAttachShader(program, frag);
		glLinkProgram(program);

		GLint param;
		glGetProgramiv(program, GL_LINK_STATUS, &param);

		if (!param)
		{
			GLchar log[4096];
			glGetProgramInfoLog(program, sizeof(log), nullptr, log);
		}

		return program;
	}
}
