// Generated by gencpp from file my_service/WheelRequest.msg
// DO NOT EDIT!


#ifndef MY_SERVICE_MESSAGE_WHEELREQUEST_H
#define MY_SERVICE_MESSAGE_WHEELREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace my_service
{
template <class ContainerAllocator>
struct WheelRequest_
{
  typedef WheelRequest_<ContainerAllocator> Type;

  WheelRequest_()
    : target_linear_velocity(0.0)
    , target_angular_velocity(0.0)  {
    }
  WheelRequest_(const ContainerAllocator& _alloc)
    : target_linear_velocity(0.0)
    , target_angular_velocity(0.0)  {
  (void)_alloc;
    }



   typedef double _target_linear_velocity_type;
  _target_linear_velocity_type target_linear_velocity;

   typedef double _target_angular_velocity_type;
  _target_angular_velocity_type target_angular_velocity;




  typedef boost::shared_ptr< ::my_service::WheelRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::my_service::WheelRequest_<ContainerAllocator> const> ConstPtr;

}; // struct WheelRequest_

typedef ::my_service::WheelRequest_<std::allocator<void> > WheelRequest;

typedef boost::shared_ptr< ::my_service::WheelRequest > WheelRequestPtr;
typedef boost::shared_ptr< ::my_service::WheelRequest const> WheelRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::my_service::WheelRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::my_service::WheelRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace my_service

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::my_service::WheelRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::my_service::WheelRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_service::WheelRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::my_service::WheelRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_service::WheelRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::my_service::WheelRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::my_service::WheelRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f0250a22f26b2d4fb70fdb58e85f8b9a";
  }

  static const char* value(const ::my_service::WheelRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf0250a22f26b2d4fULL;
  static const uint64_t static_value2 = 0xb70fdb58e85f8b9aULL;
};

template<class ContainerAllocator>
struct DataType< ::my_service::WheelRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "my_service/WheelRequest";
  }

  static const char* value(const ::my_service::WheelRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::my_service::WheelRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 target_linear_velocity\n\
float64 target_angular_velocity\n\
";
  }

  static const char* value(const ::my_service::WheelRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::my_service::WheelRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.target_linear_velocity);
      stream.next(m.target_angular_velocity);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WheelRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::my_service::WheelRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::my_service::WheelRequest_<ContainerAllocator>& v)
  {
    s << indent << "target_linear_velocity: ";
    Printer<double>::stream(s, indent + "  ", v.target_linear_velocity);
    s << indent << "target_angular_velocity: ";
    Printer<double>::stream(s, indent + "  ", v.target_angular_velocity);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MY_SERVICE_MESSAGE_WHEELREQUEST_H
