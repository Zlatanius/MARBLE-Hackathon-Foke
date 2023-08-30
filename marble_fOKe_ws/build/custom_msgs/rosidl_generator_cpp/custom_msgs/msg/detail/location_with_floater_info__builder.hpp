// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/LocationWithFloaterInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__LOCATION_WITH_FLOATER_INFO__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__LOCATION_WITH_FLOATER_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/location_with_floater_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_LocationWithFloaterInfo_altitude
{
public:
  explicit Init_LocationWithFloaterInfo_altitude(::custom_msgs::msg::LocationWithFloaterInfo & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::LocationWithFloaterInfo altitude(::custom_msgs::msg::LocationWithFloaterInfo::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::LocationWithFloaterInfo msg_;
};

class Init_LocationWithFloaterInfo_longitude
{
public:
  explicit Init_LocationWithFloaterInfo_longitude(::custom_msgs::msg::LocationWithFloaterInfo & msg)
  : msg_(msg)
  {}
  Init_LocationWithFloaterInfo_altitude longitude(::custom_msgs::msg::LocationWithFloaterInfo::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_LocationWithFloaterInfo_altitude(msg_);
  }

private:
  ::custom_msgs::msg::LocationWithFloaterInfo msg_;
};

class Init_LocationWithFloaterInfo_latitude
{
public:
  explicit Init_LocationWithFloaterInfo_latitude(::custom_msgs::msg::LocationWithFloaterInfo & msg)
  : msg_(msg)
  {}
  Init_LocationWithFloaterInfo_longitude latitude(::custom_msgs::msg::LocationWithFloaterInfo::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_LocationWithFloaterInfo_longitude(msg_);
  }

private:
  ::custom_msgs::msg::LocationWithFloaterInfo msg_;
};

class Init_LocationWithFloaterInfo_floater_info
{
public:
  Init_LocationWithFloaterInfo_floater_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LocationWithFloaterInfo_latitude floater_info(::custom_msgs::msg::LocationWithFloaterInfo::_floater_info_type arg)
  {
    msg_.floater_info = std::move(arg);
    return Init_LocationWithFloaterInfo_latitude(msg_);
  }

private:
  ::custom_msgs::msg::LocationWithFloaterInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::LocationWithFloaterInfo>()
{
  return custom_msgs::msg::builder::Init_LocationWithFloaterInfo_floater_info();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__LOCATION_WITH_FLOATER_INFO__BUILDER_HPP_
