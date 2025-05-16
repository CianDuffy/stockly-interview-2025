#include "EanValidator.hpp"
#include <iostream>



int main() {
    // read input from stdin

    // 4065418448246,84.01666666666668,0,adidas,Noir
    // 4065418448344,84.01666666666668,0,adidas,Noir
    // 4065418452151,84.01666666666668,0,adidas,Blanc
    // 4065418452229,84.01666666666668,0,adidas,Blanc
    // 4065418452090,84.01666666666668,0,adidas,Blanc
    // 4065418452120,84.01666666666668,0,adidas,Blanc
    // 4065418452083,84.01666666666668,0,adidas,Blanc
    // 4065418452243,84.01666666666668,0,adidas,Blanc
    // 4065419392044,82.00000000000001,0,adidas,Blanc
    // 3666239062713,94.50000000000001,2,caval,Beige

    // parse EANs from CSV into std::vector<std::string>
    

    EanValidator validator;

    std::vector<std::string> input = {"4065418448246", "4065418448344", "4065418452151", "4065418452229", "4065418452090", "4065418452120", "4065418452083", "4065418452243", "4065419392044", "3666239062713"};
    EanValidationResult result = validator.validateEans(input);

    std::cout << result.valid << " " << result.invalid << std::endl;
}
