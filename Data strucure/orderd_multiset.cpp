#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class t> using ordered_multiset= tree<t, null_type,less_equal<t>
        , rb_tree_tag,tree_order_statistics_node_update>;
template<class t>
void myerase(ordered_multiset<t> &o_set, t v){
int rank = o_set.order_of_key(v);
auto it = o_set.find_by_order(rank);
o_set.erase(it);
}
