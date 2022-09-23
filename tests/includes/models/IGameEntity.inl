//
// Created by maxim on 23/09/2022.
//

#ifndef TEXASHOLDEM_PERFRAMEDATA_INL
#define TEXASHOLDEM_PERFRAMEDATA_INL

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include "GLShader.h"
#include "PerFrameData.hpp"
#include <crossguid/guid.hpp>
#include <iostream>

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

        IGameEntity(std::vector<GLShader*> shaders, PerFrameData* perFrameData, uint8_t image){
            Image = image;
            FrameData = perFrameData;
            Hashcode = setNewGuid();
            Shaders = shaders;
        }
#endif //Constructors

#ifndef Properties
#define Properties
    public:
        std::vector<GLShader*> Shaders;
        PerFrameData* FrameData;
        std::string Hashcode;
        uint8_t Image;
#endif //Properties


#ifndef Methods
#define Methods
    public :
        bool load(){
        bool result = false;

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
