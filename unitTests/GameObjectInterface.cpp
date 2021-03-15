#include "GameObjectInterface.hpp"

GameObjectInterface::GameObjectInterface() {
    GameObject ball("Ball");
    gameobjects.push_back(ball);
}

std::string GameObjectInterface::selectGameObject(std::string theGameObject) {
    bool selected = false;
    for (int i = 0;i < gameobjects.size();i++) {
        if (gameobjects[i].getObjectName() == theGameObject) {
            CurrentObject = gameobjects[i];
            selected = true;
        }
    }

    if (selected == false) {
        return "null";
    }

    return CurrentObject.listInteractionTypes();
}
