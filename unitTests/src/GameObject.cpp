#include "../GameObject.hpp"
GameObject::GameObject(std::string name) {
    objectName = name;
    moveStrategy* movestrat = new moveStrategy;
    pickUpStrategy* pickUpStrat = new pickUpStrategy;

    interactionList.push_back(movestrat);
    interactionList.push_back(pickUpStrat);
}

std::string GameObject::getObjectName() { return objectName; }

std::string GameObject::listInteractionTypes() {
    std::string returnList = "";
    for (int i = 0;i < interactionList.size();i++) {
        returnList += (interactionList[i]->getName());
        if (i < interactionList.size() -1)
        {
            returnList += ",";
        }
    }

    return returnList;
}
