// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/CommsMessage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__COMMS_MESSAGE__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__COMMS_MESSAGE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__CommsMessage __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__CommsMessage __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CommsMessage_
{
  using Type = CommsMessage_<ContainerAllocator>;

  explicit CommsMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->floater_id = 0;
      this->concentration = 0ul;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->altitude = 0.0;
    }
  }

  explicit CommsMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->floater_id = 0;
      this->concentration = 0ul;
      this->latitude = 0.0;
      this->longitude = 0.0;
      this->altitude = 0.0;
    }
  }

  // field types and members
  using _floater_id_type =
    uint16_t;
  _floater_id_type floater_id;
  using _concentration_type =
    uint32_t;
  _concentration_type concentration;
  using _latitude_type =
    double;
  _latitude_type latitude;
  using _longitude_type =
    double;
  _longitude_type longitude;
  using _altitude_type =
    double;
  _altitude_type altitude;

  // setters for named parameter idiom
  Type & set__floater_id(
    const uint16_t & _arg)
  {
    this->floater_id = _arg;
    return *this;
  }
  Type & set__concentration(
    const uint32_t & _arg)
  {
    this->concentration = _arg;
    return *this;
  }
  Type & set__latitude(
    const double & _arg)
  {
    this->latitude = _arg;
    return *this;
  }
  Type & set__longitude(
    const double & _arg)
  {
    this->longitude = _arg;
    return *this;
  }
  Type & set__altitude(
    const double & _arg)
  {
    this->altitude = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::CommsMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::CommsMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::CommsMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::CommsMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::CommsMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::CommsMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::CommsMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::CommsMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::CommsMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::CommsMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__CommsMessage
    std::shared_ptr<custom_msgs::msg::CommsMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__CommsMessage
    std::shared_ptr<custom_msgs::msg::CommsMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CommsMessage_ & other) const
  {
    if (this->floater_id != other.floater_id) {
      return false;
    }
    if (this->concentration != other.concentration) {
      return false;
    }
    if (this->latitude != other.latitude) {
      return false;
    }
    if (this->longitude != other.longitude) {
      return false;
    }
    if (this->altitude != other.altitude) {
      return false;
    }
    return true;
  }
  bool operator!=(const CommsMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CommsMessage_

// alias to use template instance with default allocator
using CommsMessage =
  custom_msgs::msg::CommsMessage_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__COMMS_MESSAGE__STRUCT_HPP_
