#pragma once

#include "../GL.h"
#include "GLTexture.h"
#include "GLFW/glfw3.h"
#include <memory>
#include <cassert>

class GLFramebuffer
{
public:
	GLFramebuffer(int width, int height, GLenum formatColor, GLenum formatDepth, GL4API* api);
	~GLFramebuffer();
	GLFramebuffer(const GLFramebuffer&) = delete;
	GLFramebuffer(GLFramebuffer&&) = default;
	GLuint getHandle() const { return handle_; }
	const GLTexture& getTextureColor() const { return *texColor_.get(); }
	const GLTexture& getTextureDepth() const { return *texDepth_.get(); }
	void bind();
	void unbind();

private:
	int width_;
	int height_;
	GLuint handle_ = 0;
    GL4API *_api;

	std::unique_ptr<GLTexture> texColor_;
	std::unique_ptr<GLTexture> texDepth_;
};

GLFramebuffer::GLFramebuffer(int width, int height, GLenum formatColor, GLenum formatDepth, GL4API* api)
	: width_(width)
	, height_(height)
{
    _api = api;
    /*
     * GetAPI4(&_api, [](const char* func) -> void* { return (void *)glfwGetProcAddress(func); });
     * InjectAPITracer4(&_api);
     * */


    _api->glCreateFramebuffers(1, &handle_);

	if (formatColor)
	{
		texColor_ = std::make_unique<GLTexture>(GL_TEXTURE_2D, width, height, formatColor, _api);
        _api->glTextureParameteri(texColor_->getHandle(), GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        _api->glTextureParameteri(texColor_->getHandle(), GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        _api->glNamedFramebufferTexture(handle_, GL_COLOR_ATTACHMENT0, texColor_->getHandle(), 0);
	}
	if (formatDepth)
	{
		texDepth_ = std::make_unique<GLTexture>(GL_TEXTURE_2D, width, height, formatDepth, _api);
		const GLfloat border[] = { 0.0f, 0.0f, 0.0f, 0.0f };
        _api->glTextureParameterfv(texDepth_->getHandle(), GL_TEXTURE_BORDER_COLOR, border);
        _api->glTextureParameteri(texDepth_->getHandle(), GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
        _api->glTextureParameteri(texDepth_->getHandle(), GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        _api->glNamedFramebufferTexture(handle_, GL_DEPTH_ATTACHMENT, texDepth_->getHandle(), 0);
	}

	const GLenum status = _api->glCheckNamedFramebufferStatus(handle_, GL_FRAMEBUFFER);

    assert(status == GL_FRAMEBUFFER_COMPLETE);
}

GLFramebuffer::~GLFramebuffer()
{
    _api->glBindFramebuffer(GL_FRAMEBUFFER, 0);
    _api->glDeleteFramebuffers(1, &handle_);
}

void GLFramebuffer::bind()
{
    _api->glBindFramebuffer(GL_FRAMEBUFFER, handle_);
    _api->glViewport(0, 0, width_, height_);
}

void GLFramebuffer::unbind()
{
    _api->glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
