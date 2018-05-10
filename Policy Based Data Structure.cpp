/*
        Policy Based Data Structure
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using namespace __gnu_pbds;

template <typename T> using 	Set = tree<T, null_type,
				less<T>, rb_tree_tag,
				tree_order_statistics_node_update>;

Set <int> st;

int main() {
#ifdef Mr_Emrul
	freopen("inputf.in", "r", stdin);
#endif ///Mr_Emrul

	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	
	st.insert( 5 ); //Insert
	st.erase( 5 ); //Delete
	st.insert( 1 );
	st.insert( 2 );
	st.insert( 9 );
	cout << *st.find_by_order( 0 ) << endl; //Find value by rank
	cout << st.order_of_key( 9 ) << endl; //Find value's rank

	/* For multiple same element, use pair, store index in second of pair */
	return 0;
}
