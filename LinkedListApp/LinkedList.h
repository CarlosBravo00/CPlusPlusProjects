#include "node.h"
template <class T>
class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		bool isEmpty();
		int getSize();
		void addFirst(T data);
		void addLast(T data);
		bool add(T data, int pos);
		void deleteFirst();
		void deleteLast();
		void del(int pos);
		int deleteAll();
		T set(T data, int pos);
		T get(int pos);
		bool change(int pos1, int pos2);
		void print();

	private:
		node<T> *head;
		int size;
};

template <class T>
LinkedList<T>::LinkedList(){
	head = nullptr;
	size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
	deleteAll();
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return (head == nullptr);
}

template <class T>
int LinkedList<T>::getSize(){
	return size;
}

template <class T>
void LinkedList<T>::addFirst(T data){
	head = new node<T>(data, head);
	size++;
}

template <class T>
void LinkedList<T>::addLast(T data){
	if (isEmpty()){
		addFirst(data);
	}
	else{
		node<T> *curr = head;
		while (curr->getNext() != nullptr){
			curr = curr->getNext();
		}
		curr->setNext(new node<T>(data));
		size++;
	}
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
	if (pos < 0 || pos > size){
		return false;
	}
	if (pos == 0){
		addFirst(data);
	}
	else if (pos == size){
		addLast(data);
	}
	else{
		node<T> *curr = head;
		for (int i=1; i<pos; i++){
			curr = curr->getNext();
		}
		curr->setNext(new node<T>(data, curr->getNext()));
		size++;
	}
	return true;
}

template <class T>
void LinkedList<T>::deleteFirst(){
	if (!isEmpty()){
		node<T> *curr = head;
		head = head->getNext();
		delete curr;
		size--;
	}
}

template <class T>
void LinkedList<T>::deleteLast(){
	if (size <= 1){
		deleteFirst();
	}
	else{
		node<T> *curr = head;
		while (curr->getNext()->getNext() != nullptr){
			curr = curr->getNext();
		}
		delete curr->getNext();
		curr->setNext(nullptr);
		size--;
	}
}

template <class T>
int LinkedList<T>::deleteAll(){
	node<T> *curr = head;
	while (head != nullptr){
		head = head->getNext();
		delete curr;
		curr = head;
	}
	int auxSize = size;
	size = 0;
	return auxSize;
}

template <class T>
void LinkedList<T>::del(int pos){
	if (pos == 0){
		deleteFirst();
	}
	else{
		node<T> *curr = head;
		for (int i=1; i<pos; i++){
			curr = curr->getNext();
		}
		node<T> *aux = curr->getNext();
		curr->setNext(aux->getNext());
		delete aux;
		size--;
	}
}

template <class T>
T LinkedList<T>::get(int pos){
	node<T> *curr = head;
	for (int i=1; i<=pos; i++){
		curr = curr->getNext();
	}
	return curr->getData();
}

template <class T>
T LinkedList<T>::set(T data, int pos){
	node<T> *curr = head;
	for (int i=1; i<=pos; i++){
		curr = curr->getNext();
	}
	T dataAux = curr->getData();
	curr->setData(data);
	return dataAux;
}

template <class T>
bool LinkedList<T>::change(int pos1, int pos2){
	if (pos1 < 0 || pos2 < 0 || pos1 >= size || pos2 >=size){
		return false;
	}
	if (pos1 == pos2){
		return true;
	}
	int posMen = (pos1 < pos2 ? pos1 : pos2);
	int posMay = (pos1 > pos2 ? pos1 : pos2);
	node<T> *curr1 = head;
	for (int i=1; i<=posMen; i++){
		curr1 = curr1->getNext();
	}
	node<T> *curr2 = curr1;
	for (int i=1; i<=(posMay-posMen); i++){
		curr2 = curr2->getNext();
	}
	T dataAux = curr1->getData();
	curr1->setData(curr2->getData());
	curr2->setData(dataAux);
	return true;
}

template <class T>
void LinkedList<T>::print(){
	node<T> *curr = head;
	while (curr != nullptr){
		cout << curr->getData()<< endl;
		curr = curr->getNext();
	}
}
