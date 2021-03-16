#include <string>
#include <vector>

#include "GameObject.hpp"

class GameObjectInterface
{
private:
    std::vector<GameObject> gameobjects;
    GameObject CurrentObject;
public:
    GameObjectInterface();
    std::string selectGameObject(std::string theGameObject);
    std::string selectInteraction(std::string theInteractionType);
    std::string setInteractionOption(std::string theOption);
};