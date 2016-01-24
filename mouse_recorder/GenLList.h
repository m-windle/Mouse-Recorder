#pragma once
#include "GenDataNode.h"

template <typename T>
class GenLList
{
	GenDataNode<T>* firstNode;
	GenDataNode<T>* currentNode;

	// Memory Management
	GenDataNode<T>* createNode(){
		GenDataNode<T>* newNode = (GenDataNode<T>*)malloc(sizeof(GenDataNode<T>));
		ZeroMemory(newNode, sizeof(GenDataNode<T>));

		return newNode;
	}

	void freeNode(GenDataNode<T>* node){
		free(node);
	}

	public:
		// Constructor
		GenLList(T data)
		{
			GenDataNode<T>* firstNode = createNode();
			firstNode->setData(data);

			setFirstNode(firstNode);
			setCurrentNode(firstNode);
		}

		~GenLList(){}

		// Mutators
		void setFirstNode(GenDataNode<T>* node){
			firstNode = node;
		}

		void setCurrentNode(GenDataNode<T>* node){
			currentNode = node;
		}

		GenDataNode<T>* getFirstNode(){
			return firstNode;
		}

		GenDataNode<T>* getCurrentNode(){
			return currentNode;
		}

		// Modifiers
		void addNewNode(T data){
			GenDataNode<T>* newNode = createNode();
			newNode->setData(data);

			GenDataNode<T>* current = getCurrentNode();
			current->setNextNode(newNode);

			setCurrentNode(newNode);
		}

		// Traversal
		GenDataNode<T>* getNextNode(){
			GenDataNode<T>* current = getCurrentNode();

			return current->getNextNode();
		}
};

