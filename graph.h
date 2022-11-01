// file: graph.h
// author: Aidan Collins
// github: aijac0
// email: aidancollinscs@gmail.com
// // // // // // // // // // // //

#include <vector>


template <typename E>
class Graph<E>
{
	public:

		/**
		 * Default constructor for Graph
		 * Initializes nodes vector with size 0
		 * @return: Graph object
		 */
		Graph();	
	
		/**
		 * Constructor for Graph
		 * Initializes nodes vector with specified size
		 * @param init_size: Initial size of nodes vector
		 * @return: Graph object
		 */
		Graph(size_t init_size);
	    
		/**
		 * Add an adjacency vector to the nodes vector
		 * Initializes adjacency vector with size 0
		 */
		void add_node();

		/**
		 * Add an adjacency vector to the nodes vector
		 * Initializes adjacency vector with size 0
		 * @param init_size: Initial size of adjacency vector
		 */
		void add_node(size_t init_size);

		/** 
		 * Add v to an adjacency vector in the nodes vector
		 * @param node_id: Index in nodes vector of the adjacency vector
		 * @param v: Value to add to the adjacency vector
		 */
		void add_adjacent(size_t node_id, E v);

		/**
		 * Output string representation of graph using <<
		 * @param os: Instance of ostream
		 * @param G: Graph to output
		 */
		friend ostream& operator<<(ostream& os, const Graph& G);

	private:

		// Attributes
		Vector<Vector<E>> nodes;

		// Disable copy constructor
		Graph(const Graph & Rhs);
};
