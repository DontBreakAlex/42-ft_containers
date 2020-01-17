/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:56:51 by ncolomer          #+#    #+#             */
/*   Updated: 2020/01/15 19:52:59 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <cassert>
# include <cstddef>
# include <cmath>
# include <utility>
# include "include/Algorithm.hpp"
# include "include/Tree.hpp"

namespace ft
{
template<typename K, typename T, typename Compare>
class MapCompare
{
private:
    Compare comp;
public:
	MapCompare(): comp() {}
	MapCompare(Compare const &comp): comp(comp) {}
	MapCompare(MapCompare const &other): comp(other.comp) {}
	virtual ~MapCompare() {}

	MapCompare &operator=(MapCompare const &other)
	{
		this->comp = other.comp;
		return (*this);
	}

	Compare const &key_comp() const
	{
		return (this->comp);
	}

    bool operator()(const T& a, const T& b) const
	{
		return (comp(a.first, b.first));
	}
    bool operator()(const T& a, const K& b) const
	{
		return (comp(a.first, b));
	}
    bool operator()(const K& a, const T& b) const
	{
		return (comp(a, b.first));
	}
};

template<typename K, typename T>
class Map
{
public:
	typedef ptrdiff_t difference_type;
	typedef size_t size_type;
	typedef K const key_type;
	typedef T mapped_type;
	typedef typename std::pair<key_type, mapped_type> value_type;
	typedef value_type* pointer;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	typedef typename std::less<key_type> key_compare;
	typedef MapCompare<key_type, value_type, key_compare> map_compare;
	typedef typename Tree<value_type, map_compare>::Node node_type;
	typedef node_type* node_pointer;
	typedef MapIterator<value_type, node_type> iterator;
	typedef MapIterator<value_type const, node_type const> const_iterator;
	typedef ReverseMapIterator<value_type, node_type> reverse_iterator;
	typedef ReverseMapIterator<value_type const, node_type const> const_reverse_iterator;

    class value_compare
    {
    protected:
        key_compare comp;

        value_compare(key_compare c):
			comp(c)
		{
		}
    public:
        bool operator()(const value_type& x, const value_type& y) const
		{
			return (comp(x.first, y.first));
		}
    };
private:
	Tree<value_type, map_compare> tree;
	size_type size_;
public:
	Map():
		tree(), size_(0)
	{
	}
	Map(iterator first, iterator last)
	{
		(void)first;
		(void)last;
		//this->insert(first, last);
	}
	Map(Map const &other):
		tree(), size_(0)
	{
		(void)other;
	}
	virtual ~Map()
	{
	}

	Map &operator=(Map const &other)
	{
		(void)other;
	}

	iterator begin(void)
	{
		return (iterator(this->tree.begin_bound()));
	}
	const_iterator begin(void) const
	{
		return (const_iterator(this->tree.begin_bound()));
	}
	reverse_iterator rbegin(void)
	{
		return (reverse_iterator(this->end()));
	}
	const_reverse_iterator rbegin(void) const
	{
		return (reverse_iterator(this->end()));
	}
	iterator end(void)
	{
		return (iterator(this->tree.end_bound()));
	}
	const_iterator end(void) const
	{
		return (const_iterator(this->tree.end_bound()));
	}
	reverse_iterator rend(void)
	{
		return (reverse_iterator(this->begin()));
	}
	const_reverse_iterator rend(void) const
	{
		return (reverse_iterator(this->begin()));
	}

	bool empty(void) const
	{
		return (this->size_ > 0);
	}
	size_type size(void) const
	{
		return (this->size_);
	}
	size_type max_size(void) const
	{
		return (((std::pow(2, 64) - 1) / sizeof(node_type)) - 1);
	}

	mapped_type &operator[](key_type const &k)
	{
		node_pointer found = this->tree.find(k);
		if (found)
			return (found->get_value().second);
		++this->size_;
		return (this->tree.insert(std::make_pair(k, mapped_type()))->get_value().second);
	}

	typename std::pair<iterator, bool> insert(const_reference val);/*
	{
		node_pointer node = this->tree.find(val);
		if (node)
			return (std::make_pair(iterator(node), false));
		node_pointer inserted = this->tree.insert(val);
		++this->size_;
		return (std::make_pair(iterator(inserted), true));
	}*/
	iterator insert(iterator position, const_reference val);
	template<class InputIterator>
	void insert(InputIterator first, InputIterator last);
	void erase(iterator position);
	size_type erase(key_type const &key);
	void erase(iterator first, iterator last);
	void swap(Map &x);
	void clear(void);

	key_compare key_comp(void) const;
	value_compare value_comp(void) const
	{
		return (this->tree.value_comp().comp);
	}

	iterator find(key_type const &key);
	const_iterator find(key_type const &key) const;
	size_type count(key_type const &k) const;
	iterator lower_bound(key_type const &key);
	const_iterator lower_bound(key_type const &key) const;
	iterator upper_bound(key_type const &key);
	const_iterator upper_bound(key_type const &key) const;
	typename std::pair<iterator, iterator> equal_range(key_type const &key);
	typename std::pair<const_iterator, const_iterator> equal_range(key_type const &key) const;
};
}

#endif
