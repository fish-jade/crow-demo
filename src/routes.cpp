#include "routes.h"
#include "controllers/hello_controller.h"

void setup_routes(crow::SimpleApp& app) {
    HelloController::init_routes(app);
}
