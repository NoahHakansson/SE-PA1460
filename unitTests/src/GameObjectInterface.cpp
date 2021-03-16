#include "../GameObjectInterface.hpp"

GameObjectInterface::GameObjectInterface()
{
    GameObject ball("Ball");
    gameobjects.push_back(ball);
}

std::string GameObjectInterface::selectGameObject(std::string theGameObject)
{
    bool selected = false;
    for (int i = 0;i < gameobjects.size();i++) {
        if (gameobjects[i].getObjectName() == theGameObject) {
            CurrentObject = gameobjects[i];
            selected = true;
        }
    }

    if (selected == false) {
        return "Not existing GameObject";
    }

    return CurrentObject.listInteractionTypes();
}

std::string GameObjectInterface::selectInteraction(std::string theInteractionType) {
    CurrentObject.startInteraction(theInteractionType);

    std::string returnList = CurrentObject.listCurrentInteractionOptions();

    return returnList;
}

std::string GameObjectInterface::setInteractionOption(std::string theOption)
{
    std::string confirmationMessage = "";
    confirmationMessage = CurrentObject.setCurrentInteractionOption(theOption);
    return confirmationMessage;
}

std::string GameObjectInterface::startInteraction()
{
    std::string interactionResponse = "";
    interactionResponse = CurrentObject.startCurrentInteraction();
    return interactionResponse;
}

void GameObjectInterface::clear() {
    CurrentObject.clear();

    CurrentObject = GameObject();
}
