#pragma once

#include "../GL.h"

class GLShader
{
public:
	explicit GLShader(const char* fileName, GL4API *api);
	GLShader(GLenum type, const char* text, GL4API *api ,const char* debugFileName = "");

    GLShader();

    ~GLShader();
    GL4API *api_;
	GLenum getType() const { return type_; }
	GLuint getHandle() const { return handle_; }

private:
	GLenum type_;
	GLuint handle_;
};

class GLProgram
{
public:
	GLProgram(const GLShader& a, GL4API *api);
	GLProgram(const GLShader& a, const GLShader& b, GL4API *api);
	GLProgram(const GLShader& a, const GLShader& b, const GLShader& c, GL4API *api);
	GLProgram(const GLShader& a, const GLShader& b, const GLShader& c, const GLShader& d, const GLShader& e, GL4API *api);
	~GLProgram();
    GL4API* api_;
	void useProgram() const;
	GLuint getHandle() const { return handle_; }

private:
	GLuint handle_;
};

GLenum GLShaderTypeFromFileName(const char* fileName);

class GLBuffer
{
public:
	GLBuffer(GLsizeiptr size, const void* data, GLbitfield flags, GL4API *api);
	~GLBuffer();
    GL4API api_;
    GLuint getHandle() const { return handle_; }

private:
	GLuint handle_;
};
