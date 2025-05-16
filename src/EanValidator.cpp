#include "EanValidator.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

static const int EAN_MIN_LENGTH = 8;
static const int EAN_REQUIRED_LENGTH = 13;

static const std::unordered_map<int, int> checksumMultipliers {
    {0, 1},
    {1, 3},
    {2, 1},
    {3, 3},
    {4, 1},
    {5, 3},
    {6, 1},
    {7, 3},
    {8, 1},
    {9, 3},
    {10, 1},
    {11, 3}
};

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

    if (validateEanChecksum(paddedEan)) {
        std::cout << "Valid checksum: " << paddedEan << std::endl;
    }
    else {
        std::cout << "Invalid checksum: " << paddedEan << std::endl;
        return false;
    }
    
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
    int checkDigit = ean[ean.length() - 1] - '0';
    int sum = 0;

    for (int i = 0; i < ean.length() - 1; i++) {
        sum += (ean[i] - '0') * checksumMultipliers.at(i);
        std::cout << "Partial sum: " << sum << std::endl;
    }

    // Subtract sum from nearest equal or higher multiple of ten = check digit
    int nearestGreaterTen = (sum + 10) / 10;
    nearestGreaterTen *= 10;
    
    int calculatedChecksum = ((nearestGreaterTen - sum) + 10) % 10;

    std::cout << "nearestGreaterTen: " << nearestGreaterTen << "Checksum: " << calculatedChecksum << std::endl;



    return calculatedChecksum == checkDigit;
}


