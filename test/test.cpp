#define BOOST_TEST_MODULE CppNotes test
#include <boost/test/unit_test.hpp>

#include "algorithms/math/test_add_two_numbers_as_linked_list.hpp"
#include "algorithms/math/test_basic_matrix_multiplication.hpp"
#include "algorithms/math/test_basic_numbers_multiplication.hpp"
#include "algorithms/math/test_is_number_power_of_two.hpp"
#include "algorithms/math/test_karatsuba_multiplication.hpp"
#include "algorithms/math/test_median_of_two_sorted_arrays.hpp"
#include "algorithms/math/test_strassen_matrix_multiplication.hpp"

#include "algorithms/search/test_binary_search.hpp"
#include "algorithms/search/test_find_two_elements.hpp"

#include "algorithms/sorting/test_bubble_sort.hpp"
#include "algorithms/sorting/test_gnome_sort.hpp"
#include "algorithms/sorting/test_selection_sort.hpp"
#include "algorithms/sorting/test_insertion_sort.hpp"
#include "algorithms/sorting/test_inversions_counter.hpp"
#include "algorithms/sorting/test_merge_sort.hpp"
#include "algorithms/sorting/test_quicksort.hpp"
#include "algorithms/sorting/test_quicksort_research.hpp"

#include "algorithms/strings/test_longest_palindrome.hpp"
#include "algorithms/strings/test_longest_substring.hpp"
#include "algorithms/strings/test_ransome_note.hpp"
#include "algorithms/strings/test_str_permutations.hpp"

#include "ctci5/data_structs/test_str_unique_char.hpp"
#include "ctci5/data_structs/test_str_reverse.hpp"
#include "ctci5/data_structs/test_is_str_permutation.hpp"
#include "ctci5/data_structs/test_str_replace_spaces.hpp"
#include "ctci5/data_structs/test_str_compression.hpp"
#include "ctci5/data_structs/test_rotate_matrix.hpp"
#include "ctci5/data_structs/test_matrix_zero_out.hpp"
#include "ctci5/data_structs/test_str_is_substring.hpp"
#include "ctci5/data_structs/test_remove_dup_linked_list.hpp"
#include "ctci5/data_structs/test_find_k_to_last_elem_in_sll.hpp"
#include "ctci5/data_structs/test_delete_node_from_sll.hpp"
#include "ctci5/data_structs/test_partition_linked_list.hpp"

#include "ctci5/additional/test_calc_angle_btw_clock_hands.hpp"

#include "ctci5/math/test_primes.hpp"
#include "ctci5/math/test_parallel_lines.hpp"
#include "ctci5/math/test_int_operators.hpp"

#include "ctci5/cpp/test_read_last_lines.hpp"

#include "types/test_binary_search_tree.hpp"
#include "types/test_binary_search_tree2.hpp"
#include "types/test_concurrent_map.hpp"
#include "types/test_linked_list.hpp"
#include "types/test_matrix.hpp"

BOOST_AUTO_TEST_CASE(test_func)
{
    BOOST_CHECK(true);
}
