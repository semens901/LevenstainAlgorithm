#include <iostream>
#include<cassert>
#include<vector>
#include<numeric>
#include<memory>

template<typename T>
typename T::size_type LevenshteinDistanceMemory(const T &source,
                                          const T &target) {
    if (source.size() > target.size()) {
        return LevenshteinDistanceMemory(target, source);
    }

    using TSizeType = typename T::size_type;
    const std::unique_ptr<TSizeType> min_size(new TSizeType(source.size())), max_size(new TSizeType(target.size()));
    std::unique_ptr<std::vector<TSizeType>> lev_dist(new std::vector<TSizeType>(*min_size.get() + 1));

    std::iota(lev_dist.get()->begin(), lev_dist.get()->end(), 0);

    for (TSizeType j = 1; j <= *max_size.get(); ++j) {
        TSizeType previous_diagonal = (*lev_dist.get())[0], previous_diagonal_save;
        ++(*lev_dist.get())[0];

        for (TSizeType i = 1; i <= *min_size.get(); ++i) {
            previous_diagonal_save = (*lev_dist.get())[i];
            if (source[i - 1] == target[j - 1]) {
                (*lev_dist.get())[i] = previous_diagonal;
            } else {
                (*lev_dist.get())[i] = std::min(std::min((*lev_dist.get())[i - 1], (*lev_dist.get())[i]), previous_diagonal) + 1;
            }
            previous_diagonal = previous_diagonal_save;
        }
    }

    return (*lev_dist.get())[*min_size.get()];
}

void test_func()
{
    assert(LevenshteinDistanceMemory<std::string>("ARMA", "ALKATRAS") == 6);
    assert(LevenshteinDistanceMemory<std::string>("b", "") == 1);
    assert(LevenshteinDistanceMemory<std::string>("ammmmmmmooooooooogggggggggguuuuuuuuuussssssss", "kalahmatkadakldkqwdjqfjsdhjldhfqklfwfhlhfejkwrflwnfhkwejukoikjhefndwzs") == 66);
    assert(LevenshteinDistanceMemory<std::string>("biba", "boba") == 1);
    assert(LevenshteinDistanceMemory<std::string>("avstria", "avstralia") == 2);
    assert(LevenshteinDistanceMemory<std::string>("kotik", "skotina") == 3);
    std::cout << "Tests Success!\n";
}

int main()
{
    test_func();
    return 0;
}
