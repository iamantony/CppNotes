#ifndef PRIMALNUMBERS_H_
#define PRIMALNUMBERS_H_

#include <vector>

class PrimeNumbers
{
    // == METHODS ==
public:
    static std::vector<long unsigned int> GetPrimeNumbers(
                    const long unsigned int &t_limit);
};

#endif /* PRIMALNUMBERS_H_ */
