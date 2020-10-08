#include "Backend_Controller.h"

// local namespace modifications
using std::cout;
using std::cerr;
using std::endl;

// int main(int argc, char *argv[])
// {
//     /******************* Create CLI Parser with Neccessary Flags (declare variables ahead of time) *******************/
//     CLI_Parser flag_parser;
//     nlohmann::json flag_results = flag_parser.parse_flags(argc, argv, "Basic Crow Web App");


//     /* ********************** setup framework for web app using data taken in form command line **********************/
//     crow::SimpleApp web_app;
//     // store url in variable to pass around if needed
//     std::string web_url = "http://localhost:" + flag_results["port"].get<std::string>();

//     CROW_ROUTE(web_app, "/")
//     ([]() {
//         return "Hello world!";
//     });

//     cout << "Website is running at " << web_url << endl;
//     web_app.port(
//         std::atoi(flag_results["port"].get<std::string>().c_str())
//     ).run();
// }
