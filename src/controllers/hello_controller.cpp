#include "controllers/hello_controller.h"
#include "services/hello_service.h"

void HelloController::init_routes(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/")
    ([]{
        return HelloService::get_greeting();
    });

    CROW_ROUTE(app, "/hello")
    ([]{
        return HelloService::get_custom_greeting("Crow");
    });
}
