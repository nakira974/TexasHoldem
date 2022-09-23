//
// Created by maxim on 22/09/2022.
//

#ifndef TEXASHOLDEM_CARD_HPP
#define TEXASHOLDEM_CARD_HPP

#ifndef Includes
#define Includes
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include "IGameEntity.inl"
#endif //Includes

namespace TexasHoldem {
    class Card :  IGameEntity {
#ifndef Constructors
#define Constructors
    public :
        ~Card(){

        }

         Card(){

        }
#endif //Constructors


#ifndef Properties
#define Properties
    public:
        short Number;

#endif //Properties

#ifndef Methods
#define Methods

#endif //Methods

    };
}

#endif //TEXASHOLDEM_CARD_HPP
