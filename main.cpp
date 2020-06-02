/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 15:57:31 by ncolomer          #+#    #+#             */
/*   Updated: 2020/03/11 15:21:35 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test/test.hpp"
#include <fstream>

/**
 * * std tests
 **/
void start_all_std_tests(void) {
	test("vector");
	test_Vector<std::vector<int> >();
#ifdef FULL
	test_Vector<std::vector<Number> >();
#endif
	end_test("vector");

	test("list");
	test_List<std::list<int>, int>();
#ifdef FULL
	test_List<std::list<Number>, Number>();
#endif
	end_test("list");

	test("stack");
	test_Stack<std::stack<int>, std::deque<int> >();
#ifdef FULL
	test_Stack<std::stack<Number>, std::deque<Number> >();
#endif
	end_test("stack");

	test("queue");
	test_Queue<std::queue<int>, std::deque<int> >();
#ifdef FULL
	test_Queue<std::queue<Number>, std::deque<Number> >();
#endif
	end_test("queue");

	test("map");
	test_Map<std::map<int, int> >();
#ifdef FULL
	test_Map<std::map<char, int> >(48);
	test_Map<std::map<char, Number> >(48);
	test_Map<std::map<Number, int> >();
	test_Map<std::map<Number, Number> >();
#endif
	end_test("map");

	test("multimap");
	test_Multimap<std::multimap<int, int> >();
#ifdef FULL
	test_Multimap<std::multimap<char, int> >(48);
	test_Multimap<std::multimap<char, Number> >(48);
	test_Multimap<std::multimap<Number, int> >();
	test_Multimap<std::multimap<Number, Number> >();
#endif
	end_test("multimap");

	test("set");
	test_Set<std::set<int> >();
#ifdef FULL
	test_Set<std::set<Number> >();
#endif
	end_test("set");

	test("multiset");
	test_Multiset<std::multiset<int> >();
#ifdef FULL
	test_Multiset<std::multiset<Number> >();
#endif
	end_test("multiset");

	test("deque");
	test_Deque<std::deque<int> >();
#ifdef FULL
	test_Deque<std::deque<Number> >();
#endif
	end_test("deque");
}

/**
 * * ft tests
 **/
void start_all_ft_tests(void) {
	test("vector");
	test_Vector<ft::vector<int> >();
#ifdef FULL
	test_Vector<ft::vector<Number> >();
#endif
	end_test("vector");

	test("list");
	test_List<ft::list<int>, int>();
#ifdef FULL
	test_List<ft::list<Number>, Number>();
#endif
	end_test("list");

	test("stack");
	test_Stack<ft::stack<int>, ft::list<int> >();
#ifdef FULL
	test_Stack<ft::stack<Number>, ft::list<Number> >();
#endif
	end_test("stack");

	test("queue");
	test_Queue<ft::queue<int>, ft::list<int> >();
#ifdef FULL
	test_Queue<ft::queue<Number>,ft::list<Number> >();
#endif
	end_test("queue");

	test("map");
	test_Map<ft::map<int, int> >();
#ifdef FULL
	test_Map<ft::map<char, int> >(48);
	test_Map<ft::map<char, Number> >(48);
	test_Map<ft::map<Number, int> >();
	test_Map<ft::map<Number, Number> >();
#endif
	end_test("map");

	test("multimap");
	test_Multimap<ft::multimap<int, int> >();
#ifdef FULL
	test_Multimap<ft::multimap<char, int> >(48);
	test_Multimap<ft::multimap<char, Number> >(48);
	test_Multimap<ft::multimap<Number, int> >();
	test_Multimap<ft::multimap<Number, Number> >();
#endif
	end_test("multimap");

	test("set");
	test_Set<ft::set<int> >();
#ifdef FULL
	test_Set<ft::set<Number> >();
#endif
	end_test("set");

	test("multiset");
	test_Multiset<ft::multiset<int> >();
#ifdef FULL
	test_Multiset<ft::multiset<Number> >();
#endif
	end_test("multiset");

	test("deque");
	test_Deque<ft::deque<int> >();
#ifdef FULL
	test_Deque<ft::deque<Number> >();
#endif
	end_test("deque");
}

int main(void)
{
	std::streambuf *coutbuf = std::cout.rdbuf();

	std::ofstream stdOut("std_out");
    std::cout.rdbuf(stdOut.rdbuf());
	start_all_std_tests();
	stdOut.close();

    std::cout.rdbuf(coutbuf);

	std::ofstream ftOut("ft_out");
    std::cout.rdbuf(ftOut.rdbuf());
	start_all_ft_tests();
	ftOut.close();

    std::cout.rdbuf(coutbuf);

	// Check Number count
#ifdef FULL
	std::cout << "Total Number created: " << Number::getCreated() << '\n'
			<< "Total Number destructed: " << Number::getDestructed() << '\n';
	assert(Number::getCreated() == Number::getCreated());
#endif

	return (0);
}
