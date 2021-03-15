#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "GameObjectInterface.hpp"

GameObjectInterface interface;

TEST_CASE("selectObject") {
    WHEN("Object is a 'Ball'") {
        std::string objectName = "Ball";
        THEN("Should return 'Interactions : Move it,Pick up'") {
            REQUIRE(interface.selectGameObject(objectName) == "Interactions : Move it,Pick up");
        }
    }
}
TEST_CASE("setInteractionOptions") {
    REQUIRE(5==6);
}