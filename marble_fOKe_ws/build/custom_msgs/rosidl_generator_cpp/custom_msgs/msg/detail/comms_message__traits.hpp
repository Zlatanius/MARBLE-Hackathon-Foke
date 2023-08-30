// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/CommsMessage.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__COMMS_MESSAGE__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__COMMS_MESSAGE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/comms_message__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CommsMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: floater_id
  {
    out << "floater_id: ";
    rosidl_generator_traits::value_to_yaml(msg.floater_id, out);
    out << ", ";
  }

  // member: concentration
  {
    out << "concentration: ";
    rosidl_generator_traits::value_to_yaml(msg.concentration, out);
    out << ", ";
  }

  // member: latitude
  {
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << ", ";
  }

  // member: longitude
  {
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << ", ";
  }

  // member: altitude
  {
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CommsMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: floater_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "floater_id: ";
    rosidl_generator_traits::value_to_yaml(msg.floater_id, out);
    out << "\n";
  }

  // member: concentration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "concentration: ";
    rosidl_generator_traits::value_to_yaml(msg.concentration, out);
    out << "\n";
  }

  // member: latitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "latitude: ";
    rosidl_generator_traits::value_to_yaml(msg.latitude, out);
    out << "\n";
  }

  // member: longitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "longitude: ";
    rosidl_generator_traits::value_to_yaml(msg.longitude, out);
    out << "\n";
  }

  // member: altitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.altitude, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CommsMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace custom_msgs

namespace rosidl_generator_traits
{

[[deprecated("use custom_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const custom_msgs::msg::CommsMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::CommsMessage & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::CommsMessage>()
{
  return "custom_msgs::msg::CommsMessage";
}

template<>
inline const char * name<custom_msgs::msg::CommsMessage>()
{
  return "custom_msgs/msg/CommsMessage";
}

template<>
struct has_fixed_size<custom_msgs::msg::CommsMessage>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_msgs::msg::CommsMessage>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_msgs::msg::CommsMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__COMMS_MESSAGE__TRAITS_HPP_
