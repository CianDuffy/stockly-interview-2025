#include "EanValidator.hpp"

#include <iostream>

static const int EAN_MIN_LENGTH = 8;
static const int EAN_REQUIRED_LENGTH = 13;

EanValidationResult EanValidator::validateEans(const std::vector<std::string> & eans)
{
    int validCount = 0;
    int invalidCount = 0;

    for (const auto & ean : eans) {
        if (validateEan(ean))
            validCount++;
        else
            invalidCount++;
    }

    return {
        .valid = validCount,
        .invalid = invalidCount,
    };
}

bool EanValidator::validateEan(const std::string& ean) const
{
    if (ean.length() < EAN_MIN_LENGTH || ean.length() > EAN_REQUIRED_LENGTH)
        return false;

    // pad leading zeros if required
    std::string paddedEan = padLeadingZeros(ean);

    std::cout << "Padded string: " << paddedEan << std::endl;

    // Validate checksum
    
    return true;
}

std::string EanValidator::padLeadingZeros(const std::string & ean) const
{
    if (ean.length() == EAN_REQUIRED_LENGTH)
        return ean;

    int requireZeros = EAN_REQUIRED_LENGTH - ean.length();

    std::string paddingZeros(requireZeros, '0');

    return paddingZeros + ean;
}

bool EanValidator::validateEanChecksum(const std::string & ean) const
{

}


