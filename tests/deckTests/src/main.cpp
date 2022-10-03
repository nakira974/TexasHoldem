//
// Created by maxim on 22/09/2022.
//


#include "gtest/gtest.h"

#include "crossguid/guid.hpp"
#include "../includes/GL.h"
#include <easy/profiler.h>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>


#include <chrono>
#include <thread>

static const char* shaderCodeVertex = R"(
#version 460 core
layout(std140, binding = 0) uniform PerFrameData
{
	uniform mat4 MVP;
};
layout (location=0) out vec2 uv;
const vec2 pos[3] = vec2[3](
	vec2(-0.6f, -0.4f),
	vec2( 0.6f, -0.4f),
	vec2( 0.0f,  0.6f)
);
const vec2 tc[3] = vec2[3](
	vec2( 0.0, 0.0 ),
	vec2( 1.0, 0.0 ),
	vec2( 0.5, 1.0 )
);
void main()
{
	gl_Position = MVP * vec4(pos[gl_VertexID], 0.0, 1.0);
	uv = tc[gl_VertexID];
}
)";

static const char* shaderCodeFragment = R"(
#version 460 core
layout (location=0) in vec2 uv;
layout (location=0) out vec4 out_FragColor;
uniform sampler2D texture0;
void main()
{
	out_FragColor = texture(texture0, uv);
};
)";

void test_create_guid();
void test_load_resource(const char * path);
void test_load_image();
GLFWwindow* createWindow();
GL4API createTextures(GLuint* shaderVertex , GLuint* shaderFragment,
                      GLuint* vao, GLuint* perFrameDataBuffer,
                      GLuint* texture, GLuint* program, GLuint* kBufferSize);

int main(){
    const char * resourcePath = "data/ch2_sample3_STB.jpg";
    test_create_guid();
    test_load_resource(resourcePath);
    test_load_image();
    return 0;
}


 void test_create_guid(){
    std::string result = "";
     auto myGuid = xg::newGuid();
     std::stringstream stream;
     stream << myGuid;
     result = (stream.str().length() == 0) ? result : stream.str();
     ASSERT_FALSE(std::equal(result.begin(), result.end(), ""));
}

void test_load_resource(const char* path){
    bool result;
    int w, h, comp;
    const uint8_t* image = stbi_load(path, &w, &h, &comp, 3);
    result = (image != nullptr);
    ASSERT_TRUE(result);
}


void test_load_image(){
    EASY_MAIN_THREAD;
    EASY_PROFILER_ENABLE;
    GLuint* shaderVertex ;
    GLuint*shaderFragment;
    GLuint* vao ;
    GLuint*perFrameDataBuffer;
    GLuint* texture;
    GLuint* program;
    GLuint* kBufferSize;

    auto* window = createWindow();
    auto api = createTextures(shaderVertex, shaderFragment, vao, perFrameDataBuffer, texture, program, kBufferSize);

    EASY_END_BLOCK;

    while (!glfwWindowShouldClose(window))
    {
        EASY_BLOCK("MainLoop");
        int width, height;
        ASSERT_NO_THROW(glfwGetFramebufferSize(window, &width, &height));
        const float ratio = width / (float)height;

        ASSERT_NO_THROW(api.glViewport(0, 0, width, height));
        ASSERT_NO_THROW(api.glClear(GL_COLOR_BUFFER_BIT));

        const glm::mat4 m = glm::rotate(glm::mat4(1.0f), (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        const glm::mat4 p = glm::ortho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        const glm::mat4 mvp = p * m;

        ASSERT_NO_THROW(api.glUseProgram(*program));
        {
            EASY_BLOCK( "Pass1" );
            //std::this_thread::sleep_for( std::chrono::milliseconds(2) );
            ASSERT_NO_THROW(api.glNamedBufferSubData(*perFrameDataBuffer, 0, *kBufferSize, glm::value_ptr(mvp)));
            ASSERT_NO_THROW(api.glDrawArrays(GL_TRIANGLES, 0, 3));
        }

        {
            EASY_BLOCK( "glfwSwapBuffers()" );
            ASSERT_NO_THROW(glfwSwapBuffers(window));
        }

        {
            EASY_BLOCK( "glfwPollEvents()" );
            //std::this_thread::sleep_for( std::chrono::milliseconds(2) );
            ASSERT_NO_THROW(glfwPollEvents());
        }
    }

    EASY_BLOCK("Deleting OpenGL 4.6 resources");
    api.glDeleteTextures(1, texture);
    api.glDeleteBuffers(1, perFrameDataBuffer);
    api.glDeleteProgram(*program);
    api.glDeleteShader(*shaderFragment);
    api.glDeleteShader(*shaderVertex);
    api.glDeleteVertexArrays(1, vao);
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow* createWindow(){
        glfwSetErrorCallback(
                [](int error, const char* description)
                {
                    fprintf(stderr, "Error: %s\n", description);
                }
        );

        if (!glfwInit())
        exit(EXIT_FAILURE);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        GLFWwindow* window = glfwCreateWindow(1024, 768, "Simple example", nullptr, nullptr);
        if (!window)
        {
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwSetKeyCallback(
        window,
        [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
        );

        glfwMakeContextCurrent(window);

        return window;
}

GL4API createTextures(GLuint* shaderVertex , GLuint* shaderFragment,
                      GLuint* vao, GLuint* perFrameDataBuffer,
                      GLuint* texture, GLuint* program, GLuint* kBufferSize){
    GL4API api{};

    EASY_BLOCK("Create resources");
    GetAPI4(&api, [](const char* func) -> void* { return (void *)glfwGetProcAddress(func); });
    InjectAPITracer4(&api);

    *shaderVertex = api.glCreateShader(GL_VERTEX_SHADER);
    api.glShaderSource(*shaderVertex, 1, &shaderCodeVertex, nullptr);
    api.glCompileShader(*shaderVertex);

    *shaderFragment = api.glCreateShader(GL_FRAGMENT_SHADER);
    api.glShaderSource(*shaderFragment, 1, &shaderCodeFragment, nullptr);
    api.glCompileShader(*shaderFragment);

    *program = api.glCreateProgram();
    api.glAttachShader(*program, *shaderVertex);
    api.glAttachShader(*program, *shaderFragment);
    api.glLinkProgram(*program);

    api.glCreateVertexArrays(1, vao);
    api.glBindVertexArray(*vao);

     *kBufferSize = sizeof(glm::mat4);

    api.glCreateBuffers(1, perFrameDataBuffer);
    api.glNamedBufferStorage(*perFrameDataBuffer, *kBufferSize, nullptr, GL_DYNAMIC_STORAGE_BIT);
    api.glBindBufferRange(GL_UNIFORM_BUFFER, 0, *perFrameDataBuffer, 0, *kBufferSize);

    api.glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    int w, h, comp;
    const uint8_t* img = stbi_load("data/ch2_sample3_STB.jpg", &w, &h, &comp, 3);

    api.glCreateTextures(GL_TEXTURE_2D, 1, texture);
    api.glTextureParameteri(*texture, GL_TEXTURE_MAX_LEVEL, 0);
    api.glTextureParameteri(*texture, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    api.glTextureParameteri(*texture, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    api.glTextureStorage2D(*texture, 1, GL_RGB8, w, h);
    api.glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    api.glTextureSubImage2D(*texture, 0, 0, 0, w, h, GL_RGB, GL_UNSIGNED_BYTE, img);

    api.glBindTextures(0, 1, texture);

    return api;
}
