class Fixed {
	private:
		int _valueFixedPoint;
		static const int _bits;

	public:
		Fixed(void);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copy);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
};