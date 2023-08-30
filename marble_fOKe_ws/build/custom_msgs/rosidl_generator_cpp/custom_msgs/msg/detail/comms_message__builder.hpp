// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/CommsMessage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__COMMS_MESSAGE__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__COMMS_MESSAGE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/comms_message__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_CommsMessage_altitude
{
public:
  explicit Init_CommsMessage_altitude(::custom_msgs::msg::CommsMessage & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::CommsMessage altitude(::custom_msgs::msg::CommsMessage::_altitude_type arg)
  {
    msg_.altitude = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::CommsMessage msg_;
};

class Init_CommsMessage_longitude
{
public:
  explicit Init_CommsMessage_longitude(::custom_msgs::msg::CommsMessage & msg)
  : msg_(msg)
  {}
  Init_CommsMessage_altitude longitude(::custom_msgs::msg::CommsMessage::_longitude_type arg)
  {
    msg_.longitude = std::move(arg);
    return Init_CommsMessage_altitude(msg_);
  }

private:
  ::custom_msgs::msg::CommsMessage msg_;
};

class Init_CommsMessage_latitude
{
public:
  explicit Init_CommsMessage_latitude(::custom_msgs::msg::CommsMessage & msg)
  : msg_(msg)
  {}
  Init_CommsMessage_longitude latitude(::custom_msgs::msg::CommsMessage::_latitude_type arg)
  {
    msg_.latitude = std::move(arg);
    return Init_CommsMessage_longitude(msg_);
  }

private:
  ::custom_msgs::msg::CommsMessage msg_;
};

class Init_CommsMessage_concentration
{
public:
  explicit Init_CommsMessage_concentration(::custom_msgs::msg::CommsMessage & msg)
  : msg_(msg)
  {}
  Init_CommsMessage_latitude concentration(::custom_msgs::msg::CommsMessage::_concentration_type arg)
  {
    msg_.concentration = std::move(arg);
    return Init_CommsMessage_latitude(msg_);
  }

private:
  ::custom_msgs::msg::CommsMessage msg_;
};

class Init_CommsMessage_floater_id
{
public:
  Init_CommsMessage_floater_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CommsMessage_concentration floater_id(::custom_msgs::msg::CommsMessage::_floater_id_type arg)
  {
    msg_.floater_id = std::move(arg);
    return Init_CommsMessage_concentration(msg_);
  }

private:
  ::custom_msgs::msg::CommsMessage msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::CommsMessage>()
{
  return custom_msgs::msg::builder::Init_CommsMessage_floater_id();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__COMMS_MESSAGE__BUILDER_HPP_
