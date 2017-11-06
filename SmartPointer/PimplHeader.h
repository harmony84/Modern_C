#pragma once
#include <memory>

struct PimplStructure;

class Widget
{
public:
	Widget();
//////////////////////////////////////////////////////////////////////////
// type 1
	~Widget();

	Widget(Widget&& rhs);
	Widget& operator=(Widget&& rhs);

	Widget(Widget& rhs);
	Widget& operator=(const Widget& rhs);
private:
	std::unique_ptr<PimplStructure> pImpl;

//////////////////////////////////////////////////////////////////////////
// type 2
//private:
//	std::shared_ptr<PimplStructure> pImpl;
};