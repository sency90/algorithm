#include "Heap.h"

//Constructor
template <class T, class Container, class Cmp>
Heap<T,Container,Cmp>::Heap():sz(0) {
	arr.clear();
	arr.resize(1);
}

//public functions
template <class T, class Container, class Cmp>
void Heap<T,Container,Cmp>::push(T x) {
	arr.push_back(x);
	up(++sz);
}

template <class T, class Container, class Cmp>
void Heap<T,Container,Cmp>::pop() {
	arr[1] = arr[sz--];
	down(1);
}

template <class T, class Container, class Cmp>
T Heap<T,Container,Cmp>::top() {
	if(sz<=0) exit(1); //error
	return arr[1];
}
template <class T, class Container, class Cmp>
bool Heap<T,Container,Cmp>::empty() { return sz<=0; }

template <class T, class Container, class Cmp>
int Heap<T,Container,Cmp>::size() { return sz; }

template <class T, class Container, class Cmp>
void Heap<T,Container,Cmp>::print() {
	for(int i=1; i<=sz; i++) {
		arr[i].print();
		printf(" ");
	}
}

//private functions
template <class T, class Container, class Cmp>
void Heap<T,Container,Cmp>::swap(T& x, T& y) {
	T tmp=x; x=y; y=tmp;
}
template <class T, class Container, class Cmp>
void Heap<T,Container,Cmp>::up(int at) {
	if(at<=1) return;
	int par = at/2;
	if(cmp(arr[par],arr[at])) {
		swap(arr[par],arr[at]);
		up(par);
	}
}
template <class T, class Container, class Cmp>
void Heap<T,Container,Cmp>::down(int at) {
	int l=at*2, r=at*2+1, pos=at;
	if(l<=sz) if(cmp(arr[pos],arr[l])) pos=l;
	if(r<=sz) if(cmp(arr[pos],arr[r])) pos=r;
	if(pos!=at) {
		swap(arr[at], arr[pos]);
		down(pos);
	}
}
