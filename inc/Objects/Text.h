
#ifndef CORRUPT_OBJECTS_TEXT_H_
#define CORRUPT_OBJECTS_TEXT_H_

#include "Regolith.h"
#include "Regolith/Textures/ShortText.h"


namespace Corrupt
{

  class ObjectText : public Regolith::DrawableObject
  {
    private:
      Regolith::ShortText _texture;

    public:
      ObjectText();

      virtual ~ObjectText();


      // Clone this class
      virtual Regolith::PhysicalObject* clone() const { return (Regolith::PhysicalObject*) new ObjectText( *this ); }


      // Perform the basic configuration
      void configure( Json::Value&, Regolith::ContextGroup& ) override;


      // For the camera to request the current renderable texture
      virtual Regolith::Texture& getTexture() { return _texture; }

  };

}

#endif // CORRUPT_OBJECTS_TEXT_H_

