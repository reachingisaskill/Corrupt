
#include "Contexts/LoadScreen.h"


namespace Corrupt
{

  ContextLoadScreen::ContextLoadScreen()
  {
  }


  ContextLoadScreen::~ContextLoadScreen()
  {
  }

  void ContextLoadScreen::onStart()
  {
    this->setClosed( false );
  }


  void ContextLoadScreen::onStop()
  {
    this->setClosed( true );
  }


  void ContextLoadScreen::configure( Json::Value& json_data, Regolith::ContextGroup& cg )
  {
    Regolith::Context::configure( json_data, cg );
  }


  void ContextLoadScreen::updateContext( float /*time*/ )
  {
  }

}

