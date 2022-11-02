#!/bin/bash

g++ -pedantic -Wall -Wextra graph.h -c graph.cpp
g++ -pedantic -Wall -Wextra graph.h -c lexical_graph.cpp
g++ graph.o lexical_graph.o -o lexical_graph
