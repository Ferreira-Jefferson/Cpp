#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>
#include <stdexcept>

class Span {
	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename InputIterator>
		void addRange(InputIterator begin, InputIterator end);

	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
};

template <typename InputIterator>
void Span::addRange(InputIterator begin, InputIterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw std::out_of_range("Span: range exceeds remaining capacity");
	_numbers.insert(_numbers.end(), begin, end);
}

#endif
