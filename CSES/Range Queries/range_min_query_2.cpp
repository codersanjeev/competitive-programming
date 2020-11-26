#include <bits/stdc++.h>
using namespace std; 
using ll=long long int; 
#define big_no 1e9 

class Segment { 
    vector <ll> arr, tree; 
    public: 

    Segment ( ll n ) { 
        tree.resize ( 4*n ); 
        arr.resize ( n ); 

        for ( ll i=0; i<n; i++ ) { 
            std::cin >> arr[i]; 
        }

        for ( ll i=0; i<4*n; i++ ) { 
            tree[i] = big_no; 
        }
        buildTree ( 0, n, 1 ); 
    }

    void buildTree ( ll start, ll end, ll tree_node ) {
        if ( start == end ) { 
            tree [ tree_node] = arr[start]; 
            return; 
        }

        ll mid = ( start + end ) / 2; 

        buildTree ( start, mid, 2*tree_node ); 
        buildTree ( mid+1, end, 2*tree_node + 1 ); 

        tree [tree_node] = min ( tree [2*tree_node], tree [2*tree_node +1 ] ); 
    }

    void updateTree ( ll start, ll end, ll tree_node, ll index, ll value ) { 
        if ( start == end ) { 
            tree [tree_node] = value;
            arr [index] = value; 
            return;
        }

        ll mid = ( start + end ) / 2; 

        if ( index > mid ) { 
            updateTree ( mid + 1, end, 2*tree_node + 1, index, value ); 
        }
        else { 
            updateTree ( start, mid, 2*tree_node, index, value ); 
        }

        tree [tree_node] = min ( tree [2*tree_node], tree [2*tree_node +1] );
    }

    ll Query ( ll start, ll end, ll tree_node, ll left, ll right ) { 

        if ( start > right or end < left ) return big_no; 
        if ( start >= left and end <= right ) return tree [tree_node]; 

        ll mid = ( start + end ) / 2; 
        return min ( Query ( start, mid, 2*tree_node, left, right ), 
                Query ( mid+1, end, 2*tree_node + 1, left, right ) ); 
    }

    template <typename t> inline void print ( const t & v  ) { 
        for ( auto i: v ) { 
            std::cout << i << " "; 
        }std::cout << endl;
    }
    void print_tree ( ) { 
        print ( tree ); 
    }

    void print_vector ( ) { 
        print ( arr ); 
    }
};

int main () {
    ll n, query; 
    cin >> n >> query; 

    Segment s ( n ); 

    while ( query -- ) { 
        //std::cout << "Printing tree : "; 
        //s.print_tree ( ); 
        //std::cout << "Printing arrays : "; 
        //s.print_vector ( );

        ll main_point, left, right, index, value; 
        cin >> main_point; 

        if ( main_point == 1 ) { 
            cin >> index >> value; 

            s.updateTree ( 0, n, 1, index -1, value ); 
        }
        else { 
            cin >> left >> right; 
            cout << s.Query ( 0, n, 1, left -1, right -1 ) << endl; 
        }
        
    }
}
