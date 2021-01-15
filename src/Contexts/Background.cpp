
#include "Contexts/Background.h"

#include "Regolith/Utilities/JsonValidation.h"


namespace Corrupt
{

  ContextBackground::ContextBackground() :
    _onLoadContext()
  {
  }


  ContextBackground::~ContextBackground()
  {
  }


  void ContextBackground::configure( Json::Value& json_data, Regolith::ContextGroup& cg )
  {
    // Configure the base class first
    Context::configure( json_data, cg );

    // Background context specific configuration
    Regolith::validateJson( json_data, "on_load", Regolith::JsonType::OBJECT );
    _onLoadContext.configure( json_data["on_load"], cg );
  }


  void ContextBackground::onStart()
  {
    // Context can't do anything when it gains focus, so just close
    this->setClosed( true );
    _onLoadContext.trigger();
  }


  void ContextBackground::onStop()
  {
    this->setClosed( true );
  }

}

