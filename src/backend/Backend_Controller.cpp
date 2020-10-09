#include "Backend_Controller.h"

// local namespace modifications
using std::cout;
using std::cerr;
using std::endl;

/* =============================================== Constructors ==================================================== */

BackendController::BackendController(int argc, char* argv[], bool shouldPrintUrls)
: flag_results(parse_flags(argc, argv, CLI_PARSER_NAME)) // Create CLI Parser with Neccessary Flags
{
    /* =============================== variables that need more info to declare ================================ */
    // store url in variable to pass around if needed
    web_url = URL_BASE + flag_results["port"].get<std::string>();
    port = std::atoi(flag_results["port"].get<std::string>().c_str());

    // flags
    areRoutesInitialized = false; // set true at end of init
    _shouldPrintUrls = shouldPrintUrls;
}

void BackendController::print_urls() {
    cout << "Website is running at " << web_url << endl;
}

/* ============================================== Web Route Functions ============================================== */
void BackendController::start_web_app() {
    if (!areRoutesInitialized) {
        cerr << "Routes have not been initialized yet!!" << endl;
        exit(EXIT_FAILURE);
    }

    // start running the web app
    web_app.port(port).run();
}

void BackendController::create_web_routes() {
    // call all private functions responsible for creating websites
    setup_test_route();

    // print all urls once created
    if (_shouldPrintUrls) {
        print_urls(); // dont print if user said not to
    }

    areRoutesInitialized = true;
}

void BackendController::setup_test_route() {
    CROW_ROUTE(web_app, "/")
    ([]() {
        return "Hello world!";
    });
}
