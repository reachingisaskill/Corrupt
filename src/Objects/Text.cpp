
#include "Objects/Text.h"


namespace Corrupt
{

  ObjectText::ObjectText() :
    Regolith::DrawableObject(),
    _texture()
  {
  }


  ObjectText::~ObjectText()
  {
  }


  void ObjectText::configure( Json::Value& json_data, Regolith::ContextGroup& cg )
  {
    Regolith::PhysicalObject::configure( json_data, cg );

    _texture.configure( json_data, cg.getDataHandler() );

    this->setWidth( _texture.getWidth() );
    this->setHeight( _texture.getHeight() );
  }

}

