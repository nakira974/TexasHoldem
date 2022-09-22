﻿#include <assert.h>

#include "../includes/GL.h"
#include "../includes/GLAPITrace.h"

#define W( en ) if ( e == en ) return #en;

std::string Enum2String(GLenum e)
{
	/* BeginMode */
	W(GL_POINTS);
	W(GL_LINES);
	W(GL_LINE_LOOP);
	W(GL_LINE_STRIP);
	W(GL_TRIANGLES);
	W(GL_TRIANGLE_STRIP);
	W(GL_TRIANGLE_FAN);

	/* BlendingFactorDest */
	W(GL_SRC_COLOR);
	W(GL_ONE_MINUS_SRC_COLOR);
	W(GL_SRC_ALPHA);
	W(GL_ONE_MINUS_SRC_ALPHA);
	W(GL_DST_ALPHA);
	W(GL_ONE_MINUS_DST_ALPHA);

	/* BlendingFactorSrc */
	W(GL_DST_COLOR);
	W(GL_ONE_MINUS_DST_COLOR);
	W(GL_SRC_ALPHA_SATURATE);

	/* BlendEquationSeparate */
	W(GL_FUNC_ADD);
	W(GL_BLEND_EQUATION);
	W(GL_BLEND_EQUATION_RGB);
	W(GL_BLEND_EQUATION_ALPHA);

	/* BlendSubtract */
	W(GL_FUNC_SUBTRACT);
	W(GL_FUNC_REVERSE_SUBTRACT);

	/* Separate Blend Functions */
	W(GL_BLEND_DST_RGB);
	W(GL_BLEND_SRC_RGB);
	W(GL_BLEND_DST_ALPHA);
	W(GL_BLEND_SRC_ALPHA);
	W(GL_CONSTANT_COLOR);
	W(GL_ONE_MINUS_CONSTANT_COLOR);
	W(GL_CONSTANT_ALPHA);
	W(GL_ONE_MINUS_CONSTANT_ALPHA);
	W(GL_BLEND_COLOR);

	/* Buffer Objects */
	W(GL_ARRAY_BUFFER);
	W(GL_ELEMENT_ARRAY_BUFFER);
	W(GL_ARRAY_BUFFER_BINDING);
	W(GL_ELEMENT_ARRAY_BUFFER_BINDING);

	W(GL_STREAM_DRAW);
	W(GL_STATIC_DRAW);
	W(GL_DYNAMIC_DRAW);

	W(GL_BUFFER_SIZE);
	W(GL_BUFFER_USAGE);

	W(GL_CURRENT_VERTEX_ATTRIB);

	/* CullFaceMode */
	W(GL_FRONT);
	W(GL_BACK);
	W(GL_FRONT_AND_BACK);

	/* EnableCap */
	W(GL_TEXTURE_2D);
	W(GL_CULL_FACE);
	W(GL_BLEND);
	W(GL_DITHER);
	W(GL_STENCIL_TEST);
	W(GL_DEPTH_TEST);
	W(GL_SCISSOR_TEST);
	W(GL_POLYGON_OFFSET_FILL);
	W(GL_SAMPLE_ALPHA_TO_COVERAGE);
	W(GL_SAMPLE_COVERAGE);

	/* ErrorCode */
	W(GL_INVALID_ENUM);
	W(GL_INVALID_VALUE);
	W(GL_INVALID_OPERATION);
	W(GL_OUT_OF_MEMORY);

	/* FrontFaceDirection */
	W(GL_CW);
	W(GL_CCW);

	/* GetPName */
	W(GL_LINE_WIDTH);
	W(GL_ALIASED_LINE_WIDTH_RANGE);
	W(GL_CULL_FACE_MODE);
	W(GL_FRONT_FACE);
	W(GL_DEPTH_RANGE);
	W(GL_DEPTH_WRITEMASK);
	W(GL_DEPTH_CLEAR_VALUE);
	W(GL_DEPTH_FUNC);
	W(GL_STENCIL_CLEAR_VALUE);
	W(GL_STENCIL_FUNC);
	W(GL_STENCIL_FAIL);
	W(GL_STENCIL_PASS_DEPTH_FAIL);
	W(GL_STENCIL_PASS_DEPTH_PASS);
	W(GL_STENCIL_REF);
	W(GL_STENCIL_VALUE_MASK);
	W(GL_STENCIL_WRITEMASK);
	W(GL_STENCIL_BACK_FUNC);
	W(GL_STENCIL_BACK_FAIL);
	W(GL_STENCIL_BACK_PASS_DEPTH_FAIL);
	W(GL_STENCIL_BACK_PASS_DEPTH_PASS);
	W(GL_STENCIL_BACK_REF);
	W(GL_STENCIL_BACK_VALUE_MASK);
	W(GL_STENCIL_BACK_WRITEMASK);
	W(GL_VIEWPORT);
	W(GL_SCISSOR_BOX);
	/*      GL_SCISSOR_TEST */
	W(GL_COLOR_CLEAR_VALUE);
	W(GL_COLOR_WRITEMASK);
	W(GL_UNPACK_ALIGNMENT);
	W(GL_PACK_ALIGNMENT);
	W(GL_MAX_TEXTURE_SIZE);
	W(GL_MAX_VIEWPORT_DIMS);
	W(GL_SUBPIXEL_BITS);
	W(GL_POLYGON_OFFSET_UNITS);
	/*      GL_POLYGON_OFFSET_FILL */
	W(GL_POLYGON_OFFSET_FACTOR);
	W(GL_TEXTURE_BINDING_2D);
	W(GL_SAMPLE_BUFFERS);
	W(GL_SAMPLES);
	W(GL_SAMPLE_COVERAGE_VALUE);
	W(GL_SAMPLE_COVERAGE_INVERT);

	W(GL_NUM_COMPRESSED_TEXTURE_FORMATS);
	W(GL_COMPRESSED_TEXTURE_FORMATS);

	/* HintMode */
	W(GL_DONT_CARE);
	W(GL_FASTEST);
	W(GL_NICEST);

	/* DataType */
	W(GL_BYTE);
	W(GL_UNSIGNED_BYTE);
	W(GL_SHORT);
	W(GL_UNSIGNED_SHORT);
	W(GL_INT);
	W(GL_UNSIGNED_INT);
	W(GL_FLOAT);
	W(GL_FIXED);

	/* PixelFormat */
	W(GL_DEPTH_COMPONENT);
	W(GL_ALPHA);
	W(GL_RGB);
	W(GL_RGBA);
	W(GL_COMPRESSED_RGB8_ETC2);
	W(GL_COMPRESSED_RGBA8_ETC2_EAC);

	/* PixelType */
	W(GL_UNSIGNED_SHORT_4_4_4_4);
	W(GL_UNSIGNED_SHORT_5_5_5_1);
	W(GL_UNSIGNED_SHORT_5_6_5);

	/* Shaders */
	W(GL_FRAGMENT_SHADER);
	W(GL_VERTEX_SHADER);
	W(GL_MAX_VERTEX_ATTRIBS);
	W(GL_MAX_VERTEX_UNIFORM_VECTORS);
	W(GL_MAX_FRAGMENT_UNIFORM_VECTORS);
	W(GL_MAX_VARYING_VECTORS);

	W(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS);
	W(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS);
	W(GL_MAX_TEXTURE_IMAGE_UNITS);
	W(GL_SHADER_TYPE);
	W(GL_DELETE_STATUS);
	W(GL_LINK_STATUS);
	W(GL_VALIDATE_STATUS);
	W(GL_ATTACHED_SHADERS);
	W(GL_ACTIVE_UNIFORMS);
	W(GL_ACTIVE_UNIFORM_MAX_LENGTH);
	W(GL_ACTIVE_ATTRIBUTES);
	W(GL_ACTIVE_ATTRIBUTE_MAX_LENGTH);
	W(GL_SHADING_LANGUAGE_VERSION);
	W(GL_CURRENT_PROGRAM);

	/* StencilFunction */
	W(GL_NEVER);
	W(GL_LESS);
	W(GL_EQUAL);
	W(GL_LEQUAL);
	W(GL_GREATER);
	W(GL_NOTEQUAL);
	W(GL_GEQUAL);
	W(GL_ALWAYS);

	/* StencilOp */
	W(GL_KEEP);
	W(GL_REPLACE);
	W(GL_INCR);
	W(GL_DECR);
	W(GL_INVERT);
	W(GL_INCR_WRAP);
	W(GL_DECR_WRAP);

	/* StringName */
	W(GL_VENDOR);
	W(GL_RENDERER);
	W(GL_VERSION);
	W(GL_EXTENSIONS);

	/* TextureMagFilter */
	W(GL_NEAREST);
	W(GL_LINEAR);

	/* TextureMinFilter */
	W(GL_NEAREST_MIPMAP_NEAREST);
	W(GL_LINEAR_MIPMAP_NEAREST);
	W(GL_NEAREST_MIPMAP_LINEAR);
	W(GL_LINEAR_MIPMAP_LINEAR);

	/* TextureParameterName */
	W(GL_TEXTURE_MAG_FILTER);
	W(GL_TEXTURE_MIN_FILTER);
	W(GL_TEXTURE_WRAP_S);
	W(GL_TEXTURE_WRAP_T);

	/* TextureTarget */
	W(GL_TEXTURE);

	W(GL_TEXTURE_CUBE_MAP);
	W(GL_TEXTURE_BINDING_CUBE_MAP);
	W(GL_TEXTURE_CUBE_MAP_POSITIVE_X);
	W(GL_TEXTURE_CUBE_MAP_NEGATIVE_X);
	W(GL_TEXTURE_CUBE_MAP_POSITIVE_Y);
	W(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y);
	W(GL_TEXTURE_CUBE_MAP_POSITIVE_Z);
	W(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z);
	W(GL_MAX_CUBE_MAP_TEXTURE_SIZE);

	/* TextureUnit */
	W(GL_TEXTURE0);
	W(GL_TEXTURE1);
	W(GL_TEXTURE2);
	W(GL_TEXTURE3);
	W(GL_TEXTURE4);
	W(GL_TEXTURE5);
	W(GL_TEXTURE6);
	W(GL_TEXTURE7);
	W(GL_TEXTURE8);
	W(GL_TEXTURE9);
	W(GL_TEXTURE10);
	W(GL_TEXTURE11);
	W(GL_TEXTURE12);
	W(GL_TEXTURE13);
	W(GL_TEXTURE14);
	W(GL_TEXTURE15);
	W(GL_TEXTURE16);
	W(GL_TEXTURE17);
	W(GL_TEXTURE18);
	W(GL_TEXTURE19);
	W(GL_TEXTURE20);
	W(GL_TEXTURE21);
	W(GL_TEXTURE22);
	W(GL_TEXTURE23);
	W(GL_TEXTURE24);
	W(GL_TEXTURE25);
	W(GL_TEXTURE26);
	W(GL_TEXTURE27);
	W(GL_TEXTURE28);
	W(GL_TEXTURE29);
	W(GL_TEXTURE30);
	W(GL_TEXTURE31);
	W(GL_ACTIVE_TEXTURE);

	/* TextureWrapMode */
	W(GL_REPEAT);
	W(GL_CLAMP_TO_EDGE);
	W(GL_MIRRORED_REPEAT);

	/* Uniform Types */
	W(GL_FLOAT_VEC2);
	W(GL_FLOAT_VEC3);
	W(GL_FLOAT_VEC4);
	W(GL_INT_VEC2);
	W(GL_INT_VEC3);
	W(GL_INT_VEC4);
	W(GL_BOOL);
	W(GL_BOOL_VEC2);
	W(GL_BOOL_VEC3);
	W(GL_BOOL_VEC4);
	W(GL_FLOAT_MAT2);
	W(GL_FLOAT_MAT3);
	W(GL_FLOAT_MAT4);
	W(GL_SAMPLER_2D);
	W(GL_SAMPLER_CUBE);

	/* Vertex Arrays */
	W(GL_VERTEX_ATTRIB_ARRAY_ENABLED);
	W(GL_VERTEX_ATTRIB_ARRAY_SIZE);
	W(GL_VERTEX_ATTRIB_ARRAY_STRIDE);
	W(GL_VERTEX_ATTRIB_ARRAY_TYPE);
	W(GL_VERTEX_ATTRIB_ARRAY_NORMALIZED);
	W(GL_VERTEX_ATTRIB_ARRAY_POINTER);
	W(GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING);

	/* Read Format */
	W(GL_IMPLEMENTATION_COLOR_READ_TYPE);
	W(GL_IMPLEMENTATION_COLOR_READ_FORMAT);

	/* Shader Source */
	W(GL_COMPILE_STATUS);
	W(GL_INFO_LOG_LENGTH);
	W(GL_SHADER_SOURCE_LENGTH);
	W(GL_SHADER_COMPILER);

	/* Shader Binary */
	W(GL_SHADER_BINARY_FORMATS);
	W(GL_NUM_SHADER_BINARY_FORMATS);

	/* Shader Precision-Specified Types */
	W(GL_LOW_FLOAT);
	W(GL_MEDIUM_FLOAT);
	W(GL_HIGH_FLOAT);
	W(GL_LOW_INT);
	W(GL_MEDIUM_INT);
	W(GL_HIGH_INT);

	/* Framebuffer Object. */
	W(GL_FRAMEBUFFER);
	W(GL_RENDERBUFFER);

	W(GL_RGBA4);
	W(GL_RGB5_A1);
	W(GL_RGB565);
	W(GL_DEPTH_COMPONENT16);
	W(GL_STENCIL_INDEX);
	W(GL_STENCIL_INDEX8);
	W(GL_RENDERBUFFER_WIDTH);
	W(GL_RENDERBUFFER_HEIGHT);
	W(GL_RENDERBUFFER_INTERNAL_FORMAT);
	W(GL_RENDERBUFFER_RED_SIZE);
	W(GL_RENDERBUFFER_GREEN_SIZE);
	W(GL_RENDERBUFFER_BLUE_SIZE);
	W(GL_RENDERBUFFER_ALPHA_SIZE);
	W(GL_RENDERBUFFER_DEPTH_SIZE);
	W(GL_RENDERBUFFER_STENCIL_SIZE);

	W(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE);
	W(GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME);
	W(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL);
	W(GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE);

	W(GL_COLOR_ATTACHMENT0);
	W(GL_DEPTH_ATTACHMENT);
	W(GL_STENCIL_ATTACHMENT);

	W(GL_FRAMEBUFFER_COMPLETE);
	W(GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT);
	W(GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT);
	W(GL_FRAMEBUFFER_UNSUPPORTED);

	W(GL_FRAMEBUFFER_BINDING);
	W(GL_RENDERBUFFER_BINDING);
	W(GL_MAX_RENDERBUFFER_SIZE);

	W(GL_INVALID_FRAMEBUFFER_OPERATION);

	W(GL_TEXTURE_WIDTH);
	W(GL_TEXTURE_HEIGHT);
	W(GL_TEXTURE_INTERNAL_FORMAT);
	W(GL_LINE);
	W(GL_FILL);
	W(GL_UNIFORM_BUFFER);
	W(GL_RGBA32F);
	W(GL_RGB32F);
	W(GL_RGBA16F);
	W(GL_COMPRESSED_RED);
	W(GL_COMPRESSED_RGB);
	W(GL_COMPRESSED_RGBA);
	W(GL_RED);
	W(GL_R16);
	W(GL_R32F);
	W(GL_RGB16F);
	W(GL_TEXTURE_3D);
	W(GL_DEPTH_COMPONENT24);
	W(GL_BGR);
	W(GL_BGRA);
	W(GL_TEXTURE_COMPRESSED_IMAGE_SIZE);
	W(GL_TEXTURE_COMPRESSED);
	W(GL_TIME_ELAPSED);
	W(GL_TIMESTAMP);
	W(GL_QUERY_RESULT);
	W(GL_QUERY_RESULT_AVAILABLE);
	W(GL_PROGRAM_BINARY_LENGTH);
	W(GL_PROGRAM_BINARY_RETRIEVABLE_HINT);
	W(GL_UNIFORM_BLOCK_DATA_SIZE);
	W(GL_GEOMETRY_SHADER);
	W(GL_PATCHES);
	W(GL_PATCH_VERTICES);
	W(GL_TESS_EVALUATION_SHADER);
	W(GL_TESS_CONTROL_SHADER);

	return std::to_string(e);
}
