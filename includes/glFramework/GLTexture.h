#pragma once

#include "../GL.h"

class GLTexture
{
public:
	GLTexture(GLenum type, const char* fileName, GL4API *api);
	GLTexture(GLenum type, int width, int height, GLenum internalFormat, GL4API *api);
	GLTexture(int w, int h, const void* img, GL4API *api);
	~GLTexture();
	GLTexture(const GLTexture&) = delete;
	GLTexture(GLTexture&&) noexcept ;
    GL4API api_;
	[[nodiscard]] GLenum getType() const { return type_; }
	[[nodiscard]] GLuint getHandle() const { return handle_; }
	[[nodiscard]] GLuint64 getHandleBindless() const { return handleBindless_; }

private:
	GLenum type_ = 0;
	GLuint handle_ = 0;
	GLuint64 handleBindless_ = 0;
};
