#include <string>
#include <memory>
#include <vector>
#include "PimplHeader.h"

class Investment
{
public:
	Investment( std::string& s ) : str( s ) {};
	Investment( std::string&& s ) : str( std::move( s ) ) {};
	virtual ~Investment() { printf( "Destruct Investment\n" ); }
private:
	std::string str;
};

class Stock : public Investment
{
public:
	Stock( std::string&& s ) : Investment( std::move( s ) ) {}
	virtual ~Stock() { printf( "Destruct stock\n" ); }
};

class Bond : public Investment
{
public:
	Bond( std::string&& s ) : Investment( std::move( s ) ) {}
	virtual ~Bond() { printf( "Destruct Bond\n" ); }
};

class RealEstate : public Investment
{
public:
	RealEstate( std::string&& s ) : Investment( std::move( s ) ) {}
	virtual ~RealEstate() { printf( "Destruct RealEstate\n" ); }
};

//////////////////////////////////////////////////////////////////////////
// Factory function
template<typename T>
//std::unique_ptr<Investment, void( *)( Investment* )> makeInvestment( int state_index, T&& params )
auto makeInvestment( int state_index, T&& params )
{
	auto delInvmt = []( Investment* pInvestment )
	{
		printf( "Log : Destroy\n" );
		delete pInvestment;
	};

	std::unique_ptr<Investment, decltype( delInvmt )> pInv( nullptr, delInvmt );

	switch ( state_index )
	{
	case 0:
		pInv.reset( new Stock( std::move<T>( params ) ) );
		break;
	case 1:
		pInv.reset( new Bond( std::move<T>( params ) ) );
		break;
	case 2:
		pInv.reset( new RealEstate( std::move<T>( params ) ) );
		break;
	default:
		pInv.reset( new Investment( std::move<T>( params ) ) );
		break;
	}

	return pInv;
}


int main()
{
	//////////////////////////////////////////////////////////////////////////
	// unique pointer
	std::string name1{ "harmony_1" };
	std::string name2{ "harmony_2" };

	auto investment_1 = makeInvestment( 1, name1 );
	std::shared_ptr<Investment> investment_2 = makeInvestment( 2, name2 );	// unique_ptr to shared_ptr 

	auto unique_Investment_1{ std::make_unique<Investment>( "harmony_3" ) };
	std::shared_ptr<Investment> unique_Investment_2{ std::move( unique_Investment_1 ) };	// perfect move - maintain pointer count

	if ( unique_Investment_1 == nullptr )
	{
		printf( "unique_ptr was null pointer\n" );
	}


	//////////////////////////////////////////////////////////////////////////
	// shared pointer
	//std::shared_ptr<Investment> investment_shared_1 = std::make_shared<Investment>("shared_1");
	auto investment_shared_1 = std::make_shared<Investment>( "shared_1" );
	auto investment_shared_2 = std::move(investment_shared_1);

	printf("how many use shared pointer : %d\n", investment_shared_2.use_count() );
	investment_shared_1.reset();
	printf( "how many use shared pointer : %d\n", investment_shared_1.use_count() );

	auto custom_deleter_1 = [](Investment* inv)
	{ 
		printf("custom deleter type 1\n");
		delete inv; 
	};

	auto custom_deleter_2 = []( Investment* inv )
	{
		printf( "custom deleter type 2\n" );
		delete inv;
	};

	std::shared_ptr<Investment> investment_shared_customdeleter_1{ new Investment( "shared_customdeleter_1" ), custom_deleter_1 };
	std::shared_ptr<Investment> investment_shared_customdeleter_2{ new Investment( "shared_customdeleter_2" ), custom_deleter_2 };

	std::vector<std::shared_ptr<Investment>> vec_shared_investment { investment_shared_customdeleter_1, investment_shared_customdeleter_2 };		// ok


	//std::unique_ptr<Investment> investment_unique_customdeleter_1{ new Investment( "unique_customdeleter_1" ), custom_deleter_1 };
	//std::unique_ptr<Investment> investment_unique_customdeleter_2{ new Investment( "unique_customdeleter_2" ), custom_deleter_2 };

	//std::vector<std::unique_ptr<Investment>> vec_unique_investment{ investment_unique_customdeleter_1, investment_unique_customdeleter_2 };		// comfile error



	//////////////////////////////////////////////////////////////////////////
	// weak_ptr
	auto investment_shared_pointer = std::make_shared<Investment>( "weak_shared_pointer" );
	std::weak_ptr<Investment> investment_weak_pointer { investment_shared_pointer };

	printf( "how many use shared pointer : %d\n", investment_shared_pointer.use_count() );
	
	std::shared_ptr<Investment> investment_create_shared_pointer; 
	investment_create_shared_pointer = investment_weak_pointer.lock();	// get shared pointer from unique pointer.

	printf( "how many use shared pointer : %d\n", investment_shared_pointer.use_count() );

	investment_shared_pointer.reset();		// shared_ptr count = 1
	investment_create_shared_pointer.reset();		// shared_ptr count = 0
	investment_create_shared_pointer = investment_weak_pointer.lock();		// if fail to get pointer return nullptr.

	if ( investment_create_shared_pointer == nullptr )
	{
		printf( "This pointer expired.\n" );
	}

	if ( investment_weak_pointer.expired() == true )
	{
		printf("This pointer expired.\n");
	}

	
	//////////////////////////////////////////////////////////////////////////
	// Pimpl
	auto pimpl_widget_1 = std::make_shared<Widget>();
	auto pimpl_widget_2{ std::move( pimpl_widget_1 ) };
	pimpl_widget_1 = std::move( pimpl_widget_2 );

	return 0;
}

