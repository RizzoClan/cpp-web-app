#ifndef CLI_CONTROLLER_H
#define CLI_CONTROLLER_H

// Standard Includes
#include <iostream>
#include <string>
#include <sstream>

// 3rd Party Includes
#include "crow.h"
#include "CLI11.hpp"
#include <json.hpp>

// Our Includes

class CLI_Parser {
    public:
        // default constructor
        CLI_Parser();

        /**
         * @Brief: Constructor that inately parses command line flags. Access results with "get_results()"
         * @Args:
         *      name: the name of the parser
         *      parser_description: Description of the parser
         *      argc: The number of arguments
         *      argv: The arguments
         * @Note: These arguments should be taken directly from int main(argc, argv)
         * @Note: using CLI11 for command-line parsing: https://cliutils.gitlab.io/CLI11Tutorial/
         */
        nlohmann::json parse_flags(int argc, char* argv[], std::string parser_name) const;

    private:
        // crow::json::wvalue parse_flags(int argc, char* argv[], std::string parser_name) const;
};

#endif
