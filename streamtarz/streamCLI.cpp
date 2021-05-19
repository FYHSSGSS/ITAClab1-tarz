#include <iostream>
#include "huffman.h"
#include "lz78.h"
#include <boost/program_options.hpp>

namespace bpo = boost::program_options;

int type;

int main(int argc, char const *argv[]) {
    std::vector<std::string> addr;
    bpo::options_description opt("all options");
    opt.add_options()
            ("gaf,g", bpo::value<int>(&type),"Use Huffman encoding to compress (1)/ decompress (0)")
            ("lz78,l", bpo::value<int>(&type),"Use LZ78 encoding to compress (1)/ decompress (0)")
            ("help,h", " ");
    bpo::variables_map vm;

    try{
        bpo::store(parse_command_line(argc, argv, opt), vm);
    }
    catch(...){
        std::cout << "An undefined option exists in the input parameter!\n";
        return 0;
    }
    bpo::notify(vm);

    if(vm.count("help") ){
        std::cout << opt << std::endl;
        return 0;
    }
    if(vm.count("gaf") )huffman::encode(type);
    if(vm.count("lz78") )lz78::encode(type);
    return 0;
}
