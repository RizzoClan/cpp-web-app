// @File: This file is meant to store constants that would otherwise be magic values

#ifndef CONSTANTS_H
#define CONSTANTS_H

// Standard Includes
#include <string>

// 3rd Party Includes
#include <json.hpp>

// Our Includes


const std::string CLI_PARSER_NAME = "Basic Crow Web App";
const std::string URL_BASE = "http://localhost:";
const std::string PORT_FLAG_NAME = "port";
const std::string PRINT_FLAG_NAME = "print-sites";
const int DEFAULT_PORT = 8080;

// url consts 
// (have to define urls this way due to implementation of CROW_ROUTE - https://github.com/ipkn/crow/issues/281)
const std::string MAIN_PAGE = "main-page";
const std::string TEST_PAGE = "test-page";
const nlohmann::json SITE_URLS = {
    {MAIN_PAGE, "/"},
    {TEST_PAGE, "/test"}
};

#endif
