// Our Includes
#include "CLI_Parser.h"

// local namespace modifications
using std::cout;
using std::cerr;
using std::endl;

CLI_Parser::CLI_Parser() {
    // empty for now
}

nlohmann::json CLI_Parser::parse_flags(int argc, char* argv[], std::string parser_name) const {
    CLI::App parser(parser_name);

    nlohmann::json flag_results;

    /* =============================================== create flags =============================================== */
    parser.add_option("-p,--port", flag_results[PORT_FLAG_NAME])
        ->description("Set the port to open the web app on")
        ->check(CLI::Range(1024, 65535), "Must select a valid port in the range")
        ->default_val(DEFAULT_PORT);

    bool dont_print_sites; // false if flag used
    parser.add_flag("-b,--bool", dont_print_sites)
        ->description("Don't print out generated sites urls")
        ->default_val(false);

    /* ============================================ actually parse flags =========================================== */
    try {
        parser.parse(argc, argv);
    } catch  (const CLI::ParseError &e) {
        parser.exit(e); // handles printing of error messages
        exit(EXIT_FAILURE);
    }

    flag_results[PRINT_FLAG_NAME] = !dont_print_sites;

    // return results
    return flag_results;
}
