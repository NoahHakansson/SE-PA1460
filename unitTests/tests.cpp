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
    WHEN("Object is a 'Ball' and options are Move it,Pick up") {
        std::string interactions = "Move it, pick up";
        THEN("'Move it' Should return 'Gently,Hard,Barbaric' ") {
            REQUIRE
                (interface.setInteractionOptions(optionOne) == "Gently,Hard,Barbaric");
        }
        THEN("'Pick up' Should return 'Gently,Hard' ") {
            REQUIRE
                (interface.setInteractionOptions(optionTwo) == "Gently,Hard");
        }
    }
}