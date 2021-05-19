#include <iostream>
#include "huffman.h"
#include "lz78.h"
#include <boost/program_options.hpp>

namespace bpo = boost::program_options;

//char* target, destination;
std::string target, destination;
int type;

int main(int argc, char const *argv[]) {
    std::vector<std::string> addr;
    bpo::options_description opt("all options");
    opt.add_options()
            ("gaf,g", bpo::value<std::vector<std::string> >()->multitoken(), " Use Huffman encoding to compress (1)/ decompress (0)   the input file path   the output file path")
            ("lz78,l", bpo::value<std::vector<std::string> >()->multitoken(), "Use LZ78 encoding to compress (1)/ decompress (0)   the input file path   the output file path")
            ("help,h", " ");
    bpo::variables_map vm;

    try {
        bpo::store(parse_command_line(argc, argv, opt), vm);
    }
    catch (...) {
        std::cout << "An undefined option exists in the input parameter!\n";
        return 0;
    }
    bpo::notify(vm);

    if (vm.count("help")) {
        std::cout << opt << std::endl;
        return 0;
    }
    if (vm.count("gaf")) {
        if (vm["gaf"].as<std::vector<std::string> >().size() != 3) {
            std::cout << "输入的参数列表不正确！\n";
            return 0;
        }
        std::string temp = vm["gaf"].as<std::vector<std::string> >()[0];
        if (temp.length() != 1 and (temp[0] != '0' or temp[1] != '1')) {
            std::cout << "输入的参数列表不正确！\n";
            return 0;
        }
        type = temp[0] - '0';
        target = vm["gaf"].as<std::vector<std::string> >()[1];
        destination = vm["gaf"].as<std::vector<std::string> >()[2];
        char *fin = new char[strlen(target.c_str()) + 1];
        strcpy(fin, target.c_str());
        char *fout = new char[strlen(destination.c_str()) + 1];
        strcpy(fout, destination.c_str());
        huffman::encode(fin, fout, type);
    }
    if (vm.count("lz78")) {
        if (vm["lz78"].as<std::vector<std::string> >().size() != 3) {
            std::cout << "输入的参数列表不正确！\n";
            return 0;
        }
        std::string temp = vm["lz78"].as<std::vector<std::string> >()[0];
        if (temp.length() != 1 and (temp[0] != '0' or temp[1] != '1')) {
            std::cout << "输入的参数列表不正确！\n";
            return 0;
        }
        type = temp[0] - '0';
        target = vm["lz78"].as<std::vector<std::string> >()[1];
        destination = vm["lz78"].as<std::vector<std::string> >()[2];
        char *fin = new char[strlen(target.c_str()) + 1];
        strcpy(fin, target.c_str());
        char *fout = new char[strlen(destination.c_str()) + 1];
        strcpy(fout, destination.c_str());
//        printf("type %d\n", type);
        lz78::encode(fin, fout, type);
    }
    std::cout << "Bye!" << std::endl;
    return 0;
}
