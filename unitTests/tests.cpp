#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "GameObjectInterface.hpp"

//SETUP
GameObjectInterface interface;

TEST_CASE("selectObject") {
    WHEN("Object is a 'Ball'") {
        //ACTUAL TEST
        std::string objectName = "Ball";
        std::string result1 = interface.selectGameObject(objectName);
        THEN("Should return 'Interactions: Move it,Pick up'") {
            REQUIRE
                (result1 == "Move it,Pick up");
        }
    }
}

TEST_CASE("selectInteraction"){
        WHEN("Object is a 'Ball' and we are now selecting the interactionType 'move'") {
        //SETUP
        std::string objectName = "Ball";
        interface.selectGameObject(objectName);
        //ACTUAL TEST
        std::string result2 = interface.selectInteraction("Move it");
        THEN("Should return 'Options: Gently, Hard, Barbaric") {
            REQUIRE
                (result2 == "Options: Gently, Hard, Barbaric");
        }
    }
}

TEST_CASE("setInteractionOptions") {
    WHEN("Object is a 'Ball' and interactionType is 'MoveStrategy' We choose the option 'Barbaric'") {
        std::string theOption = "Barbaric";
        std::string result3 = interface.setInteractionOption(theOption);
        THEN("Option 'Barbaric' Should return 'SUCCESS' ") {
            REQUIRE
                (result3 == "SUCCESS");
        }
        
    }
}

TEST_CASE("startInteraction"){
    // TODO: startInteraction
}
