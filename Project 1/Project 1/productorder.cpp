// productorder.cpp
// Rose Peters
// Started: 2020-09-01
// Updated: 2020-09-07
// 
// For CS 311 Fall 2020
// Source for class ProductOrder
// Product order product name, # items ordered.

#include "productorder.h"



// *********************************************************************
// class ProductOrder - Definitions of member functions
// *********************************************************************

// ProductOrder::toString
// (See header for docs.)
string ProductOrder::toString() const {
	return getName() + " (" + std::to_string(getNumber()) + ")";
}

// ProductOrder::getName
// (See header for docs.)
string ProductOrder::getName() const {
	return _productName;
}

// ProductOrder::setName
// (See header for docs.)
void ProductOrder::setName(string productName) {
	_productName = productName;
}

// ProductOrder::getNumber
// (See header for docs.)
int ProductOrder::getNumber() const {
	return _itemsOrdered;
}

// ProductOrder::setNumber
// (See header for docs.)
void ProductOrder::setNumber(int itemsOrdered) {
		_itemsOrdered = itemsOrdered;
}

// ProductOrder::empty
// (See header for docs.)
bool ProductOrder::empty() const {
	if (_itemsOrdered == 0) {
		return true;
	}
	return false;
}


// *********************************************************************
// class ProductName - Definitions of associated global operators
// *********************************************************************



//operator<< (ostream, ProductOrder)
// see header for docs.
std::ostream& operator<<(std::ostream& out, const ProductOrder& product) {
	out << product.getName() + " (" + std::to_string(product.getNumber()) + ")";
	return out;

}
//operator!= (ProductOrder, ProductOrder)
// see header for docs.
bool operator!=(const ProductOrder& lhs, const ProductOrder& rhs) {
	return !(lhs == rhs);
}