// $Id$
#include "cdp.hpp"

namespace CIAO
{
  namespace Config_Handlers
  {
    // DeploymentPlan
    // 

    DeploymentPlan::
    DeploymentPlan (::CIAO::Config_Handlers::ComponentInterfaceDescription const& realizes__,
    ::CIAO::Config_Handlers::MonolithicDeploymentDescription const& implementation__)
    :
    realizes_ (new ::CIAO::Config_Handlers::ComponentInterfaceDescription (realizes__)),
    implementation_ (new ::CIAO::Config_Handlers::MonolithicDeploymentDescription (implementation__)),
    regulator__ ()
    {
      realizes_->container (this);
      implementation_->container (this);
    }

    DeploymentPlan::
    DeploymentPlan (::CIAO::Config_Handlers::DeploymentPlan const& s)
    :
    label_ (s.label_.get () ? new ::XMLSchema::string< char > (*s.label_) : 0),
    UUID_ (s.UUID_.get () ? new ::XMLSchema::string< char > (*s.UUID_) : 0),
    realizes_ (new ::CIAO::Config_Handlers::ComponentInterfaceDescription (*s.realizes_)),
    implementation_ (new ::CIAO::Config_Handlers::MonolithicDeploymentDescription (*s.implementation_)),
    regulator__ ()
    {
      if (label_.get ()) label_->container (this);
      if (UUID_.get ()) UUID_->container (this);
      realizes_->container (this);
      implementation_->container (this);
      instance_.reserve (s.instance_.size ());
      {
        for (instance_const_iterator i (s.instance_.begin ());
        i != s.instance_.end ();
        ++i) add_instance (*i);
      }

      connection_.reserve (s.connection_.size ());
      {
        for (connection_const_iterator i (s.connection_.begin ());
        i != s.connection_.end ();
        ++i) add_connection (*i);
      }

      dependsOn_.reserve (s.dependsOn_.size ());
      {
        for (dependsOn_const_iterator i (s.dependsOn_.begin ());
        i != s.dependsOn_.end ();
        ++i) add_dependsOn (*i);
      }

      artifact_.reserve (s.artifact_.size ());
      {
        for (artifact_const_iterator i (s.artifact_.begin ());
        i != s.artifact_.end ();
        ++i) add_artifact (*i);
      }

      infoProperty_.reserve (s.infoProperty_.size ());
      {
        for (infoProperty_const_iterator i (s.infoProperty_.begin ());
        i != s.infoProperty_.end ();
        ++i) add_infoProperty (*i);
      }
    }

    ::CIAO::Config_Handlers::DeploymentPlan& DeploymentPlan::
    operator= (::CIAO::Config_Handlers::DeploymentPlan const& s)
    {
      if (s.label_.get ()) label (*(s.label_));
      else label_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      if (s.UUID_.get ()) UUID (*(s.UUID_));
      else UUID_ = ::std::auto_ptr< ::XMLSchema::string< char > > (0);

      realizes (s.realizes ());

      implementation (s.implementation ());

      instance_.clear ();
      instance_.reserve (s.instance_.size ());
      {
        for (instance_const_iterator i (s.instance_.begin ());
        i != s.instance_.end ();
        ++i) add_instance (*i);
      }

      connection_.clear ();
      connection_.reserve (s.connection_.size ());
      {
        for (connection_const_iterator i (s.connection_.begin ());
        i != s.connection_.end ();
        ++i) add_connection (*i);
      }

      dependsOn_.clear ();
      dependsOn_.reserve (s.dependsOn_.size ());
      {
        for (dependsOn_const_iterator i (s.dependsOn_.begin ());
        i != s.dependsOn_.end ();
        ++i) add_dependsOn (*i);
      }

      artifact_.clear ();
      artifact_.reserve (s.artifact_.size ());
      {
        for (artifact_const_iterator i (s.artifact_.begin ());
        i != s.artifact_.end ();
        ++i) add_artifact (*i);
      }

      infoProperty_.clear ();
      infoProperty_.reserve (s.infoProperty_.size ());
      {
        for (infoProperty_const_iterator i (s.infoProperty_.begin ());
        i != s.infoProperty_.end ();
        ++i) add_infoProperty (*i);
      }

      return *this;
    }


    // DeploymentPlan
    // 
    bool DeploymentPlan::
    label_p () const
    {
      return label_.get () != 0;
    }

    ::XMLSchema::string< char > const& DeploymentPlan::
    label () const
    {
      return *label_;
    }

    ::XMLSchema::string< char >& DeploymentPlan::
    label ()
    {
      return *label_;
    }

    void DeploymentPlan::
    label (::XMLSchema::string< char > const& e)
    {
      if (label_.get ())
      {
        *label_ = e;
      }

      else
      {
        label_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
        label_->container (this);
      }
    }

    // DeploymentPlan
    // 
    bool DeploymentPlan::
    UUID_p () const
    {
      return UUID_.get () != 0;
    }

    ::XMLSchema::string< char > const& DeploymentPlan::
    UUID () const
    {
      return *UUID_;
    }

    ::XMLSchema::string< char >& DeploymentPlan::
    UUID ()
    {
      return *UUID_;
    }

    void DeploymentPlan::
    UUID (::XMLSchema::string< char > const& e)
    {
      if (UUID_.get ())
      {
        *UUID_ = e;
      }

      else
      {
        UUID_ = ::std::auto_ptr< ::XMLSchema::string< char > > (new ::XMLSchema::string< char > (e));
        UUID_->container (this);
      }
    }

    // DeploymentPlan
    // 
    ::CIAO::Config_Handlers::ComponentInterfaceDescription const& DeploymentPlan::
    realizes () const
    {
      return *realizes_;
    }

    ::CIAO::Config_Handlers::ComponentInterfaceDescription& DeploymentPlan::
    realizes ()
    {
      return *realizes_;
    }

    void DeploymentPlan::
    realizes (::CIAO::Config_Handlers::ComponentInterfaceDescription const& e)
    {
      *realizes_ = e;
    }

    // DeploymentPlan
    // 
    ::CIAO::Config_Handlers::MonolithicDeploymentDescription const& DeploymentPlan::
    implementation () const
    {
      return *implementation_;
    }

    ::CIAO::Config_Handlers::MonolithicDeploymentDescription& DeploymentPlan::
    implementation ()
    {
      return *implementation_;
    }

    void DeploymentPlan::
    implementation (::CIAO::Config_Handlers::MonolithicDeploymentDescription const& e)
    {
      *implementation_ = e;
    }

    // DeploymentPlan
    // 
    DeploymentPlan::instance_iterator DeploymentPlan::
    begin_instance ()
    {
      return instance_.begin ();
    }

    DeploymentPlan::instance_iterator DeploymentPlan::
    end_instance ()
    {
      return instance_.end ();
    }

    DeploymentPlan::instance_const_iterator DeploymentPlan::
    begin_instance () const
    {
      return instance_.begin ();
    }

    DeploymentPlan::instance_const_iterator DeploymentPlan::
    end_instance () const
    {
      return instance_.end ();
    }

    void DeploymentPlan::
    add_instance (::CIAO::Config_Handlers::InstanceDeploymentDescription const& e)
    {
      if (instance_.capacity () < instance_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::InstanceDeploymentDescription > v;
        v.reserve (instance_.size () + 1);

        while (instance_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::InstanceDeploymentDescription& t = instance_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          instance_.pop_back ();
        }

        instance_.swap (v);
      }

      instance_.push_back (e);
      instance_.back ().container (this);
    }

    // DeploymentPlan
    // 
    DeploymentPlan::connection_iterator DeploymentPlan::
    begin_connection ()
    {
      return connection_.begin ();
    }

    DeploymentPlan::connection_iterator DeploymentPlan::
    end_connection ()
    {
      return connection_.end ();
    }

    DeploymentPlan::connection_const_iterator DeploymentPlan::
    begin_connection () const
    {
      return connection_.begin ();
    }

    DeploymentPlan::connection_const_iterator DeploymentPlan::
    end_connection () const
    {
      return connection_.end ();
    }

    void DeploymentPlan::
    add_connection (::CIAO::Config_Handlers::PlanConnectionDescription const& e)
    {
      if (connection_.capacity () < connection_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::PlanConnectionDescription > v;
        v.reserve (connection_.size () + 1);

        while (connection_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::PlanConnectionDescription& t = connection_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          connection_.pop_back ();
        }

        connection_.swap (v);
      }

      connection_.push_back (e);
      connection_.back ().container (this);
    }

    // DeploymentPlan
    // 
    DeploymentPlan::dependsOn_iterator DeploymentPlan::
    begin_dependsOn ()
    {
      return dependsOn_.begin ();
    }

    DeploymentPlan::dependsOn_iterator DeploymentPlan::
    end_dependsOn ()
    {
      return dependsOn_.end ();
    }

    DeploymentPlan::dependsOn_const_iterator DeploymentPlan::
    begin_dependsOn () const
    {
      return dependsOn_.begin ();
    }

    DeploymentPlan::dependsOn_const_iterator DeploymentPlan::
    end_dependsOn () const
    {
      return dependsOn_.end ();
    }

    void DeploymentPlan::
    add_dependsOn (::CIAO::Config_Handlers::ImplementationDependency const& e)
    {
      if (dependsOn_.capacity () < dependsOn_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::ImplementationDependency > v;
        v.reserve (dependsOn_.size () + 1);

        while (dependsOn_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::ImplementationDependency& t = dependsOn_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          dependsOn_.pop_back ();
        }

        dependsOn_.swap (v);
      }

      dependsOn_.push_back (e);
      dependsOn_.back ().container (this);
    }

    // DeploymentPlan
    // 
    DeploymentPlan::artifact_iterator DeploymentPlan::
    begin_artifact ()
    {
      return artifact_.begin ();
    }

    DeploymentPlan::artifact_iterator DeploymentPlan::
    end_artifact ()
    {
      return artifact_.end ();
    }

    DeploymentPlan::artifact_const_iterator DeploymentPlan::
    begin_artifact () const
    {
      return artifact_.begin ();
    }

    DeploymentPlan::artifact_const_iterator DeploymentPlan::
    end_artifact () const
    {
      return artifact_.end ();
    }

    void DeploymentPlan::
    add_artifact (::CIAO::Config_Handlers::ArtifactDeploymentDescription const& e)
    {
      if (artifact_.capacity () < artifact_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::ArtifactDeploymentDescription > v;
        v.reserve (artifact_.size () + 1);

        while (artifact_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::ArtifactDeploymentDescription& t = artifact_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          artifact_.pop_back ();
        }

        artifact_.swap (v);
      }

      artifact_.push_back (e);
      artifact_.back ().container (this);
    }

    // DeploymentPlan
    // 
    DeploymentPlan::infoProperty_iterator DeploymentPlan::
    begin_infoProperty ()
    {
      return infoProperty_.begin ();
    }

    DeploymentPlan::infoProperty_iterator DeploymentPlan::
    end_infoProperty ()
    {
      return infoProperty_.end ();
    }

    DeploymentPlan::infoProperty_const_iterator DeploymentPlan::
    begin_infoProperty () const
    {
      return infoProperty_.begin ();
    }

    DeploymentPlan::infoProperty_const_iterator DeploymentPlan::
    end_infoProperty () const
    {
      return infoProperty_.end ();
    }

    void DeploymentPlan::
    add_infoProperty (::CIAO::Config_Handlers::Property const& e)
    {
      if (infoProperty_.capacity () < infoProperty_.size () + 1)
      {
        ::std::vector< ::CIAO::Config_Handlers::Property > v;
        v.reserve (infoProperty_.size () + 1);

        while (infoProperty_.size ())
        {
          //@@ VC6
          ::CIAO::Config_Handlers::Property& t = infoProperty_.back ();
          t.container (0);
          v.push_back (t);
          v.back ().container (this);
          infoProperty_.pop_back ();
        }

        infoProperty_.swap (v);
      }

      infoProperty_.push_back (e);
      infoProperty_.back ().container (this);
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    // DeploymentPlan
    //

    DeploymentPlan::
    DeploymentPlan (::XSCRT::XML::Element< char > const& e)
    :Base__ (e), regulator__ ()
    {

      ::XSCRT::Parser< char > p (e);

      while (p.more_elements ())
      {
        ::XSCRT::XML::Element< char > e (p.next_element ());
        ::std::basic_string< char > n (::XSCRT::XML::uq_name (e.name ()));

        if (n == "label")
        {
          ::XMLSchema::string< char > t (e);
          label (t);
        }

        else if (n == "UUID")
        {
          ::XMLSchema::string< char > t (e);
          UUID (t);
        }

        else if (n == "realizes")
        {
          realizes_ = ::std::auto_ptr< ::CIAO::Config_Handlers::ComponentInterfaceDescription > (new ::CIAO::Config_Handlers::ComponentInterfaceDescription (e));
          realizes_->container (this);
        }

        else if (n == "implementation")
        {
          implementation_ = ::std::auto_ptr< ::CIAO::Config_Handlers::MonolithicDeploymentDescription > (new ::CIAO::Config_Handlers::MonolithicDeploymentDescription (e));
          implementation_->container (this);
        }

        else if (n == "instance")
        {
          ::CIAO::Config_Handlers::InstanceDeploymentDescription t (e);
          add_instance (t);
        }

        else if (n == "connection")
        {
          ::CIAO::Config_Handlers::PlanConnectionDescription t (e);
          add_connection (t);
        }

        else if (n == "dependsOn")
        {
          ::CIAO::Config_Handlers::ImplementationDependency t (e);
          add_dependsOn (t);
        }

        else if (n == "artifact")
        {
          ::CIAO::Config_Handlers::ArtifactDeploymentDescription t (e);
          add_artifact (t);
        }

        else if (n == "infoProperty")
        {
          ::CIAO::Config_Handlers::Property t (e);
          add_infoProperty (t);
        }

        else 
        {
        }
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

#include <XSCRT/ExtendedTypeInfo.hpp>

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace
    {
      ::XMLSchema::TypeInfoInitializer < char > XMLSchemaTypeInfoInitializer_ (::XSCRT::extended_type_info_map ());

      struct DeploymentPlanTypeInfoInitializer
      {
        DeploymentPlanTypeInfoInitializer ()
        {
          ::XSCRT::TypeId id (typeid (DeploymentPlan));
          ::XSCRT::ExtendedTypeInfo nf (id);

          nf.add_base (::XSCRT::ExtendedTypeInfo::Access::public_, false, typeid (::XSCRT::Type));
          ::XSCRT::extended_type_info_map ().insert (::std::make_pair (id, nf));
        }
      };

      DeploymentPlanTypeInfoInitializer DeploymentPlanTypeInfoInitializer_;
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Traversal
    {
      // DeploymentPlan
      //
      //

      void DeploymentPlan::
      traverse (Type& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        realizes (o);
        implementation (o);
        instance (o);
        connection (o);
        dependsOn (o);
        artifact (o);
        infoProperty (o);
        post (o);
      }

      void DeploymentPlan::
      traverse (Type const& o)
      {
        pre (o);
        if (o.label_p ()) label (o);
        else label_none (o);
        if (o.UUID_p ()) UUID (o);
        else UUID_none (o);
        realizes (o);
        implementation (o);
        instance (o);
        connection (o);
        dependsOn (o);
        artifact (o);
        infoProperty (o);
        post (o);
      }

      void DeploymentPlan::
      pre (Type&)
      {
      }

      void DeploymentPlan::
      pre (Type const&)
      {
      }

      void DeploymentPlan::
      label (Type& o)
      {
        dispatch (o.label ());
      }

      void DeploymentPlan::
      label (Type const& o)
      {
        dispatch (o.label ());
      }

      void DeploymentPlan::
      label_none (Type&)
      {
      }

      void DeploymentPlan::
      label_none (Type const&)
      {
      }

      void DeploymentPlan::
      UUID (Type& o)
      {
        dispatch (o.UUID ());
      }

      void DeploymentPlan::
      UUID (Type const& o)
      {
        dispatch (o.UUID ());
      }

      void DeploymentPlan::
      UUID_none (Type&)
      {
      }

      void DeploymentPlan::
      UUID_none (Type const&)
      {
      }

      void DeploymentPlan::
      realizes (Type& o)
      {
        dispatch (o.realizes ());
      }

      void DeploymentPlan::
      realizes (Type const& o)
      {
        dispatch (o.realizes ());
      }

      void DeploymentPlan::
      implementation (Type& o)
      {
        dispatch (o.implementation ());
      }

      void DeploymentPlan::
      implementation (Type const& o)
      {
        dispatch (o.implementation ());
      }

      void DeploymentPlan::
      instance (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::instance_iterator b (o.begin_instance()), e (o.end_instance());

        if (b != e)
        {
          instance_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) instance_next (o);
          }

          instance_post (o);
        }

        else instance_none (o);
      }

      void DeploymentPlan::
      instance (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::instance_const_iterator b (o.begin_instance()), e (o.end_instance());

        if (b != e)
        {
          instance_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) instance_next (o);
          }

          instance_post (o);
        }

        else instance_none (o);
      }

      void DeploymentPlan::
      instance_pre (Type&)
      {
      }

      void DeploymentPlan::
      instance_pre (Type const&)
      {
      }

      void DeploymentPlan::
      instance_next (Type&)
      {
      }

      void DeploymentPlan::
      instance_next (Type const&)
      {
      }

      void DeploymentPlan::
      instance_post (Type&)
      {
      }

      void DeploymentPlan::
      instance_post (Type const&)
      {
      }

      void DeploymentPlan::
      instance_none (Type&)
      {
      }

      void DeploymentPlan::
      instance_none (Type const&)
      {
      }

      void DeploymentPlan::
      connection (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::connection_iterator b (o.begin_connection()), e (o.end_connection());

        if (b != e)
        {
          connection_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) connection_next (o);
          }

          connection_post (o);
        }

        else connection_none (o);
      }

      void DeploymentPlan::
      connection (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::connection_const_iterator b (o.begin_connection()), e (o.end_connection());

        if (b != e)
        {
          connection_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) connection_next (o);
          }

          connection_post (o);
        }

        else connection_none (o);
      }

      void DeploymentPlan::
      connection_pre (Type&)
      {
      }

      void DeploymentPlan::
      connection_pre (Type const&)
      {
      }

      void DeploymentPlan::
      connection_next (Type&)
      {
      }

      void DeploymentPlan::
      connection_next (Type const&)
      {
      }

      void DeploymentPlan::
      connection_post (Type&)
      {
      }

      void DeploymentPlan::
      connection_post (Type const&)
      {
      }

      void DeploymentPlan::
      connection_none (Type&)
      {
      }

      void DeploymentPlan::
      connection_none (Type const&)
      {
      }

      void DeploymentPlan::
      dependsOn (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::dependsOn_iterator b (o.begin_dependsOn()), e (o.end_dependsOn());

        if (b != e)
        {
          dependsOn_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) dependsOn_next (o);
          }

          dependsOn_post (o);
        }

        else dependsOn_none (o);
      }

      void DeploymentPlan::
      dependsOn (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::dependsOn_const_iterator b (o.begin_dependsOn()), e (o.end_dependsOn());

        if (b != e)
        {
          dependsOn_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) dependsOn_next (o);
          }

          dependsOn_post (o);
        }

        else dependsOn_none (o);
      }

      void DeploymentPlan::
      dependsOn_pre (Type&)
      {
      }

      void DeploymentPlan::
      dependsOn_pre (Type const&)
      {
      }

      void DeploymentPlan::
      dependsOn_next (Type&)
      {
      }

      void DeploymentPlan::
      dependsOn_next (Type const&)
      {
      }

      void DeploymentPlan::
      dependsOn_post (Type&)
      {
      }

      void DeploymentPlan::
      dependsOn_post (Type const&)
      {
      }

      void DeploymentPlan::
      dependsOn_none (Type&)
      {
      }

      void DeploymentPlan::
      dependsOn_none (Type const&)
      {
      }

      void DeploymentPlan::
      artifact (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::artifact_iterator b (o.begin_artifact()), e (o.end_artifact());

        if (b != e)
        {
          artifact_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) artifact_next (o);
          }

          artifact_post (o);
        }

        else artifact_none (o);
      }

      void DeploymentPlan::
      artifact (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::artifact_const_iterator b (o.begin_artifact()), e (o.end_artifact());

        if (b != e)
        {
          artifact_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) artifact_next (o);
          }

          artifact_post (o);
        }

        else artifact_none (o);
      }

      void DeploymentPlan::
      artifact_pre (Type&)
      {
      }

      void DeploymentPlan::
      artifact_pre (Type const&)
      {
      }

      void DeploymentPlan::
      artifact_next (Type&)
      {
      }

      void DeploymentPlan::
      artifact_next (Type const&)
      {
      }

      void DeploymentPlan::
      artifact_post (Type&)
      {
      }

      void DeploymentPlan::
      artifact_post (Type const&)
      {
      }

      void DeploymentPlan::
      artifact_none (Type&)
      {
      }

      void DeploymentPlan::
      artifact_none (Type const&)
      {
      }

      void DeploymentPlan::
      infoProperty (Type& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::infoProperty_iterator b (o.begin_infoProperty()), e (o.end_infoProperty());

        if (b != e)
        {
          infoProperty_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) infoProperty_next (o);
          }

          infoProperty_post (o);
        }

        else infoProperty_none (o);
      }

      void DeploymentPlan::
      infoProperty (Type const& o)
      {
        // VC6 anathema strikes again
        //
        DeploymentPlan::Type::infoProperty_const_iterator b (o.begin_infoProperty()), e (o.end_infoProperty());

        if (b != e)
        {
          infoProperty_pre (o);
          for (;
           b != e;
          )
          {
            dispatch (*b);
            if (++b != e) infoProperty_next (o);
          }

          infoProperty_post (o);
        }

        else infoProperty_none (o);
      }

      void DeploymentPlan::
      infoProperty_pre (Type&)
      {
      }

      void DeploymentPlan::
      infoProperty_pre (Type const&)
      {
      }

      void DeploymentPlan::
      infoProperty_next (Type&)
      {
      }

      void DeploymentPlan::
      infoProperty_next (Type const&)
      {
      }

      void DeploymentPlan::
      infoProperty_post (Type&)
      {
      }

      void DeploymentPlan::
      infoProperty_post (Type const&)
      {
      }

      void DeploymentPlan::
      infoProperty_none (Type&)
      {
      }

      void DeploymentPlan::
      infoProperty_none (Type const&)
      {
      }

      void DeploymentPlan::
      post (Type&)
      {
      }

      void DeploymentPlan::
      post (Type const&)
      {
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
    namespace Writer
    {
      // DeploymentPlan
      //
      //

      DeploymentPlan::
      DeploymentPlan (::XSCRT::XML::Element< char >& e)
      : ::XSCRT::Writer< char > (e)
      {
      }

      DeploymentPlan::
      DeploymentPlan ()
      {
      }

      void DeploymentPlan::
      traverse (Type const& o)
      {
        Traversal::DeploymentPlan::traverse (o);
      }

      void DeploymentPlan::
      label (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("label", top_ ()));
        Traversal::DeploymentPlan::label (o);
        pop_ ();
      }

      void DeploymentPlan::
      UUID (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("UUID", top_ ()));
        Traversal::DeploymentPlan::UUID (o);
        pop_ ();
      }

      void DeploymentPlan::
      realizes (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("realizes", top_ ()));
        Traversal::DeploymentPlan::realizes (o);
        pop_ ();
      }

      void DeploymentPlan::
      implementation (Type const& o)
      {
        push_ (::XSCRT::XML::Element< char > ("implementation", top_ ()));
        Traversal::DeploymentPlan::implementation (o);
        pop_ ();
      }

      void DeploymentPlan::
      instance_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< char > ("instance", top_ ()));
      }

      void DeploymentPlan::
      instance_next (Type const& o)
      {
        instance_post (o);
        instance_pre (o);
      }

      void DeploymentPlan::
      instance_post (Type const&)
      {
        pop_ ();
      }

      void DeploymentPlan::
      connection_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< char > ("connection", top_ ()));
      }

      void DeploymentPlan::
      connection_next (Type const& o)
      {
        connection_post (o);
        connection_pre (o);
      }

      void DeploymentPlan::
      connection_post (Type const&)
      {
        pop_ ();
      }

      void DeploymentPlan::
      dependsOn_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< char > ("dependsOn", top_ ()));
      }

      void DeploymentPlan::
      dependsOn_next (Type const& o)
      {
        dependsOn_post (o);
        dependsOn_pre (o);
      }

      void DeploymentPlan::
      dependsOn_post (Type const&)
      {
        pop_ ();
      }

      void DeploymentPlan::
      artifact_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< char > ("artifact", top_ ()));
      }

      void DeploymentPlan::
      artifact_next (Type const& o)
      {
        artifact_post (o);
        artifact_pre (o);
      }

      void DeploymentPlan::
      artifact_post (Type const&)
      {
        pop_ ();
      }

      void DeploymentPlan::
      infoProperty_pre (Type const&)
      {
        push_ (::XSCRT::XML::Element< char > ("infoProperty", top_ ()));
      }

      void DeploymentPlan::
      infoProperty_next (Type const& o)
      {
        infoProperty_post (o);
        infoProperty_pre (o);
      }

      void DeploymentPlan::
      infoProperty_post (Type const&)
      {
        pop_ ();
      }
    }
  }
}

namespace CIAO
{
  namespace Config_Handlers
  {
  }
}

