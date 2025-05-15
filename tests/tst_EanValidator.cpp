#include "gtest/gtest.h"

#include "EanValidator.hpp"

TEST(EanValidationTest, basic)
{
    EanValidator validator;
    
    std::vector<std::string> input = {" a ", " v "};
    EanValidationResult result = validator.validateEans(input);

    EXPECT_EQ(2, result.valid);
    EXPECT_EQ(0, result.invalid);
}
