#include "crow.h"
#include "CLI11.hpp"

int main(int argc, char *argv[])
{
    // we use CLI11 for command-line parsing: https://cliutils.gitlab.io/CLI11Tutorial/
    CLI::App cli_parser("Basic Crow Web App");
    CLI11_PARSE(cli_parser, argc, argv);

    // setup framework for web app using data taken in form command line
    crow::SimpleApp web_app;

    CROW_ROUTE(web_app, "/")
    ([]() {
        return "Hello world!";
    });

    web_app.port(18080).run();
}
