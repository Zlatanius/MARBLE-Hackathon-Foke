// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msgs:msg/LocationWithFloaterInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__LOCATION_WITH_FLOATER_INFO__TRAITS_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__LOCATION_WITH_FLOATER_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "custom_msgs/msg/detail/location_with_floater_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace custom_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const LocationWithFloaterInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: floater_info
  {
    out << "floater_info: ";
    rosidl_generator_traits::value_to_yaml(msg.floater_info, out);
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
  const LocationWithFloaterInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: floater_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "floater_info: ";
    rosidl_generator_traits::value_to_yaml(msg.floater_info, out);
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

inline std::string to_yaml(const LocationWithFloaterInfo & msg, bool use_flow_style = false)
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
  const custom_msgs::msg::LocationWithFloaterInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  custom_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use custom_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const custom_msgs::msg::LocationWithFloaterInfo & msg)
{
  return custom_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<custom_msgs::msg::LocationWithFloaterInfo>()
{
  return "custom_msgs::msg::LocationWithFloaterInfo";
}

template<>
inline const char * name<custom_msgs::msg::LocationWithFloaterInfo>()
{
  return "custom_msgs/msg/LocationWithFloaterInfo";
}

template<>
struct has_fixed_size<custom_msgs::msg::LocationWithFloaterInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<custom_msgs::msg::LocationWithFloaterInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<custom_msgs::msg::LocationWithFloaterInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSGS__MSG__DETAIL__LOCATION_WITH_FLOATER_INFO__TRAITS_HPP_
