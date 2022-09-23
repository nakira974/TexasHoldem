//
// Created by maxim on 23/09/2022.
//

#ifndef TEXASHOLDEM_PERFRAMEDATA_INL
#define TEXASHOLDEM_PERFRAMEDATA_INL

#include <cstdio>
#include <cstdlib>
#include <string>
#include <utility>
#include <vector>
#include "GLShader.h"
#include "PerFrameData.hpp"
#include <crossguid/guid.hpp>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>


namespace TexasHoldem {
    class IGameEntity {

#ifndef Constructors
#define Constructors
    protected:
        ~IGameEntity(){
            for (auto & shader : Shaders)
                delete shader;

            Shaders.clear();

        }

        IGameEntity(std::vector<GLShader*> shaders, PerFrameData* perFrameData){
            FrameData = perFrameData;
            Hashcode = setNewGuid();
            Shaders = std::move(shaders);
        }
#endif //Constructors

#ifndef Properties
#define Properties
    public:
        std::vector<GLShader*> Shaders;
        PerFrameData* FrameData;
        std::string Hashcode;
        uint8_t* Image;
#endif //Properties


#ifndef Methods
#define Methods
    public :
        bool load(char * resourcePath){
            bool result = false;
            int w, h, comp;
            Image = stbi_load(resourcePath, &w, &h, &comp, 3);
            result = (Image != nullptr);
            return result;
        }

        bool unload(){
            bool result = false;

            return result;
    }

    private:
        static std::string setNewGuid()
        {
            auto myGuid = xg::newGuid();
            std::stringstream stream;
            stream << myGuid;
            return stream.str();
        }
#endif //Methods
};
}
#endif //TEXASHOLDEM_PERFRAMEDATA_INL
