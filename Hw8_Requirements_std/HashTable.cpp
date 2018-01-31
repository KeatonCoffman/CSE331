/****************************************************************
Keaton Coffman
CSE 331
Instructor Professor Onsay
Project 11
*****************************************************************/

#include <iostream>
#include "HashTable.h"


// Function: HashTable constructor
// Pre: Requires a table size
// Post: Allocates memory for an array and creates a Hashtable using that array
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(int initTableSize)
    : tableSize(initTableSize)
{
	tableSize = initTableSize;
	dataTable = new BSTree<DataType, KeyType>[initTableSize];
}


// Function: Copy Constructor
// Pre: A HashTable object has been initialized
// Post: Copies a HashTable object
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::HashTable(const HashTable& source) {
	this->tableSize = source.tableSize;
	dataTable = new BSTree<DataType, KeyType>[source.tableSize];
	for(int i=0;i<=source.tableSize;i++){
		dataTable[i] = source[i];
	}
	
}

// Function: Equals operator 
// Pre: A HashTable object has been initialized
// Post: Copies a HashTable object and takes all the properties of source
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>&
HashTable<DataType, KeyType>::operator=(const HashTable& source) {
    if (&source != this) {
	delete[] dataTable;
	copyTable(source);
    }
    return *this;
}

// Function: Copy the table "source"
// Pre: A HashTable object has been initialized
// Post: Calls copy constructor
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::copyTable(const HashTable& source) {
	*this(&source);
}

// Function: Destructor
// Pre: A HashTable object has been initialized
// Post: Deletes the array dataTable and frees memory
template <typename DataType, typename KeyType>
HashTable<DataType, KeyType>::~HashTable() {
	delete[] dataTable;
}

// Function: Inserts a data item into a BST in the array
// Pre: A HashTable object has been initialized
// Post: Gets the index of the correct BST and calls BST's insert
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::insert(const DataType& newDataItem) {
	int index = DataType::hash(newDataItem.getKey())%tableSize;
	dataTable[index].insert(newDataItem);
 }

// Function: Removes a data item from the BST in the array
// Pre: A HashTable object has been initialized
// Post: Gets index using hash and modulus by the tableSize. Removes an object from a BST.
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::remove(const KeyType& deleteKey) {
	int index = DataType::hash(deleteKey)%tableSize;
	return(dataTable[index].remove(deleteKey));
}

// Function: Retrieves a data item from a BST in the array
// Pre: A HashTable object has been initialized
// Post: Gets index using hash and modulus by the tableSize. retrieves an object in a BST.
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::retrieve(const KeyType& searchKey,DataType& returnItem) const{
	int index = (DataType::hash(searchKey))%this->tableSize;
	return(dataTable[index].retrieve(searchKey,returnItem));
}

// Function: Clears a BST in the array
// Pre: A HashTable object has been initialized
// Post: 
template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::clear() {
	for(int i=0;i<=this->tableSize;i++){
		dataTable[i].BSTree<DataType,KeyType>::clear();
	}
}

// Function: Checks to see if a BST in the array is empty
// Pre: A HashTable object has been initialized
// Post: Iterates throught the table and uses BST class of isEmpty function.
template <typename DataType, typename KeyType>
bool HashTable<DataType, KeyType>::isEmpty() const {
	for(int i=0;i<=tableSize;i++){
		if(!dataTable[i].isEmpty()){
			return false;
		}
	}
	return true;
}


template <typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const {
    for (int i = 0; i < tableSize; ++i) {
	cout << i << ": ";
	dataTable[i].writeKeys();
    }
};
