
#include "Objects/Image.h"


namespace Corrupt
{

  ObjectImage::ObjectImage() :
    Regolith::DrawableObject(),
    _texture()
  {
  }


  ObjectImage::~ObjectImage()
  {
  }


  void ObjectImage::configure( Json::Value& json_data, Regolith::ContextGroup& cg )
  {
    Regolith::PhysicalObject::configure( json_data, cg );

    _texture.configure( json_data, cg.getDataHandler() );
  }

}

