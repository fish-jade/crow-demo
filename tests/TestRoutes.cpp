#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <crow.h>
#include "Routes.h"

TEST_CASE("Test root route") {
    crow::SimpleApp app;
    setup_routes(app);

    auto response = app.handle_request("GET", "/");
    REQUIRE(response.code == 200);
    REQUIRE(response.body == "Hello, World from Conan!");
}

TEST_CASE("Test hello route") {
    crow::SimpleApp app;
    setup_routes(app);

    auto response = app.handle_request("GET", "/hello");
    REQUIRE(response.code == 200);
    REQUIRE(response.body == "Hello, Crow!");
}
