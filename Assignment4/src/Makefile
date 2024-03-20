webstore:main
	g++ main.o SecondaryNode.o PrimaryNode.o AVLTree.o ReadFile.o  Webstore.o BinarySearchTree.o RedBlackTree.o -o webstore
main:AVLTree
	g++ -std=c++11 -c main.cpp -o main.o
AVLTree:BinarySearchTree
	g++ -std=c++11 -c AVLTree.cpp -o AVLTree.o
BinarySearchTree:RedBlackTree
	g++ -std=c++11 -c BinarySearchTree.cpp -o BinarySearchTree.o
RedBlackTree:PrimaryNode
	g++ -std=c++11 -c RedBlackTree.cpp -o RedBlackTree.o
PrimaryNode:Webstore
	g++ -std=c++11 -c PrimaryNode.cpp -o PrimaryNode.o
Webstore:ReadFile
	g++ -std=c++11 -c Webstore.cpp -o Webstore.o
ReadFile:SecondaryNode
	g++ -std=c++11 -c ReadFile.cpp -o ReadFile.o
SecondaryNode:
	g++ -std=c++11 -c SecondaryNode.cpp -o SecondaryNode.o 

