#include "scenario.hpp"

void Scenario::render(){
    // Render Objects
    for (GameObject &obj : gameObjects){
        obj.render(renderer);
    }
}

void Scenario::update(){
    for (GameObject &obj : gameObjects){
        obj.update();
    }
}

void Scenario::handleEvent(SDL_Event &e){

}