//
// Created by maxim on 23/09/2022.
//

#ifndef TEXASHOLDEM_PERFRAMEDATA_HPP
#define TEXASHOLDEM_PERFRAMEDATA_HPP

#include "glm/glm.hpp"
#include "glm/ext.hpp"

namespace TexasHoldem{
    struct PerFrameData{
        glm::mat4 view;
        glm::mat4 proj;
        glm::vec4 cameraPos;
    };
}
#endif //TEXASHOLDEM_PERFRAMEDATA_HPP
