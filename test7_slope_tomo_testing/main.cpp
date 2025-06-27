#include <iostream>
#include<fstream>

double creat_c_model(int nz, int nx)
{

    return 0.0f;
}

std::pair<int, int> reading_c_dim(std::string file_location)
{
    int nz, nx;
    std::ifstream shape_file(file_location);
    shape_file >> nz >>nx;
    return {nz, nx};
}

int main(int argc, char* argv[]){
    std::cout<< "#####################################################################"<<std::endl;
    std::cout<< "This is the main function for eikonal function based slope tomography"<<std::endl;
    std::cout<< "#####################################################################"<<std::endl;
    std::cout<< "this is the number of the inputs: " << argc << std::endl;
    std::string  c_file_location = argv[1];


    auto [nz, nx] = reading_c_dim(c_file_location);
    std::cout<< "This is the shape of the c file dim" << nz << " and " << nx<< std::endl;
    return 0;
}