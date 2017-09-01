//
// Created by kenwi on 9/1/17.
//

#ifndef GREAT_COD_STATEBASE_H
#define GREAT_COD_STATEBASE_H


#include "Application.h"

class StateBase {
public:
    StateBase(Application& application) : application(&application)  {

    }

    virtual void render(sf::RenderTarget& renderTarget) = 0;
private:
    Application* application;
};


#endif //GREAT_COD_STATEBASE_H
