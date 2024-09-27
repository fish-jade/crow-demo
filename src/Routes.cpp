#include "Routes.h"
#include "controllers/HelloController.h"

void SetupRoutes(crow::SimpleApp& app) {
    HelloController::InitRoutes(app);
    CROW_ROUTE(app, "/resource/v1/update")
        .methods("POST"_method)([](const crow::request& req) {
            std::string file_name;
            crow::multipart::message form_data(req);
            crow::json::wvalue response_body;
            response_body["code"] = 200;
            response_body["message"] = "success";
            return response_body;
        });
}
