// Time.cpp

//---------------------------------------------------------------------------
// HEADER FILES:
//---------------------------------------------------------------------------
#include "AzulTime.h"
#include <limits>   // For numeric_limits< Time::Representation >.


//---------------------------------------------------------------------------
// FRIENDS:
//---------------------------------------------------------------------------
const AzulTime operator*( const float ratio, const AzulTime& rhs )
{
	return(
		AzulTime( static_cast<AzulTime::Representation >( ratio * rhs._rawTime ) )
  	);
}

const AzulTime operator*( const int ratio, const AzulTime& rhs )
{
	return(AzulTime( ratio * rhs._rawTime ) );
}



//---------------------------------------------------------------------------
// CONSTRUCTORS:
//---------------------------------------------------------------------------

AzulTime::AzulTime( const Duration duration ): _rawTime( 0 )
{
	// IMPORTANT: This is private information that is SUBJECT TO CHANGE!
	//
	// Currently: 1 second = 30000
	//            1 ms     = 30
	//            1 NTSC   = 500
	//            1 PAL    = 600
	//
	// At 32 bits, this gives us a range of roughly -20 to 20 hours.
	const AzulTime::Representation ONE_RAW_SECOND = 30000;

	switch ( duration )
	{
		case TIME_ZERO:
			this->_rawTime = 0;
			break;

		case TIME_NTSC_FRAME:
			this->_rawTime = ONE_RAW_SECOND / 60;
			break;

		case TIME_NTSC_30_FRAME:
			this->_rawTime = 2 * ONE_RAW_SECOND / 60;
			break;

		case TIME_PAL_FRAME:
			this->_rawTime = ONE_RAW_SECOND / 50;
			break;

		case TIME_ONE_SECOND:
			this->_rawTime = ONE_RAW_SECOND;
			break;

		case TIME_ONE_MILLISECOND:
			this->_rawTime = ONE_RAW_SECOND / 1000;
			break;

		case TIME_ONE_MINUTE:
			this->_rawTime = 60 * ONE_RAW_SECOND;
			break;

		case TIME_ONE_HOUR:
			this->_rawTime = 60 * 60 * ONE_RAW_SECOND;
			break;

		case TIME_MIN:
			this->_rawTime = std::numeric_limits< AzulTime::Representation >::min();
			break;

		case TIME_MAX:
			this->_rawTime = std::numeric_limits< AzulTime::Representation >::max();
			break;

		default:
			// IMPORTANT: Intentionally avoiding assertion handling
			//            for the Time library.
			this->_rawTime = 0;
			break;
	}
}



//---------------------------------------------------------------------------
// COMPARISONS:
//---------------------------------------------------------------------------
bool AzulTime::operator==( const AzulTime& rhs ) const
{
	return( this->_rawTime == rhs._rawTime );
}


bool AzulTime::operator!=( const AzulTime& rhs ) const
{
	return( this->_rawTime != rhs._rawTime );
}


bool AzulTime::operator<( const AzulTime& rhs ) const
{
	return( this->_rawTime < rhs._rawTime );
}


bool AzulTime::operator<=( const AzulTime& rhs ) const
{
	return( this->_rawTime <= rhs._rawTime );
}


bool AzulTime::operator>( const AzulTime& rhs ) const
{
	return( this->_rawTime > rhs._rawTime );
}


bool AzulTime::operator>=( const AzulTime& rhs ) const
{
	return( this->_rawTime >= rhs._rawTime );
}



//---------------------------------------------------------------------------
// NEGATION / ADDITION / SUBTRACTION:
//---------------------------------------------------------------------------
const AzulTime AzulTime::operator-() const
{
	return(AzulTime( -this->_rawTime ) );
}


const AzulTime AzulTime::operator+( const AzulTime& rhs ) const
{
	// !!! FIXME: Overflow checks
	return(AzulTime( this->_rawTime + rhs._rawTime ) );
}


const AzulTime AzulTime::operator-( const AzulTime& rhs ) const
{
	// !!! FIXME: Overflow checks
	return(AzulTime( this->_rawTime - rhs._rawTime ) );
}


AzulTime& AzulTime::operator+=( const AzulTime& rhs )
{
	// !!! FIXME: Overflow checks
	this->_rawTime += rhs._rawTime;
	return( *this );
}


AzulTime& AzulTime::operator-=( const AzulTime& rhs )
{
	// !!! FIXME: Overflow checks
	this->_rawTime -= rhs._rawTime;
	return( *this );
}



//---------------------------------------------------------------------------
// MULTIPLICATION:
//---------------------------------------------------------------------------
const AzulTime AzulTime::operator*( const float ratio ) const
{
	// !!! FIXME: Overflow checks
	return(
		AzulTime( static_cast< Representation >( ratio * this->_rawTime ) )
		);
}


const AzulTime AzulTime::operator*( const int ratio ) const
{
	// !!! FIXME: Overflow checks
	return(AzulTime( this->_rawTime * ratio ) );
}


AzulTime& AzulTime::operator*=( const float ratio )
{
	// !!! FIXME: Overflow checks
	this->_rawTime = static_cast< Representation>( ratio * this->_rawTime );
	return( *this );
}


AzulTime& AzulTime::operator*=( const int ratio )
{
	// !!! FIXME: Overflow checks
	this->_rawTime *= ratio;
	return( *this );
}



//---------------------------------------------------------------------------
// DIVISION:
//---------------------------------------------------------------------------
float AzulTime::operator/( const AzulTime& denominator ) const
{
	// !!! FIXME: Divide by zero.
	return(
		static_cast< float >( this->_rawTime ) / denominator._rawTime
		);
}


const AzulTime AzulTime::operator/( const float denominator ) const
{
	// !!! FIXME: Divide by zero.
	return(
		AzulTime( static_cast< Representation >( this->_rawTime / denominator ) )
		);
}


const AzulTime AzulTime::operator/( const int denominator ) const
{
	// !!! FIXME: Divide by zero.
	return(AzulTime( this->_rawTime / denominator ) );
}


AzulTime& AzulTime::operator/=( const float denominator )
{
	// !!! FIXME: Divide by zero.
	this->_rawTime = 
		static_cast< Representation>( this->_rawTime / denominator );
	return( *this );
}


AzulTime& AzulTime::operator/=( const int denominator )
{
	// !!! FIXME: Divide by zero.
	this->_rawTime /= denominator;
	return( *this );
}



//---------------------------------------------------------------------------
// DIVISION:
//---------------------------------------------------------------------------
int AzulTime::quotient( const AzulTime& numerator, const AzulTime& denominator )
{
	// !!! FIXME: Divide by zero & check range
	return(static_cast< int > (numerator._rawTime / denominator._rawTime ));
}


const AzulTime AzulTime::remainder( const AzulTime& numerator, const AzulTime& denominator )
{
	// !!! FIXME: Divide by zero.
	return(AzulTime( numerator._rawTime % denominator._rawTime ) );
}


//---------------------------------------------------------------------------
// PRIVATE IMPLEMENTATION:
//---------------------------------------------------------------------------
AzulTime::AzulTime( const AzulTime::Representation rawTime ): _rawTime( rawTime )
{
}

