//
// Created by maxim on 22/09/2022.
//


#include "gtest/gtest.h"

#include "../includes/GL.h"
#include "crossguid/guid.hpp"
#include <easy/profiler.h>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <stb_image.h>


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

int main(){
    const char * resourcePath = "data/ch2_sample3_STB.jpg";
    test_create_guid();
    test_load_resource(resourcePath);
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
