// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msgs:msg/CountWithFloaterInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__COUNT_WITH_FLOATER_INFO__STRUCT_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__COUNT_WITH_FLOATER_INFO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_msgs__msg__CountWithFloaterInfo __attribute__((deprecated))
#else
# define DEPRECATED__custom_msgs__msg__CountWithFloaterInfo __declspec(deprecated)
#endif

namespace custom_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CountWithFloaterInfo_
{
  using Type = CountWithFloaterInfo_<ContainerAllocator>;

  explicit CountWithFloaterInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->floater_info = "";
      this->larvae_count = 0;
    }
  }

  explicit CountWithFloaterInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : floater_info(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->floater_info = "";
      this->larvae_count = 0;
    }
  }

  // field types and members
  using _floater_info_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _floater_info_type floater_info;
  using _larvae_count_type =
    uint16_t;
  _larvae_count_type larvae_count;

  // setters for named parameter idiom
  Type & set__floater_info(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->floater_info = _arg;
    return *this;
  }
  Type & set__larvae_count(
    const uint16_t & _arg)
  {
    this->larvae_count = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msgs__msg__CountWithFloaterInfo
    std::shared_ptr<custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msgs__msg__CountWithFloaterInfo
    std::shared_ptr<custom_msgs::msg::CountWithFloaterInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CountWithFloaterInfo_ & other) const
  {
    if (this->floater_info != other.floater_info) {
      return false;
    }
    if (this->larvae_count != other.larvae_count) {
      return false;
    }
    return true;
  }
  bool operator!=(const CountWithFloaterInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CountWithFloaterInfo_

// alias to use template instance with default allocator
using CountWithFloaterInfo =
  custom_msgs::msg::CountWithFloaterInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__COUNT_WITH_FLOATER_INFO__STRUCT_HPP_
