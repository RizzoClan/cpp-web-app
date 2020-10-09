// Standard Includes
#include <iostream>
#include <string>
#include <sstream>

// 3rd Party Includes
#include <json.hpp>

// Our Includes
#include "Backend_Controller.h"

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char *argv[])
{
    /************************ setup framework for web app using data taken in form command line **********************/
    // create object & parses command line flags
    BackendController app(argc, argv);

    // setup all websites
    app.create_web_routes();

    // start the web app. Nothing gets run after this point!
    app.start_web_app();

    // finish program (only reached after control+c)
    return EXIT_SUCCESS;
}
