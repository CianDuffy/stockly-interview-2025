#include "EanValidator.hpp"
#include <iostream>


int main() {
    // read input from stdin

    // parse EANs from CSV into std::vector<std::string>

    EanValidator validator;

    std::vector<std::string> input = {"12345678", " v "};
    EanValidationResult result = validator.validateEans(input);

    std::cout << result.valid << " " << result.invalid << std::endl;
}
