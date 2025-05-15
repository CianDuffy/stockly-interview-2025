#include "EanValidator.hpp"
#include <iostream>


int main() {
    // read input from stdin

    // parse EANs from CSV into std::vector<std::string>

    EanValidator validator;

    std::vector<std::string> input = {"3666239062713", "3666239062714", "6291041500213"};
    EanValidationResult result = validator.validateEans(input);

    std::cout << result.valid << " " << result.invalid << std::endl;
}
