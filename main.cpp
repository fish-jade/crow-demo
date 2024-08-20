#include <crow.h>

using namespace std;

int main() 
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")
    ([]{
        return "Hello, World from Conan!";
    });

    app.port(8080).multithreaded().run();
    return 0;
}