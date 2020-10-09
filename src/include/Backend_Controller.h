#ifndef BACKEND_CONTROLLER_H
#define BACKEND_CONTROLLER_H

// Standard Includes
#include <iostream>
#include <string>
#include <sstream>

// 3rd Party Includes
#include "crow.h"
#include "CLI11.hpp"
#include <json.hpp>

// Our Includes
#include "CLI_Parser.h"
#include "constants.h"

// make CLI_Parser private so that main cannot double call functions it should not
class BackendController : private CLI_Parser {
    public:
        BackendController(int argc, char* argv[], bool shouldPrintUrls=true);
        /**
         * @Brief: Wrapper for all private functions that create routes for all the websites
         */
        void create_web_routes();

        /**
         * @Brief: Start up the middleware web app server
         * @Note: Must create all the web routes before starting the app
         */
        void start_web_app();

    private:
        /* ======================================= Private Helper Functions ======================================== */
        /**
         * @Brief: Create test website that just prints "hello world"
         */
        void setup_test_route();

        /**
         * @Brief: Print out all urls created by this app
         */
        void print_urls();

        /* ========================================== Private Variables  =========================================== */
        // variables set in constructor
        const nlohmann::json& flag_results;

        // web app's variables/objects
        crow::SimpleApp web_app; // initialize crow web middleware object
        bool areRoutesInitialized;
        bool _shouldPrintUrls;
        int port;
        std::string web_url;
};

#endif
