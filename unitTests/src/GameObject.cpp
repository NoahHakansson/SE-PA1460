#include "../GameObject.hpp"
GameObject::GameObject(std::string name)
{
    objectName = name;
    moveStrategy* movestrat = new moveStrategy;
    pickUpStrategy* pickUpStrat = new pickUpStrategy;
    currentState = new OnGroundState;

    interactionList.push_back(movestrat);
    interactionList.push_back(pickUpStrat);
    // temporary harcoded default, should be set by selectInteraction
    // currentType = movestrat;
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
    if (currentType != nullptr){
        confirmationMessage = currentType->setOption(theOption);
    }else {
        confirmationMessage = "Can't choose option, NO INTERACTIONTYPE SELECTED!";
    }
    return confirmationMessage;
}

std::string GameObject::startCurrentInteraction()
{
    std::string interactionResponse = "";
    if (currentType != nullptr){
        interactionResponse += currentType->getName();
        this->changeState(interactionResponse);
        interactionResponse = "Interaction: " + interactionResponse;
        interactionResponse += ",Option: ";
        interactionResponse += currentType->getOption();
        interactionResponse += (",State: " + currentState->getState());
    }else {
        interactionResponse = "Can't start interaction, NO INTERACTIONTYPE SELECTED!";
    }
    return interactionResponse;
}

void GameObject::changeState(std::string interactionResponse)
{
    if (currentType->getOption() != "NULL"){
        if (interactionResponse == "Pick up"){
            currentState = new PickedUpState;
        }
        else if (interactionResponse == "Move it"){
            currentState = new MovedState;
        }
        else if (interactionResponse == "Drop it"){
            currentState = new OnGroundState;
        }
    }
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
