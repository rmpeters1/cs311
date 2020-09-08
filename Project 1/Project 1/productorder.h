// productorder.h
// Rose Peters
// Started: 2020-09-01
// Updated: 2020-09-07
// 
// For CS 311 Fall 2020
// Header for class ProductOrder
// Product order product name, # items ordered.

#ifndef PRODUCTORDER_HPP_
#define PRODUCTORDER_HPP_

#include <iostream>
#include <ostream>
#include <string>
using std::string;


// *********************************************************************
// class ProductName - Class definition
// *********************************************************************


// class ProductOrder
// Product order: product name, # items ordered.
// Invariants:
//  0 <= _itemsOrdered
// "" || string == productName
class ProductOrder {

	// ***** ProductName: Ctors, dctor, op= *****
public:

	// Default ctor
	// Set product name to unspecified.
	// Set items ordered to 0.
	ProductOrder() :
		_productName("UNSPECIFIED"),
		_itemsOrdered(0)
	{
	}

	//Ctor from product name, # items ordered
	// Set product name and # items ordered to given string and int.
	// set _neg to true if itemsOrdered < 0
	// Pre: 
	//  0 <= _itemsOrdered
	// "" || string == productName
	ProductOrder(string productName, int itemsOrdered) :
		_productName(productName),
		_itemsOrdered(itemsOrdered)
	{
		if (_itemsOrdered < 0) {
			_itemsOrdered = -_itemsOrdered;
		}
	}

	// Big 5: using automatically generated versions
	ProductOrder(const ProductOrder& product) = default;
	ProductOrder(ProductOrder&& product) = default;
	ProductOrder& operator=(const ProductOrder& product) = default;
	ProductOrder& operator=(ProductOrder&& product) = default;
	~ProductOrder() = default;

	// ***** ProductOrder: General public operators *****
public:

	// op==
	// Verify one product is equal to another
	friend bool operator==(const ProductOrder& lhs, const ProductOrder& rhs) {
		return lhs._productName == rhs._productName &&
			lhs._itemsOrdered == rhs._itemsOrdered;
	}

	// op++ [pre]
	// Add one to items ordered.
	ProductOrder& operator++() {
		++_itemsOrdered;
		return *this;
	}

	// op++ [post]
	// Add one to items ordered.
	ProductOrder operator++([[maybe_unused]] int dummy) {
		auto save = *this;
		++(*this);
		return save;
	}

	// op-- [pre]
	// Subtract one from items ordered.
	ProductOrder& operator--() {
		if (_itemsOrdered > 0) {
			--_itemsOrdered;
			return *this;
		}
	}

	// op-- [post]
	// Subtract one from items ordered.
	ProductOrder operator--([[maybe_unused]] int dummy)
	{
		auto save = *this;
		--(*this);
		return save;
	}

	// ***** ProductName: General public functions *****
public:

	// getName
	// Return product name.
	string getName() const;

	// setName
	// Set product name to given string.
	// Pre:
	// "" || string == productName
	void setName(string productName);

	// getNumber
	// Return # items ordered.
	int getNumber() const;

	// setNumber
	// Set items ordered to given int.
	//  values < 0 will not be set.
	// Pre:
	// 0 <= _itemsOrdered
	void setNumber(int itemsOrdered);

	// toString
	// return object as string: 
	// "productName (itemsOrdered)"
	string toString() const;

	// empty
	// return true if # items ordered = 0
	bool empty() const;

	// ***** ProductName: Data members *****
private:

	string _productName; // name of the product
	int _itemsOrdered; // # of products ordered
	bool _neg; // tell if value is negative

}; // End class ProductName



// *********************************************************************
// class ProductOrder - Declarations of associated global operators
// *********************************************************************


// operator<< (ostream, ProductName)
// Prints ProductOrder as productName (itemsOrdered)
std::ostream& operator<<(std::ostream&, const ProductOrder&);

// operator!= (ProductOrder, ProductOrder)
// Verify one product is not equal to another
bool operator!=(const ProductOrder&, const ProductOrder&);

#endif //!PRODUCTORDER_HPP_