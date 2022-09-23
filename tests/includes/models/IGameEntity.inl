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

namespace TexasHoldem {
    class IGameEntity {
    public:
        std::vector<GLShader*> Shaders;
        PerFrameData* FrameData;
    };
}
#endif //TEXASHOLDEM_PERFRAMEDATA_INL
