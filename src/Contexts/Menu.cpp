
#include "Contexts/Menu.h"


namespace Corrupt
{

  ContextMenu::ContextMenu()
  {
  }


  ContextMenu::~ContextMenu()
  {
  }


  void ContextMenu::onStart()
  {
    this->setClosed( false );
  }


  void ContextMenu::onStop()
  {
    this->setClosed( true );
  }


  void ContextMenu::configure( Json::Value& json_data, Regolith::ContextGroup& cg )
  {
    // Configure the base class first
    Regolith::Context::configure( json_data, cg );

    // Menu context specific configuration
  }

}

