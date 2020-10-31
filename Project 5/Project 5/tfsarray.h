// TFSArray.h
// Rose Peters
// Started: 2020-10-23
// Updated: 2020-10-29
//
// For CS 311 Fall 2020
// Header for class TFSArray
// Smart array of given type

#ifndef FILE_TFSArray_H_INCLUDED
#define FILE_TFSArray_H_INCLUDED

#include <cstddef>
// For std::size_t
#include <algorithm>
// For std::max


// *********************************************************************
// class TFSArray - Class definition
// *********************************************************************


// class TFSArray
// Frightfully Smart Array of given type.
// Resizable, copyable/movable, exception-safe.
// Invariants:
//     0 <= _size <= _capacity.
//     _data points to an array of value_type, allocated with new [],
//      owned by *this, holding _capacity value_type values -- UNLESS
//      _capacity == 0, in which case _data may be nullptr.
// Requirements on Type:
//						Valtype must have a copy ctor and a (non-throwing) dctor.
template<typename ValType>
class TFSArray {

	// ***** TFSArray: types *****
public:

	// value_type: type of data items
	using value_type = ValType;

	// size_type: type of sizes & indices
	using size_type = std::size_t;

	// iterator, const_iterator: random-access iterator types
	using iterator = value_type*;
	using const_iterator = const value_type*;

	// ***** TFSArray: internal-use constants *****
private:

	// Capacity of default-constructed object
	enum { DEFAULT_CAP = 16 };

	// ***** TFSArray: ctors, op=, dctor *****
public:

	// Default ctor & ctor from size
	// Strong Guarantee
	explicit TFSArray(size_type size = 0)
		:_capacity(std::max(size, size_type(DEFAULT_CAP))),
		// _capacity must be declared before _data
		_size(size),
		_data(_capacity == 0 ? nullptr : new value_type[_capacity])
	{}

	// Copy ctor
	// No-Throw Guarantee
	TFSArray(const TFSArray& other)
		: _capacity(std::max(other._size, size_type(DEFAULT_CAP))),
		_size(other._size),
		_data(other._capacity == 0 ? nullptr : new value_type[other._capacity])
	{
		try {
			std::copy(other.begin(), other.end(), _data);
		}
		catch (...) {
			delete[] _data;
			throw;
		}
	}


	// Move ctor
	// No-Throw Guarantee
	TFSArray(TFSArray&& other) noexcept
		:_data(other._data),
		_size(other._size),
		_capacity(other._capacity)
	{
		other._size = 0;
		other._data = nullptr;
	}

	// Copy assignment
	// Basic Guarantee
	TFSArray& operator=(const TFSArray& other) {
		TFSArray copy(other);
		mswap(copy);
		return *this;
	}

	// Move assignment
	// No-Throw Guarantee
	TFSArray& operator=(TFSArray&& other) noexcept

	{
		mswap(other);
		return *this;
	}

	// Dctor
	// No-Throw Guarantee
	~TFSArray()
	{
		delete[] _data;
	}

	// ***** TFSArray: general public operators *****
public:

	// operator[] - non-const & const
	// Pre:
	//     0 <= index
	// No-Throw Guarantee
	value_type& operator[](size_type index) noexcept
	{
		return _data[index];
	}
	const value_type& operator[](size_type index) const noexcept
	{
		return _data[index];
	}

	// ***** TFSArray: general public functions *****
public:

	// size
	// No-Throw Guarantee
	size_type size() const noexcept
	{
		return _size;
	}

	// empty
	// No-Throw Guarantee
	bool empty() const noexcept
	{
		return size() == 0;
	}

	// begin - non-const & const
	// No-Throw Guarantee
	iterator begin() noexcept
	{
		return _data;
	}

	const_iterator begin() const noexcept
	{
		return _data;
	}

	// end - non-const & const
	// No-Throw Guarantee
	iterator end() noexcept
	{
		return begin() + size();
	}
	const_iterator end() const noexcept
	{
		return begin() + size();
	}


	// resize
	// No-Throw Guarantee
	// Pre:
	//		0 <= newsize
	void resize(size_type newsize) {

		size_type newSize = newsize;
		size_type newCapacity = std::max(_capacity * 2, newsize);

		if (newsize <= _capacity) {
			_size = newsize;
		}
		if (newsize > _capacity) {
			value_type* newData = new value_type[newCapacity];
			try {
				std::copy(begin(), end(), newData);
			}
			catch (...) {
				delete[] newData;
				throw;
			}
			delete[] _data;
			std::swap(_data, newData);
			std::swap(_capacity, newCapacity);
			std::swap(_size, newSize);

		}
	}

	// insert
	// No-Throw Guarantee
	// Pre:
	//		_size contains pos
	iterator insert(iterator pos,
		const value_type& item) {


		size_type index = pos - begin();
		resize(_size + 1);
		iterator it = begin() + index;
		_data[_size - 1] = item;

		try {
			std::rotate(it, begin() + _size - 1, end());
		}
		catch (...) {
			resize(_size - 1);
			throw;
		}
		return it;

	}

	// erase
	// Basic Guarantee
	// Pre:
	//		_size contains pos 
	iterator erase(iterator pos)
	{

		std::rotate(pos, pos + 1, end());
		resize(_size - 1);
		return pos;
	}

	// push_back
	// Basic Guarantee
	void push_back(const value_type& item)
	{
		insert(end(), item);
	}

	// pop_back
	// ??? Guarantee
	void pop_back()
	{
		erase(end() - 1);
	}

	// swap
	// No-Throw Guarantee
	void swap(TFSArray& other) noexcept {
		other.mswap(*this);
	}

	// ***** TFSArray: data members *****
private:

	size_type    _capacity;  // Size of our allocated array
	size_type    _size;      // Size of client's data
	value_type* _data;      // Pointer to our array

	void mswap(TFSArray& other) noexcept { //swap pointer values
		std::swap(_data, other._data);
		std::swap(_size, other._size);
	}

};  // End class TFSArray


#endif  //#ifndef FILE_TFSArray_H_INCLUDED

