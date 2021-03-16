#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "GameObjectInterface.hpp"

GameObjectInterface interface;

TEST_CASE("selectObject") {
    WHEN("Object is a 'Ball'") {
        std::string objectName = "Ball";
        std::string result1 = interface.selectGameObject(objectName);
        THEN("Should return 'Interactions: Move it,Pick up'") {
            REQUIRE
                (result1 == "Move it,Pick up");
        }
    }
}

TEST_CASE("selectInteraction"){
    // TODO: selectInteraction
}

TEST_CASE("setInteractionOptions") {
    WHEN("Object is a 'Ball' and interactionType is 'MoveStrategy' We choose the option 'Barbaric'") {
        std::string theOption = "Barbaric";
        std::string result2 = interface.setInteractionOption(theOption);
        THEN("Option 'Barbaric' Should return 'SUCCESS' ") {
            REQUIRE
                (result2 == "SUCCESS");
        }
        
    }
}

TEST_CASE("startInteraction"){
    // TODO: startInteraction
}
