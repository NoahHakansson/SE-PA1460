#include <string>
#include <vector>

#include "interactionTypes.hpp"

class GameObject
{
private:
    std::string objectName;
    std::vector<interactionType *> interactionList;
public:
    GameObject(std::string name);
    GameObject() {}
    std::string getObjectName();
    std::string listInteractionTypes();
};