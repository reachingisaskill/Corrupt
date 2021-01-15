
#ifndef CORRUPT_OBJECTS_IMAGE_H_
#define CORRUPT_OBJECTS_IMAGE_H_

#include "Regolith.h"
#include "Regolith/Textures/Spritesheet.h"


namespace Corrupt
{

  class ObjectImage : public Regolith::DrawableObject
  {
    private:
      Regolith::Spritesheet _texture;

    public:
      ObjectImage();

      virtual ~ObjectImage();


      // Clone this class
      virtual Regolith::PhysicalObject* clone() const { return (Regolith::PhysicalObject*) new ObjectImage( *this ); }


      // Perform the basic configuration
      void configure( Json::Value&, Regolith::ContextGroup& ) override;


      // For the camera to request the current renderable texture
      virtual Regolith::Texture& getTexture() { return _texture; }

  };

}

#endif // CORRUPT_OBJECTS_IMAGE_H_

