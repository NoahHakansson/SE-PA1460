#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "GameObjectInterface.hpp"

//SETUP

TEST_CASE("selectObject") {
    WHEN("Object is a 'Ball'") {
        //ACTUAL TEST
        GameObjectInterface interface;
        std::string objectName = "Ball";
        std::string result1 = interface.selectGameObject(objectName);
        THEN("Should return 'Interactions: Move it,Pick up'") {
            REQUIRE
                (result1 == "Move it,Pick up");
        }
        //CLEAN UP
        interface.clear();
    }
}

TEST_CASE("selectInteraction"){
        WHEN("Object is a 'Ball' and we are now selecting the interactionType 'move'") {
        //SETUP
        GameObjectInterface interface;
        std::string objectName = "Ball";
        interface.selectGameObject(objectName);
        //ACTUAL TEST
        std::string result2 = interface.selectInteraction("Move it");
        THEN("Should return 'Options: Gently, Hard, Barbaric") {
            REQUIRE
                (result2 == "Options: Gently, Hard, Barbaric");
        }
        //CLEAN UP
        interface.clear();
    }
}

TEST_CASE("setInteractionOptions") {
    WHEN("Object is a 'Ball' and interactionType is 'MoveStrategy' We choose the option 'Barbaric'") {
        //SETUP
        GameObjectInterface interface;
        std::string objectName = "Ball";
        interface.selectGameObject(objectName);
        interface.selectInteraction("Move it");
        //ACTUAL TEST
        std::string theOption = "Barbaric";
        std::string result3 = interface.setInteractionOption(theOption);
        THEN("Option 'Barbaric' Should return 'SUCCESS' ") {
            REQUIRE
                (result3 == "SUCCESS");
        }
        //CLEAN UP
        interface.clear();
    }
}

TEST_CASE("startInteraction"){
    // TODO: startInteraction
}

TEST_CASE("selectObject - Alternative") {
    WHEN("Tries to select GameObject: 'Pterodactyl") {
        //ACTUAL TEST
        GameObjectInterface interface;
        std::string objectName = "Pterodactyl";
        std::string result1 = interface.selectGameObject(objectName);
        THEN("Will fail as the GameObject doesn't exist") {
            REQUIRE
                (result1 == "Move it,Ride it");
        }
        //CLEAN UP
        interface.clear();
    }
}

TEST_CASE("selectInteraction - Alternative"){
        WHEN("Object is a 'Ball' and we are now selecting the interactionType 'Turn On'") {
        //SETUP
        GameObjectInterface interface;
        std::string objectName = "Ball";
        interface.selectGameObject(objectName);
        //ACTUAL TEST
        std::string result2 = interface.selectInteraction("Turn On");
        THEN("Should fail as a ball obviously can't be turned on or off") {
            REQUIRE
                (result2 == "Options: Gently, Hard, Barbaric");
        }
        //CLEAN UP
        interface.clear();
    }
}

TEST_CASE("setInteractionOptions - Alternative") {
    WHEN("Object is a 'Ball' and interactionType is 'MoveStrategy' We choose the option 'Blissful'") {
        //SETUP
        GameObjectInterface interface;
        std::string objectName = "Ball";
        interface.selectGameObject(objectName);
        interface.selectInteraction("Move it");
        //ACTUAL TEST
        std::string theOption = "Blissful";
        std::string result3 = interface.setInteractionOption(theOption);
        THEN("Option 'Barbaric' Should return 'FAILED' as blissful is not part of the options ") {
            REQUIRE
                (result3 == "SUCCESS");
        }
        //CLEAN UP
        interface.clear();
    }
}
