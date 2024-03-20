Assignment3:main
	g++ main.o HUCoffeeShop.o Node.o Queue.o Check.o Employee.o ReadFile.o Customer.o Cashier.o Barista.o -o Assignment3
main:HUCoffeeShop
	g++ -std=c++11 -c main.cpp -o main.o
HUCoffeeShop:Check
	g++ -std=c++11 -c HUCoffeeShop.cpp -o HUCoffeeShop.o
Check:Employee
	g++ -std=c++11 -c Check.cpp -o Check.o
Employee:ReadFile
	g++ -std=c++11 -c Employee.cpp -o Employee.o
ReadFile:Customer
	g++ -std=c++11 -c ReadFile.cpp -o ReadFile.o
Customer:Cashier
	g++ -std=c++11 -c Customer.cpp -o Customer.o
Cashier:Barista
	g++ -std=c++11 -c Cashier.cpp -o Cashier.o
Barista:Queue
	g++ -std=c++11 -c Barista.cpp -o Barista.o
Queue:Node
	g++ -std=c++11 -c Queue.cpp -o Queue.o
Node:
	g++ -std=c++11 -c Node.cpp -o Node.o 
