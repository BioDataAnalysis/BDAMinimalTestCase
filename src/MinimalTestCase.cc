
#include <boost/program_options.hpp>

#include <iostream>
#include <string>

void ParseCommandLineArguments(boost::program_options::variables_map& aOptionsMap,
                               const int argc, char** const argv)
{
    // Declare command line options.
    boost::program_options::options_description vCMDLineDescription("Allowed options");
    vCMDLineDescription.add_options()
    ("help,h", "this help message")
    ("server,s", boost::program_options::value<std::string>()->default_value("localhost"), "the server url")
    ("insecure-port,q", boost::program_options::value<int>()->default_value(50050), "the server insecure port")
    ("secure-port,p", boost::program_options::value<int>()->default_value(50051), "the server secure port")
    ("username,u", boost::program_options::value<std::string>(), "the username for log in")
    ("password,p", boost::program_options::value<std::string>(), "the password for log in")
    ("sessionid,s", boost::program_options::value<std::string>(), "the server API session ID for log in")
    ("tokenfile,t", boost::program_options::value<std::string>(), "the server API session ID file for log in")
    ("shutdown", "send a shutdown request to the server");

    boost::program_options::store(boost::program_options::parse_command_line(argc, argv, vCMDLineDescription), aOptionsMap);
    boost::program_options::notify(aOptionsMap);

    if (aOptionsMap.count("help")) {
        std::cout << vCMDLineDescription;
        std::exit(0);
    }
}

int main(int argc, char** argv) {
    boost::program_options::variables_map vOptionsMap;
    ParseCommandLineArguments(vOptionsMap, argc, argv);

    return 0;
}
