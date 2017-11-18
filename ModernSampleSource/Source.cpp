#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <array>



#pragma region "decltype"
template<typename Container, typename Index>
decltype(auto) authAndAccess(Container& c, Index i)
{
	return c[i];
}
#pragma endregion


#pragma region "Item type deduction"
template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
	return N;
}
#pragma endregion


#pragma region "check type"
template<typename T>
class TD;
#pragma endregion


#pragma region "alias"
template<typename T>
using MyAllocList = std::list<T>;
#pragma endregion


#pragma region "constexpr"
constexpr int pow(int base, int exp)
{
	return (exp == 0 ? 1 : base * pow(base, exp - 1));
}

class Point 
{
public:
	constexpr Point(double xVal = 0, double yVal =0) : x(xVal), y(yVal) { }

	constexpr double xValue() const { return x; }
	constexpr double yValue() const { return y; }

	void SetX( double newX ) noexcept { x = newX; }
	void SetY( double newY ) noexcept { y = newY; }

private:
	double x, y;
};
#pragma endregion

int main()
{
#pragma region "Item type deduction"
	const char name[] = { "J. P. Brigger" };
	auto count = arraySize(name);
#pragma endregion

#pragma region "decltype"
	std::deque<int> d { 1,2,3,4,5,6 };

	authAndAccess(d, 5) = 10;
#pragma endregion

#pragma region "check type"
	const int theAnswer = 42;
	auto x = theAnswer;
	auto y = &theAnswer;

	// case 1 - IDE
	// case 2 - comfile error
	//TD<decltype( x )> xType;
	//TD<decltype( y )> yType;

	// case 3 - type id
	std::cout << typeid( x ).name() << std::endl;
	std::cout << typeid( y ).name() << std::endl;

	// case 4 - boost::typeindex
#pragma  endregion

#pragma region "don't want boolean deduction "
	std::vector<bool> boolContainer = { true, false, false, true, true };
	std::vector<int> integerContainer = { 1, 2, 3, 4, 5 };

	auto boolHighPriority = boolContainer[1];
	auto integerHighPriority = integerContainer[ 1 ];
#pragma endregion

#pragma region "scoped enum"
	enum class Status : std::uint8_t { failed, success, invalid };

	int classInteger = 1;

	//if ( classInteger == Status::invalid ) // comfile error
	if ( classInteger == static_cast<int>(Status::invalid) )
	{
		printf("equal enum\n");
	}
#pragma endregion 

#pragma region "constexpr"
	constexpr auto num_conds = 5;
	std::array<int, pow(3, num_conds )> results;

	constexpr Point p1( 9.4, 27.7 );
	constexpr Point p2( 28.1, 5.3 );
	Point p3( 11.1, 65.3 );
#pragma endregion

	return 0;
}