#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "GameObjectInterface.hpp"

GameObjectInterface interface;

TEST_CASE("selectObject") {
    WHEN("Object is a 'Ball'") {
        std::string objectName = "Ball";
        THEN("Should return 'Interactions: Move it,Pick up'") {
            REQUIRE
                (interface.selectGameObject(objectName) == "Move it,Pick up");
        }
    }
}
TEST_CASE("setInteractionOptions") {
    WHEN("Object is a 'Ball' and interactionType is 'MoveStrategy' We choose the option 'Gently'") {
        std::string theOption = "Gently";
        THEN("Option 'Gently' Should return 'SUCCESS' ") {
            REQUIRE
                (interface.setInteractionOption(theOption) == "SUCCESS");
        }
        
    }
}