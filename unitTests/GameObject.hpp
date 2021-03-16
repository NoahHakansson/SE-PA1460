#include <string>
#include <vector>

#include "interactionTypes.hpp"

class GameObject
{
private:
    std::string objectName;
    std::vector<interactionType *> interactionList;
    interactionType* currentType = nullptr;
    std::string currentState;
    void selectStrategy(std::string theInteractionType);
public:
    GameObject(std::string name);
    GameObject() {}
    std::string getObjectName();
    std::string listInteractionTypes();
    std::string listCurrentInteractionOptions();
    void startInteraction(std::string theInteractionType);
    std::string setCurrentInteractionOption(std::string theOption);
<<<<<<< HEAD
    void clear();
=======
    std::string startCurrentInteraction();
>>>>>>> c01e1b7dd693c1bc930f1535ee95155d50606756
};