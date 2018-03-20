#include "bin.hh"

int main(){
    std::cout << "Binary Runner\n";

    for(int i = 0; i < 10; i++){
        Gen.push_back(uni(rng));
        std::cout << "int: " <<Gen[i] << " and in binary: " << toBinary(Gen[i]) << std::endl;
    }
    
    std::cout << "\n\n";
    
    std::string DecStore, token;
    for(int i = 0; i < 10; i++){ 
        DecStore = std::to_string(unid(rng));
        std::cout << DecStore << std::endl;
        while(token != DecStore){
            token = DecStore.substr(0,DecStore.find_first_of("."));
            DecStore = DecStore.substr(DecStore.find_first_of(".") + 1);
            printf("%s ",token.c_str());
            std::cout << "Split for binary conversion" << std::endl;
        }
        std::cout << std::endl;
    }
    return 0;
}
