#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <stdexcept>
#include <utility>
#include <sys/time.h>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	*this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::parse(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string token = argv[i];
		if (token.empty())
			throw std::runtime_error("Error");
		for (size_t j = 0; j < token.size(); ++j)
			if (!std::isdigit(token[j]))
				throw std::runtime_error("Error");

		char *end;
		long value = std::strtol(token.c_str(), &end, 10);
		if (*end != '\0' || value > INT_MAX)
			throw std::runtime_error("Error");

		_vec.push_back(static_cast<int>(value));
		_deq.push_back(static_cast<int>(value));
	}
	if (_vec.empty())
		throw std::runtime_error("Error");
}

static std::vector<size_t> jacobsthalOrder(size_t pendSize)
{
	std::vector<size_t> order;
	if (pendSize == 0)
		return order;

	size_t prevJ = 0;
	size_t a = 1;
	size_t b = 1;
	while (prevJ < pendSize)
	{
		size_t bound = b;
		if (bound > pendSize)
			bound = pendSize;
		for (size_t i = bound; i > prevJ; --i)
			order.push_back(i);
		prevJ = b;
		size_t next = b + 2 * a;
		a = b;
		b = next;
	}
	return order;
}

template <typename C>
static void binaryInsert(C &main, int value)
{
	size_t low = 0;
	size_t high = main.size();
	while (low < high)
	{
		size_t mid = (low + high) / 2;
		if (value < main[mid])
			high = mid;
		else
			low = mid + 1;
	}
	main.insert(main.begin() + low, value);
}

template <typename C>
static void mergeInsertSort(C &seq)
{
	if (seq.size() < 2)
		return;

	bool hasStraggler = (seq.size() % 2 != 0);
	int straggler = 0;
	if (hasStraggler)
		straggler = seq.back();

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < seq.size(); i += 2)
	{
		int x = seq[i];
		int y = seq[i + 1];
		if (x > y)
			pairs.push_back(std::make_pair(y, x));
		else
			pairs.push_back(std::make_pair(x, y));
	}

	C larges;
	for (size_t i = 0; i < pairs.size(); ++i)
		larges.push_back(pairs[i].second);
	mergeInsertSort(larges);

	std::vector<std::pair<int, int> > sortedPairs;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < larges.size(); ++i)
	{
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (!used[j] && pairs[j].second == larges[i])
			{
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	C main;
	main.push_back(sortedPairs[0].first);
	for (size_t i = 0; i < sortedPairs.size(); ++i)
		main.push_back(sortedPairs[i].second);

	std::vector<int> pend;
	for (size_t i = 1; i < sortedPairs.size(); ++i)
		pend.push_back(sortedPairs[i].first);

	std::vector<size_t> order = jacobsthalOrder(pend.size());
	for (size_t i = 0; i < order.size(); ++i)
		binaryInsert(main, pend[order[i] - 1]);

	if (hasStraggler)
		binaryInsert(main, straggler);

	seq = main;
}

void PmergeMe::sortVector()
{
	mergeInsertSort(_vec);
}

void PmergeMe::sortDeque()
{
	mergeInsertSort(_deq);
}

void PmergeMe::printVector(std::string const &prefix, std::vector<int> const &v) const
{
	std::cout << prefix;
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << " " << v[i];
	std::cout << std::endl;
}

void PmergeMe::run(int argc, char **argv)
{
	parse(argc, argv);

	printVector("Before:", _vec);

	struct timeval start, end;

	gettimeofday(&start, NULL);
	sortVector();
	gettimeofday(&end, NULL);
	double vecTime = (end.tv_sec - start.tv_sec) * 1000000.0
		+ (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	sortDeque();
	gettimeofday(&end, NULL);
	double deqTime = (end.tv_sec - start.tv_sec) * 1000000.0
		+ (end.tv_usec - start.tv_usec);

	printVector("After: ", _vec);

	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque  : " << deqTime << " us" << std::endl;
}
