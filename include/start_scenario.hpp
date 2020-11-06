#ifndef _START_SCENARIO_H
#define _START_SCENARIO_H

#include "scenario.hpp"

struct StartScenario: public Scenario
{
    StartScenario(SDL_Renderer *_renderer): Scenario(_renderer){}

    StartScenario(SDL_Renderer *_renderer, std::vector<GameObject> objects): Scenario(_renderer, objects){}
};


#endif