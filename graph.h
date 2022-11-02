// file: graph.h
// author: Aidan Collins
// github: aijac0
// email: aidancollinscs@gmail.com
// // // // // // // // // // // //

#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#include <vector>
#include <iostream>


template <typename E> class Graph;

template <typename E>
std::ostream& operator<<(std::ostream& os, const Graph<E>& G);


template <typename E>
class Graph
{
	public:

		/**
		 * Default constructor for Graph
		 * Initializes nodes vector with size 0
		 * @return: Graph object
		 */
		Graph<E>();	
	
		/**
		 * Constructor for Graph
		 * Initializes nodes vector with specified size
		 * @param init_size: Initial size of nodes vector
		 * @return: Graph object
		 */
		Graph<E>(size_t init_size);


		/**
		 * Destructor for Graph
		 */
		~Graph<E>();


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
		friend std::ostream& operator<< <E>(std::ostream& os, const Graph<E>& G);

	private:

		// Attributes
		std::vector< std::vector<E> *> nodes;

		// Disable copy constructor
		Graph(const Graph & Rhs);
};


template <typename E>
Graph<E>::Graph()
: nodes() {}

	
template <typename E>
Graph<E>::Graph(size_t init_size)
: nodes(init_size, nullptr)
{
	// Empty contents of nodes (while maintaining size)
	nodes.clear();
}


template <typename E>
Graph<E>::~Graph()
{
	for (std::vector<E> *vec : nodes)
	{
		delete vec;
	}
}
	    

template <typename E>
void Graph<E>::add_node()
{	
	// Create new adjacency vector
	std::vector<E> *vec = new std::vector<E>();
	// Add adj vector to nodes vector
	nodes.push_back(vec);
}


template <typename E>
void Graph<E>::add_node(size_t init_size)
{
	// Create new adjacency vector with specified init_size
	std::vector<E> *vec = new std::vector<E>(init_size);
	// Empty contents of adj vector (while maintaining size)
	vec->clear();
	// Add adj vector to nodes vector
	nodes.push_back(vec);
}


template <typename E>
void Graph<E>::add_adjacent(size_t node_id, E v)
{
	// Add v to adjacency vector in nodes vector
	nodes[node_id]->push_back(v);
}


template <typename E>
std::ostream& operator<<(std::ostream& os, const Graph<E>& G)
{
	// Iterate overe very adjacency vector in nodes vector
	for (std::vector<E> *vec : G.nodes)
	{
		os << "[ ";

		// Iterate over every v in adj vector
		for (E v: *vec)
		{
			os << v << ' ';
		}

		os << "] (" << vec->size() << '/' << vec->capacity() << ')' << std::endl;
	}

	os << '(' << G.nodes.size() << '/' << G.nodes.capacity() << ')' << std::endl;
	
	return os;
}


#endif
