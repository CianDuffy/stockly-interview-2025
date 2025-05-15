#ifndef EAN_VALIDATOR_HPP
#define EAN_VALIDATOR_HPP

#include <string>
#include <vector>

struct EanValidationResult 
{
    int valid;
    int invalid;
};

class EanValidator
{
public:
    EanValidationResult validateEans(const std::vector<std::string> & eans);

private:
    bool validateEan(const std::string & ean) const;
    std::string padLeadingZeros(const std::string & ean) const;
    bool validateEanChecksum(const std::string & ean) const;
};

#endif
