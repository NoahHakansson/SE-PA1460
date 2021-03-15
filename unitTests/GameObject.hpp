#include <string>
#include <vector>

#include "interactionTypes.hpp"

class GameObject
{
private:
    std::string objectName;
    std::vector<interactionType *> interactionList;
    interactionType* currentType;
public:
    GameObject(std::string name);
    GameObject() {}
    std::string getObjectName();
    std::string listInteractionTypes();
    std::string setCurrentInteractionOption(std::string theOption);
};