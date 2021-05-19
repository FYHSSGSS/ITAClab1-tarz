#include <iostream>
#include "huffman.h"
#include "lz78.h"
//#include <boost/program_options.hpp>
//
//namespace bpo = boost::program_options;
//
char target[110], destination[110];
//std::string target, destination;
//int type;

int main(int argc, char const *argv[]) {
    scanf("%s%s",target, destination);
    lz78::encode(target, destination, 0);
    /*std::vector<std::string> addr;
    bpo::options_description opt("all options");
    opt.add_options()
            //指定该参数的默认值
            // "apple,a" : 指定选项的全写形式为 --apple, 简写形式为 -a
            //value<type>(ptr) : ptr为该选项对应的外部变量的地址, 当该选项被解析后,
            //可通过下面的notify()函数将选项的值赋给该外部变量,该变量的值会自动更新
            //defaut_value(num) : num为该选项的默认值, 若命令行中未输入该选项, 则该选项的值取为num
            ("gaf,g", bpo::value<std::vector<std::string> >()->multitoken(),"使用哈夫曼编码压缩(1)/解压(0) 输入的文件路径 输出的文件路径")
            ("lz78,l", bpo::value<std::vector<std::string> >()->multitoken(),"使用LZ78编码压缩(1)/解压(0) 输入的文件路径 输出的文件路径")
            //该参数的实际类型为vector,所以命令行中输入的值可以是多个,
            //multitoken()的作用就是告诉编译器,该选项可接受多个值
            ("help,h", "对输入文件进行huffman或者LZ78编码的压缩/ 解压操作");
    bpo::variables_map vm;

    try{
        bpo::store(parse_command_line(argc, argv, opt), vm);
    }
    catch(...){
        std::cout << "输入的参数中存在未定义的选项！\n";
        return 0;
    }
    bpo::notify(vm);

    if(vm.count("help") ){
        std::cout << opt << std::endl;
        return 0;
    }
    if(vm.count("gaf") ){
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
        char* fin = new char[strlen(target.c_str())+1];
        strcpy(fin, target.c_str());
        char* fout = new char[strlen(destination.c_str())+1];
        strcpy(fout, destination.c_str());
        huffman::encode(fin, fout, type);
    }
    if(vm.count("lz78") ){
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
        char* fin = new char[strlen(target.c_str())+1];
        strcpy(fin, target.c_str());
        char* fout = new char[strlen(destination.c_str())+1];
        strcpy(fout, destination.c_str());
        lz78::encode(fin, fout, type);
    }*/
    std::cout << "Bye!" << std::endl;
    return 0;
}
