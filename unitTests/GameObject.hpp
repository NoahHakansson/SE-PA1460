#include <string>
#include <vector>

#include "interactionTypes.hpp"
#include "ObjectState.hpp"

class GameObject
{
private:
    std::string objectName;
    std::vector<interactionType *> interactionList;
    interactionType* currentType = nullptr;
    ObjectState* currentState = nullptr;
    void selectStrategy(std::string theInteractionType);
public:
    GameObject(std::string name);
    GameObject() {}
    std::string getObjectName();
    std::string listInteractionTypes();
    std::string listCurrentInteractionOptions();
    void startInteraction(std::string theInteractionType);
    std::string setCurrentInteractionOption(std::string theOption);
    void clear();
    std::string startCurrentInteraction();
};