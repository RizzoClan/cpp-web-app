// Standard Includes
#include <iostream>
#include <string>
#include <sstream>

// 3rd Party Includes
#include "crow.h"
#include "CLI11.hpp"

// Our Includes
#include "Backend_Controller.h"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
    /******************* Create CLI Parser with Neccessary Flags (declare variables ahead of time) *******************/
    // using CLI11 for command-line parsing: https://cliutils.gitlab.io/CLI11Tutorial/
    CLI::App cli_parser("Basic Crow Web App");

    // create temp variables
    int port = 8080; //default to standard web port

    // create flags
    cli_parser.add_option("-p,--port", port, "Set the port to open the web app on")
        ->check(CLI::Range(1024, 65535), "Must select a valid port in the range");

    // actually parse flags
    CLI11_PARSE(cli_parser, argc, argv);


    /* ********************** setup framework for web app using data taken in form command line **********************/
    crow::SimpleApp web_app;

    // store url in variable to pass around if needed
    std::string web_url = "http://localhost:" + std::to_string(port);

    CROW_ROUTE(web_app, "/")
    ([]() {
        return "Hello world!";
    });

    cout << "Website is running at " << web_url << endl;
    web_app.port(port).run();
}
