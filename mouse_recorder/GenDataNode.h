#pragma once

template <class T>
class GenDataNode
{
	T pData;
	GenDataNode<T>* pNextNode;

	public:
		// Constructor
		GenDataNode(T data)
		{
			setData(data);
			pNextNode = NULL;
		}

		~GenDataNode(){}

		// Mutators
		T getData(){
			return pData;
		}

		GenDataNode<T>* getNextNode(){
			return pNextNode;
		}

		void setData(T data){
			pData = data;
		}

		void setNextNode(GenDataNode* nextNode){
			pNextNode = nextNode;
		}
};

