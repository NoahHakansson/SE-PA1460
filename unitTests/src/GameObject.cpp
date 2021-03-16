#include "../GameObject.hpp"
GameObject::GameObject(std::string name)
{
    objectName = name;
    moveStrategy *movestrat = new moveStrategy;
    pickUpStrategy *pickUpStrat = new pickUpStrategy;

    interactionList.push_back(movestrat);
    interactionList.push_back(pickUpStrat);
    // temporary harcoded default, should be set by selectInteraction
    currentType = movestrat;
}

std::string GameObject::getObjectName() { return objectName; }

std::string GameObject::listInteractionTypes()
{
    std::string returnList = "";
    for (int i = 0; i < interactionList.size(); i++)
    {
        returnList += (interactionList[i]->getName());
        if (i < interactionList.size() - 1)
        {
            returnList += ",";
        }
    }

    return returnList;
}

std::string GameObject::setCurrentInteractionOption(std::string theOption)
{
    std::string confirmationMessage = "";
    confirmationMessage = currentType->setOption(theOption);
    return confirmationMessage;
}

std::string GameObject::startCurrentInteraction()
{
    std::string interactionResponse = "";
    
    return interactionResponse;
}

void GameObject::startInteraction(std::string theInteractionType)
{
    selectStrategy(theInteractionType);
}

void GameObject::selectStrategy(std::string theInteractionType)
{
    bool selected = false;
    for (int i = 0; i < interactionList.size(); i++)
    {
        if (interactionList[i]->getName() == theInteractionType)
        {
            currentType = interactionList[i];
            selected = true;

            break;
        }
    }
    if (selected == false) {
        currentType = nullptr;
    }
}

std::string GameObject::listCurrentInteractionOptions()
{
    if (currentType != nullptr)
    {
        std::string returnList = currentType->listOptions();

        return returnList;
    }
    else {
        return "invalid interactionType";
    }
}

void GameObject::clear() {
    if (currentType != nullptr) {
        currentType->unsetOption();
    }
}
