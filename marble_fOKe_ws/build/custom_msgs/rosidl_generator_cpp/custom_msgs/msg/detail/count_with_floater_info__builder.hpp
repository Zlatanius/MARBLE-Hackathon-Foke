// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msgs:msg/CountWithFloaterInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__COUNT_WITH_FLOATER_INFO__BUILDER_HPP_
#define CUSTOM_MSGS__MSG__DETAIL__COUNT_WITH_FLOATER_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_msgs/msg/detail/count_with_floater_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_msgs
{

namespace msg
{

namespace builder
{

class Init_CountWithFloaterInfo_larvae_count
{
public:
  explicit Init_CountWithFloaterInfo_larvae_count(::custom_msgs::msg::CountWithFloaterInfo & msg)
  : msg_(msg)
  {}
  ::custom_msgs::msg::CountWithFloaterInfo larvae_count(::custom_msgs::msg::CountWithFloaterInfo::_larvae_count_type arg)
  {
    msg_.larvae_count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msgs::msg::CountWithFloaterInfo msg_;
};

class Init_CountWithFloaterInfo_floater_info
{
public:
  Init_CountWithFloaterInfo_floater_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CountWithFloaterInfo_larvae_count floater_info(::custom_msgs::msg::CountWithFloaterInfo::_floater_info_type arg)
  {
    msg_.floater_info = std::move(arg);
    return Init_CountWithFloaterInfo_larvae_count(msg_);
  }

private:
  ::custom_msgs::msg::CountWithFloaterInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msgs::msg::CountWithFloaterInfo>()
{
  return custom_msgs::msg::builder::Init_CountWithFloaterInfo_floater_info();
}

}  // namespace custom_msgs

#endif  // CUSTOM_MSGS__MSG__DETAIL__COUNT_WITH_FLOATER_INFO__BUILDER_HPP_
