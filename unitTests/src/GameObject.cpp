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
    std::string returnList = "Interactions : ";
    for (int i = 0;i < interactionList.size();i++) {
        returnList += (interactionList[i]->getName() + ",");
    }

    return returnList;
}
