#include <bits/stdc++.h>
using namespace std; 
using ll=long long int; 

//Segment Trees implementation
class Segment { 
    vector <ll > tree, arr; 
    ll N;
    public: 

    Segment ( ll n ) { 
        arr.resize ( n ), tree.resize ( 4*n ); 
        N = n;
    }

    template <typename t> 
        void print ( const t & v ) { 
            for ( auto i: v ) { 
                std::cout << i << " "; 
            }std::cout << std::endl;
        }

    void inputArray ( ) { 
        for ( ll i=0; i<N; i++ ) { 
            cin >> arr[i];
        }
        buildTree ( 0, N, 1 );
    }

    void buildTree ( ll start, ll end, ll tree_node ) { 
        if ( start == end ) { 
            tree[tree_node] = arr [start]; 
            return;
        }

        ll mid = ( start + end ) /2; 
        buildTree ( start, mid, 2*tree_node ); 
        buildTree ( mid+1, end, 2*tree_node + 1 ); 
        tree [ tree_node ] = tree [ 2*tree_node ] + tree [ 2*tree_node + 1]; 
    }

    void updateTree ( ll start, ll end, ll tree_node, ll index, ll value ) { 
        if ( start == end ) { 
            arr [index] = value; 
            tree [tree_node] = value; 
            return; 
        }

        ll mid = ( start + end ) / 2; 
        if ( index > mid ) { 
            updateTree ( mid +1, end, 2*tree_node + 1, index, value ); 
        }
        else { 
            updateTree ( start, mid, 2*tree_node, index, value );
        }

        tree [tree_node] = tree[2*tree_node] + tree [2*tree_node + 1 ]; 
    }

    ll Query ( ll start, ll end, ll tree_node, ll left, ll right ) { 
        if ( start > right or end < left ) return 0; 

        if ( start >= left and end <= right ) return tree[tree_node]; 

        ll mid = ( start + end ) / 2; 

        return Query ( start, mid, 2 * tree_node, left, right ) + Query ( mid+1, end, 2*tree_node + 1, left, right ); 
    }

    void printArray () { 
        print ( arr ); 
    }

    void printTree () { 
        print ( tree ); 
    }
};

int main () { 
    ll n, queries; 
    cin >> n >> queries;

    Segment s ( n ); 
    s.inputArray ( ); 

    for ( ll i=0; i<queries; i++ ) { 
        ll left, right; 
        std::cin >> left >> right;
        std::cout << s.Query ( 0, n, 1, left - 1, right - 1) << std::endl; // left, right are converted in 0-index array from 1-index array.
    }
}
