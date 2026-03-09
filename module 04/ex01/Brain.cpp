Brain::Brain() {
    std::cout << "Brain: default constructor called Brain" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain: copy constructor called Brain" << std::endl;
    *this = other;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain: copy assignment operator called Brain" << std::endl;
    if (this == &other)
        return *this;
    for (int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain: destructor called Brain" << std::endl;
}
