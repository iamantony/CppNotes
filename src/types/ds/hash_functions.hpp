#ifndef HASH_FUNCTIONS_HPP
#define HASH_FUNCTIONS_HPP

#include <cmath>
#include <random>

// Comparison of hashes:
// https://softwareengineering.stackexchange.com/questions/49550/which-hashing-algorithm-is-best-for-uniqueness-and-speed

namespace Types::DS {

    /* Hash function that uses division method
     * m - number of buckets
     * Some values of m are better than others. For instance, you don’t want to choose a power
     * of 2, because then h(k) is just the lowest-order bits of k, and generally not all low-order
     * bit patterns are equally likely (i.e. if most of the keys have same k lowe-order bits, they
     * all would be put in the same bucket). Also you should not choose even number for the m. If
     * most of the keys would be even numbers, they would be put to buckets with even indexes and
     * buckets with odd indexes would contain less elements.
     * Often you want to choose a prime number that is not too close to an exact power of 2.
     */
    class HashModulo {
        const size_t m;

    public:
        explicit HashModulo(const size_t num_of_buckets) : m(num_of_buckets) {}
        size_t operator()(size_t key) { return key % m; }
        size_t operator()(int32_t key) { return static_cast<size_t>(std::abs(key)) % m; }
    };

    /* 1. Multiply the key k by some number 0 < A < 1.
     * 2. Extract the fractional part of kA.
     * 3. Multiply it by m.
     * 4. Take the floor of the results.
     * In other words, let h(k) = [m(kA mod 1)].
     * Here the value of m is not critical, but some values of A work better than others. Knuth
     * suggests that A = (√5 − 1)/2 is likely to work reasonably well.
     */
    class HashMultiplication {
        double A;
        double m;

    public:
        explicit HashMultiplication(const size_t num_of_buckets) {
            A = (sqrt(5.0) - 1.0) / 2.0;
            m = static_cast<double>(num_of_buckets);
        }

        size_t operator()(size_t key){
            double key_d = static_cast<double>(key);
            return static_cast<size_t>(fmod(key_d * A, 1.0) * m);
        }
    };

    /* https://en.wikipedia.org/wiki/Universal_hashing#Avoiding_modular_arithmetic
     * The state of the art for hashing integers is the multiply-shift scheme described by
     * Dietzfelbinger et al. in 1997. By avoiding modular arithmetic, this method is much easier
     * to implement and also runs significantly faster in practice (usually by at least a factor
     * of four). The scheme assumes the number of bins is a power of two, m=2^M. Let w be the
     * number of bits in a machine word. Then the hash functions are parametrised over odd positive
     * integer a < 2^w (that fit in a word of w bits). To evaluate ha(x), multiply x by a
     * modulo 2^w and then keep the high order M bits as the hash code. In mathematical notation,
     * this is: ha(x) = (a*x mod 2^w) / 2^(w-M) == (a*x mod 2^w) >> (w-M)
     */
    namespace helpers {
        template <typename T>
        bool is_power_of_2(T num) {
            return num > 0 && ((num & (num - 1)) == 0);
        }

        inline size_t get_power(size_t num) {
            size_t power = 0;
            while (num != 0) {
                ++power;
                num /= 2;
            }

            --power;
            return power;
        }

        class RandomGenerator {
            std::mt19937 m_mt;
            std::uniform_int_distribution<uint64_t> m_dist;

            uint64_t generate_random_num(const bool even, const bool odd) {
                while (true) {
                    auto num = m_dist(m_mt);
                    if (is_power_of_2(num)) { continue; }
                    if ((even && num % 2 == 0) ||
                        (odd && num % 2 == 1) ||
                        (even == odd))
                    {
                        return num;
                    }
                }
            }

        public:
            explicit RandomGenerator(const size_t word_size) {
                m_mt.seed(7893);
                const auto max_num = static_cast<uint64_t>(std::pow(2, word_size)) - 1;
                m_dist = std::uniform_int_distribution<uint64_t>(0, max_num);
            }

            RandomGenerator(size_t min, size_t max) {
                m_mt.seed(7893);
                m_dist = std::uniform_int_distribution<uint64_t>(min, max);
            }

            uint64_t generate() { return generate_random_num(true, true); }
            uint64_t generate_even() { return generate_random_num(true, false); }
            uint64_t generate_odd() { return generate_random_num(false, true); }
        };
    }

    class HashMultiplyShift {
        const uint64_t m_word_size = sizeof(int32_t) * 8; // w
        uint64_t m_modulo = 0;
        uint64_t m_M = 0;
        uint64_t m_a = 0;

    public:
        explicit HashMultiplyShift(const size_t num_of_buckets) {
            auto max_num_of_buckets = static_cast<size_t>(std::pow(2, m_word_size - 1));
            if (num_of_buckets > max_num_of_buckets) {
                throw std::runtime_error("Number of buckets is too huge");
            }

            if (!helpers::is_power_of_2(num_of_buckets)) {
                throw std::runtime_error("Number of buckets is not 2^x");
            }

            m_modulo = static_cast<size_t>(std::pow(2, m_word_size));
            m_M = helpers::get_power(num_of_buckets);

            helpers::RandomGenerator g(m_word_size);
            m_a = g.generate_odd();
        }

        uint64_t operator()(int32_t key) const {
            const auto key_64 = static_cast<uint64_t>(key);
            return ((key_64 * m_a) % m_modulo) >> (m_word_size - m_M);
        }
    };

    class HashMultiplyAddShift {
        const uint64_t m_word_size = sizeof(int32_t) * 8; // w
        uint64_t m_modulo = 0;
        uint64_t m_M = 0;
        uint64_t m_a = 0;
        uint64_t m_b = 0;

    public:
        explicit HashMultiplyAddShift(const size_t num_of_buckets) {
            auto max_num_of_buckets = static_cast<size_t>(std::pow(2, m_word_size - 1));
            if (num_of_buckets > max_num_of_buckets) {
                throw std::runtime_error("Number of buckets is too huge");
            }

            if (!helpers::is_power_of_2(num_of_buckets)) {
                throw std::runtime_error("Number of buckets is not 2^x");
            }

            m_modulo = static_cast<size_t>(std::pow(2, m_word_size));
            m_M = helpers::get_power(num_of_buckets);

            helpers::RandomGenerator g(m_word_size);
            m_a = g.generate_odd();
            m_b = g.generate();
        }

        size_t operator()(int32_t key) const {
            const auto key_64 = static_cast<size_t>(key);
            return ((key_64 * m_a + m_b) % m_modulo) >> (m_word_size - m_M);
        }
    };

    class HashVector {
        const uint64_t m_word_size = sizeof(int32_t) * 8; // w
        uint64_t m_modulo = 0;
        uint64_t m_M = 0;

    public:
        explicit HashVector(const size_t num_of_buckets) {
            auto max_num_of_buckets = static_cast<size_t>(std::pow(2, m_word_size - 1));
            if (num_of_buckets > max_num_of_buckets) {
                throw std::runtime_error("Number of buckets is too huge");
            }

            if (!helpers::is_power_of_2(num_of_buckets)) {
                throw std::runtime_error("Number of buckets is not 2^x");
            }

            m_modulo = static_cast<uint64_t>(std::pow(2, m_word_size));
            m_M = helpers::get_power(num_of_buckets);
        }

        uint64_t operator()(const std::vector<int32_t>& v) const {
            if (v.empty()) { return 0; }

            std::vector<uint64_t> random_a(v.size(), 0);

            helpers::RandomGenerator g(m_word_size);
            std::generate(random_a.begin(), random_a.end(), [&g](){ return g.generate_odd(); });

            uint64_t sum = 0;
            for (size_t i = 0; i < v.size(); ++i) {
                sum += static_cast<uint64_t>(v[i]) * random_a[i];
            }

            return (sum % m_modulo) >> (m_word_size - m_M);
        }
    };

    /* Based on:
     * https://stackoverflow.com/questions/7666509/hash-function-for-string
     * http://www.cse.yorku.ca/~oz/hash.html
     * GCC uses MurmurHash2:
     * https://sites.google.com/site/murmurhash/
     * https://github.com/gcc-mirror/gcc/blob/master/libstdc++-v3/libsupc++/hash_bytes.cc
     */
    template <typename T>
    class HashString {
        uint64_t m_num_of_buckets = 1;

    public:
        explicit HashString(const size_t num_of_buckets) {
            if (num_of_buckets == 0) {
                throw std::runtime_error("Invalid number of buckets");
            }

            m_num_of_buckets = num_of_buckets;
        }

        uint64_t operator()(const std::basic_string<T>& s) const {
            if (s.empty()) { return 0; }

            uint64_t hash = 5381;
            for (const auto& c : s) {
                hash = ((hash << 5) + hash) + static_cast<uint64_t>(c); /* hash * 33 + c */
            }

            return hash % m_num_of_buckets;
        }
    };
}

#endif //HASH_FUNCTIONS_HPP
