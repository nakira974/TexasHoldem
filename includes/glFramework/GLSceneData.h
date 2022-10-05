#pragma once

#include "../scene/Scene.h"
#include "../scene/Material.h"
#include "../scene/VtxData.h"
#include "../glFramework/GLShader.h"
#include "../glFramework/GLTexture.h"

class GLSceneData
{
public:
	GLSceneData(
		const char* meshFile,
		const char* sceneFile,
		const char* materialFile,
        GL4API* api);

	std::vector<GLTexture> allMaterialTextures_;
    GL4API* api_;
	MeshFileHeader header_;
	MeshData meshData_;

	Scene scene_;
	std::vector<MaterialDescription> materials_;
	std::vector<DrawData> shapes_;

	void loadScene(const char* sceneFile);
};
