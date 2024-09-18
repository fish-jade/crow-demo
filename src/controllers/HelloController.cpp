#include "controllers/HelloController.h"
#include "services/HelloService.h"

void HelloController::InitRoutes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/")
    ([]{
        return HelloService::GetGreeting();
    });

    CROW_ROUTE(app, "/hello")
    ([]{
        return HelloService::GetCustomGreeting("Crow");
    });
}
