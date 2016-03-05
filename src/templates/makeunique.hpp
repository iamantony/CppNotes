#ifndef MAKEUNIQUE_HPP_
#define MAKEUNIQUE_HPP_

/* Failed to compile under g++ 4.9.3
#include <memory>
#include <type_traits>
#include <utility>
#include <string>

using namespace std;

template <typename T, typename... Args>
unique_ptr<T> make_unique_helper(false_type, Args&&... args)
{
    return unique_ptr<T> (new T(forward<Args>(args)... ));
}

template <typename T, typename... Args>
unique_ptr<T> make_unique_helper(true_type, Args&&... args)
{
    // Check that size of array is not 0
    static_assert(extent<T>::value == 0,
            "make_unique<T[N]> is forbidden, please use make_unique<T[]>");

    typedef typename remove_extent<T>::type U;
    return unique_ptr<T> (new U[sizeof...(Args)] (forward<Args>(args)... ) );
}

template <typename T, typename... Args>
unique_ptr<T> make_unique(Args&&...args)
{
    return make_unique_helper<T>(is_array<T>(), forward<Args>(args)...);
}

void StartMakeUnique()
{
    auto a = make_unique<int>();
    cout << *a << endl;

    auto s = make_unique<string>('x');
    cout << *s << endl;

    auto arr = make_unique<int[]>(11, 22, 33);
    cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
}
*/

#endif /* MAKEUNIQUE_HPP_ */
