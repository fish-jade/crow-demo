#include "Routes.h"
#include "controllers/HelloController.h"

void SetupRoutes(crow::SimpleApp& app) {
    HelloController::InitRoutes(app);
}
