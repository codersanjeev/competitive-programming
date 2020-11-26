#include <bits/stdc++.h>
using namespace std;
using ll=long long int; 

class Segment { 
    vector <ll> arr, tree; 
    ll size_of_array; 
    public:

    Segment ( ll size ) {
        tree.resize ( 4*size ),  arr.resize ( size );
        size_of_array = size; 

        for ( ll i=0; i<size_of_array; i++ ) { 
            cin >> arr[i]; 
        }
        buildTree( 0, size_of_array, 1 ); 
    }

    void buildTree ( ll start, ll end, ll tree_node ) { 
        //base case
        if ( start == end ) { 
            tree [tree_node ] = arr [start];
            return; 
        }

        ll mid = ( start + end ) /2;
        buildTree ( start, mid, 2*tree_node ); 
        buildTree ( mid+1, end, 2*tree_node + 1 );

        tree [tree_node] = tree [2*tree_node] + tree [2*tree_node + 1];
    }

    void updateTree ( ll start, ll end, ll tree_node, ll index, ll value ) { 
        //Base case
        if ( start == end ) { 
            tree [tree_node] = value; 
            arr [index] = value; 
            return;
        }

        ll mid = ( start + end ) / 2; 
        if ( index > mid ) 
            updateTree ( mid+1, end, 2*tree_node + 1, index, value ); 
        else 
            updateTree ( start, mid, 2*tree_node, index, value ); 

        tree [tree_node] = tree [2*tree_node] + tree [2*tree_node + 1]; 
    }

    ll Query ( ll start, ll end, ll tree_node, ll left, ll right ) { 
        //base case 
        if ( start > right or end < left ) return 0;
        if ( start >= left and end <= right ) return tree[tree_node];

        ll mid = ( start + end ) /2; 

        return Query ( start, mid, 2*tree_node, left, right ) + 
            Query ( mid+1, end, 2*tree_node + 1, left, right ); 
    }

    template <typename t> void print ( const t & v ) { 
        for ( auto i: v ) { 
            std::cout << i << " "; 
        }std::cout << std::endl;
    }

    void print_tree ( ) { 
        print ( tree ); 
    }
    void print_array ( ) { 
        print ( arr ); 
    }
};

int main () { 
    ll n, queries; 
    std::cin >> n >> queries; 

    Segment s ( n );

    while ( queries -- ) { 
        ll main_no, left, right, index, value; 
        std::cin >> main_no;


        if ( main_no == 1 ) {
            std::cin >> index >> value;
            s.updateTree ( 0, n, 1, index-1 , value ); 
        }
        else if ( main_no == 2 ) { 
            std::cin >> left >> right; 
            std::cout << s.Query ( 0, n, 1, left -1, right -1 ) << std::endl; 
        }
    }
}
