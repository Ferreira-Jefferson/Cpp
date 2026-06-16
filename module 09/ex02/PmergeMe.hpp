#pragma once

#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();

		void run(int argc, char **argv);

	private:
		std::vector<int> _vec;
		std::deque<int> _deq;

		void parse(int argc, char **argv);
		void sortVector();
		void sortDeque();

		void printVector(std::string const &prefix, std::vector<int> const &v) const;
};
