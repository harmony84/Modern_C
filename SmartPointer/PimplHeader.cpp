#include "PimplHeader.h"
#include "PImplStructure.h"

Widget::Widget() 
	: pImpl(std::make_unique<PimplStructure>())
{
}

//////////////////////////////////////////////////////////////////////////
// type 1
Widget::~Widget() = default;
Widget::Widget( Widget&& rhs ) = default;
Widget& Widget::operator=( Widget&& rhs ) = default;

Widget::Widget( Widget& rhs ) 
	: pImpl(nullptr)
{
	if ( rhs.pImpl != nullptr )
	{
		pImpl = std::make_unique<PimplStructure>(*rhs.pImpl);
	}
}

Widget& Widget::operator=( const Widget& rhs )
{
	if ( rhs.pImpl == nullptr )
	{
		pImpl.reset();
	}
	else if (pImpl == nullptr )
	{
		std::make_unique<PimplStructure>(*rhs.pImpl);
	}
	else 
	{
		*pImpl = *rhs.pImpl;
	}

	return *this;
}

