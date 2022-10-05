#include "GLShader.h"
#include "../Utils.h"

#include "../GL.h"
#include <cassert>
#include <cstdio>
#include <string>

GLShader::GLShader(const char* fileName, GL4API *api)
: GLShader(GLShaderTypeFromFileName(fileName), readShaderFile(fileName).c_str(),api, fileName)
{}

GLShader::GLShader(GLenum type, const char* text,GL4API *api ,const char* debugFileName)
	: type_(type)
	, handle_(api_->glCreateShader(type))
{
    api_ = api;
    api_->glShaderSource(handle_, 1, &text, nullptr);
    api_->glCompileShader(handle_);

	char buffer[8192];
	GLsizei length = 0;
    api_->glGetShaderInfoLog(handle_, sizeof(buffer), &length, buffer);

	if (length)
	{
		printf("%s (File: %s)\n", buffer, debugFileName);
		printShaderSource(text);
		assert(false);
	}
}

GLShader::~GLShader()
{
    api_->glDeleteShader(handle_);
}


void printProgramInfoLog(GLuint handle, GL4API* api)
{
	char buffer[8192];
	GLsizei length = 0;
    api->glGetProgramInfoLog(handle, sizeof(buffer), &length, buffer);
	if (length)
	{
		printf("%s\n", buffer);
		assert(false);
	}
}

GLProgram::GLProgram(const GLShader& a, GL4API* api)
	: handle_(api_->glCreateProgram())
{
    api_ = api;
    api_->glAttachShader(handle_, a.getHandle());
    api_->glLinkProgram(handle_);
	printProgramInfoLog(handle_, api_);
}

GLProgram::GLProgram(const GLShader& a, const GLShader& b, GL4API *api)
: handle_(api_->glCreateProgram())
{
    api_ = api;
    api_->glAttachShader(handle_, a.getHandle());
    api_->glAttachShader(handle_, b.getHandle());
    api_->glLinkProgram(handle_);
	printProgramInfoLog(handle_, api_);
}

GLProgram::GLProgram(const GLShader& a, const GLShader& b, const GLShader& c, GL4API *api)
: handle_(api_->glCreateProgram())
{
    api_ = api;
    api_->glAttachShader(handle_, a.getHandle());
    api_->glAttachShader(handle_, b.getHandle());
    api_->glAttachShader(handle_, c.getHandle());
    api_->glLinkProgram(handle_);
	printProgramInfoLog(handle_, api_);
}

GLProgram::GLProgram(const GLShader& a, const GLShader& b, const GLShader& c, const GLShader& d, const GLShader& e, GL4API *api)
: handle_(api_->glCreateProgram())
{
    api_ = api;
    api_->glAttachShader(handle_, a.getHandle());
    api_->glAttachShader(handle_, b.getHandle());
    api_->glAttachShader(handle_, c.getHandle());
    api_->glAttachShader(handle_, d.getHandle());
    api_->glAttachShader(handle_, e.getHandle());
    api_->glLinkProgram(handle_);
	printProgramInfoLog(handle_, api_);
}

GLProgram::~GLProgram()
{
    api_->glDeleteProgram(handle_);
}

void GLProgram::useProgram() const
{
    api_->glUseProgram(handle_);
}

GLenum GLShaderTypeFromFileName(const char* fileName)
{
	if (endsWith(fileName, ".vert"))
		return GL_VERTEX_SHADER;

	if (endsWith(fileName, ".frag"))
		return GL_FRAGMENT_SHADER;

	if (endsWith(fileName, ".geom"))
		return GL_GEOMETRY_SHADER;

	if (endsWith(fileName, ".tesc"))
		return GL_TESS_CONTROL_SHADER;

	if (endsWith(fileName, ".tese"))
		return GL_TESS_EVALUATION_SHADER;

	if (endsWith(fileName, ".comp"))
		return GL_COMPUTE_SHADER;

	assert(false);

	return 0;
}

GLBuffer::GLBuffer(GLsizeiptr size, const void* data, GLbitfield flags, GL4API *api)
{
    api_ = *api;
    api_.glCreateBuffers(1, &handle_);
    api_.glNamedBufferStorage(handle_, size, data, flags);
}

GLBuffer::~GLBuffer()
{
    api_.glDeleteBuffers(1, &handle_);
}
