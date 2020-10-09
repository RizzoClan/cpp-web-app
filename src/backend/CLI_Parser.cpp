// Our Includes
#include "CLI_Parser.h"

CLI_Parser::CLI_Parser() {
    // empty for now
}

nlohmann::json CLI_Parser::parse_flags(int argc, char* argv[], std::string parser_name) const {
    CLI::App cli_parser(parser_name);

    nlohmann::json flag_results;

    // create flags
    int port = 8080;
    // cli_parser.add_option("-p,--port", flag_results["port"], "Set the port to open the web app on")
    cli_parser.add_option("-p,--port", flag_results["port"], "Set the port to open the web app on")
        ->check(CLI::Range(1024, 65535), "Must select a valid port in the range")
        ->default_val(8080);

    // actually parse flags
    cli_parser.parse(argc, argv);
    // CLI11_PARSE(cli_parser, argc, argv); // cant use this due to throwing errors outside of int main()

    // return results
    return flag_results;
}
