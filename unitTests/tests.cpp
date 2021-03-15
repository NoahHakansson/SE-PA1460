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

TEST_CASE("selectInteraction"){
    // TODO: selectInteraction
}

TEST_CASE("setInteractionOptions") {
    WHEN("Object is a 'Ball' and interactionType is 'MoveStrategy' We choose the option 'Barbaric'") {
        std::string theOption = "Barbaric";
        THEN("Option 'Barbaric' Should return 'SUCCESS' ") {
            REQUIRE
                (interface.setInteractionOption(theOption) == "SUCCESS");
        }
        
    }
}

TEST_CASE("startInteraction"){
    // TODO: startInteraction
}
