#include <bits/stdc++.h>
using namespace std; 
using ll=long long int;
#define big_no 1e9

class Segment { 
    vector <ll> arr, tree; 
    ll size_of_array;

    public: 

    Segment ( int size ) { 
        size_of_array = size; 
        arr.resize ( size); 
        tree.resize ( 4* size); 

        for ( ll i=0; i<size_of_array; i++ ) { 
            cin >> arr[i];
        }

        for ( ll i=0; i<4*size_of_array; i++ ) { 
            tree [i] = big_no; 
        }

        buildTree ( 0, size_of_array, 1 );
        
        /* 
        std::cout << "Our tree : " << std::endl;
        for ( auto i: tree ) { 
            std::cout << i << " "; 
        }std::cout << std::endl;
        */
    }

    void buildTree ( ll start, ll end, ll tree_node ) { 

        //baseCase
        if ( start == end ) { 
            tree [tree_node] = arr[start];
            return;
        }

        ll mid = ( start + end ) / 2; 
        buildTree ( start, mid, 2*tree_node );
        buildTree ( mid+1, end, 2*tree_node + 1 ); 

        tree [tree_node] = min (tree[2*tree_node], tree [2*tree_node+1] ); 
    }

    ll Query ( ll start, ll end, ll tree_node, ll left, ll right ) {

        //Base Case 

        if ( start > right or end < left ) return big_no;
        if ( start >= left and end <= right ) return tree [ tree_node]; 

        ll mid = ( start + end ) / 2; 

        return min ( Query ( start, mid, 2*tree_node, left, right ), 
                Query ( mid+1, end, 2*tree_node + 1, left, right) );
    }
};


int main ( ) { 
    ll n, queries; 
    std::cin >> n >> queries; 

    Segment s ( n ); 
    while ( queries -- ) { 
        ll left, right; 
        std::cin >> left >> right; 

        std::cout << s.Query ( 0, n, 1, left -1, right-1 ) << std::endl;
    }
}
