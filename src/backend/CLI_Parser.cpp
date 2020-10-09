// Our Includes
#include "CLI_Parser.h"

CLI_Parser::CLI_Parser() {
    // empty for now
}

nlohmann::json CLI_Parser::parse_flags(int argc, char* argv[], std::string parser_name) const {
    CLI::App cli_parser(parser_name);

    nlohmann::json flag_results;

    /* =============================================== create flags =============================================== */
    cli_parser.add_option("-p,--port", flag_results[PORT_FLAG_NAME], "Set the port to open the web app on")
        ->check(CLI::Range(1024, 65535), "Must select a valid port in the range")
        ->default_val(DEFAULT_PORT);

    /* ============================================ actually parse flags =========================================== */
    cli_parser.parse(argc, argv);

    // return results
    return flag_results;
}
