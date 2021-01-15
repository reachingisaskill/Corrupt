
#include "Regolith.h"

//#ifdef LOGTASTIC_DEBUG_OFF
//#undef LOGTASTIC_DEBUG_OFF
//#endif

#include "Corrupt.h"

#include "Contexts/LoadScreen.h"
#include "Contexts/Background.h"
#include "Contexts/Menu.h"

#include "Objects/Text.h"
#include "Objects/Image.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
// Forward declarations

// Global entry point
int start();


////////////////////////////////////////////////////////////////////////////////////////////////////
// Figure out and define what the entry point is depending on the platform definitions

// Windows specific entry point (thanks windows....)
#if defined _WIN32

#include <windows.h>

int WINAPI WinMain( HINSTANCE /*instance*/, HINSTANCE /*prevInstance*/, LPSTR /*lpszArg*/, int /*show*/ )
{
  return start();
}

//#elif defined __linux__
#else

// Standard entry point for every other platform.
int main( int /*n_args*/, char** /*args*/ )
{
  return start();
}

#endif 

////////////////////////////////////////////////////////////////////////////////////////////////////
// Start the game

int start()
{
  logtastic::init();
  logtastic::setLogFileDirectory( "./logs/" );
  logtastic::addLogFile( "Corrupt.log" );

  INFO_LOG( "Initialising the manager" );
  Regolith::Manager* man = Regolith::Manager::createInstance();
  logtastic::start( "Natus Novum - A new born.", CORRUPT_VERSION );

  try
  {
    INFO_LOG( "Creating custom object builders" );
    Regolith::ObjectFactory& object_factory = man->getObjectFactory();
    object_factory.addBuilder< Corrupt::ObjectText >( "text" );
    object_factory.addBuilder< Corrupt::ObjectImage >( "image" );

    INFO_LOG( "Creating custom context builders" );
    Regolith::ContextFactory& context_factory = man->getContextFactory();
    context_factory.addBuilder< Corrupt::ContextLoadScreen >( "load_screen" );
    context_factory.addBuilder< Corrupt::ContextBackground >( "background" );
    context_factory.addBuilder< Corrupt::ContextMenu >( "menu" );

    INFO_LOG( "Initialising the manager" );
    man->init( CORRUPT_CONFIGURATION_FILE );

    INFO_LOG( "Starting Natus Novum" );
    man->run();

  }
  catch ( Regolith::Exception& ex )
  {
    FAILURE_LOG( ex.what() );
    std::cerr << ex.elucidate();
  }
  catch ( std::exception& ex )
  {
    FAILURE_LOG( "Unexpected exception occured:" );
    FAILURE_STREAM << ex.what();
  }

  Regolith::Manager::killInstance();
  logtastic::stop();
  return 0;
}

