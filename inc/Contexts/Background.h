
#ifndef CORRUPT_CONTEXTS_BACKGROUND_H_
#define CORRUPT_CONTEXTS_BACKGROUND_H_

#include "Regolith.h"


namespace Corrupt
{

  class ContextBackground : public Regolith::Context
  {
    private:
      Regolith::OpenContextSignal _onLoadContext;

    protected:
      // Hooks for context state changes
      virtual void onStart() override;
      virtual void onStop() override;
  //    virtual void onPause() override {}
  //    virtual void onResume() override {}

      // Called during the update loop for frame-dependent context actions
      virtual void updateContext( float ) override {}

      // Called after the physics processes to update the current position that the camera renders from
      virtual Regolith::Vector updateCamera( float ) const { return Regolith::Vector( 0.0, 0.0 ); }

      // Called for each object that is flagged to have global physics
      virtual void updatePhysics( Regolith::PhysicalObject*, float ) const override {}

      // Rendering operations specific to the context
      virtual void renderContext( Regolith::Camera& ) override {}

    public:

      ContextBackground();

      virtual ~ContextBackground();


      // Configure the background type context
      void configure( Json::Value&, Regolith::ContextGroup& ) override;


      // This context overrides previous ones on the context stack
      virtual bool overridesPreviousContext() const override { return true; }
  };

}

#endif // CORRUPT_CONTEXTS_BACKGROUND_H_

