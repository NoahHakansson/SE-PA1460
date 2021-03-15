#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "GameObjectInterface.hpp"

GameObjectInterface interface;

TEST_CASE() {
    REQUIRE(interface.selectGameObject("Ball") == "Interactions : Move it,Pick up,");
}