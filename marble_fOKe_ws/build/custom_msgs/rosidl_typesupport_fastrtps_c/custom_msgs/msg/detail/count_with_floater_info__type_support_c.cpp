// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_msgs:msg/CountWithFloaterInfo.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/count_with_floater_info__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msgs/msg/detail/count_with_floater_info__struct.h"
#include "custom_msgs/msg/detail/count_with_floater_info__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // floater_info
#include "rosidl_runtime_c/string_functions.h"  // floater_info

// forward declare type support functions


using _CountWithFloaterInfo__ros_msg_type = custom_msgs__msg__CountWithFloaterInfo;

static bool _CountWithFloaterInfo__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CountWithFloaterInfo__ros_msg_type * ros_message = static_cast<const _CountWithFloaterInfo__ros_msg_type *>(untyped_ros_message);
  // Field name: floater_info
  {
    const rosidl_runtime_c__String * str = &ros_message->floater_info;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: larvae_count
  {
    cdr << ros_message->larvae_count;
  }

  return true;
}

static bool _CountWithFloaterInfo__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CountWithFloaterInfo__ros_msg_type * ros_message = static_cast<_CountWithFloaterInfo__ros_msg_type *>(untyped_ros_message);
  // Field name: floater_info
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->floater_info.data) {
      rosidl_runtime_c__String__init(&ros_message->floater_info);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->floater_info,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'floater_info'\n");
      return false;
    }
  }

  // Field name: larvae_count
  {
    cdr >> ros_message->larvae_count;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t get_serialized_size_custom_msgs__msg__CountWithFloaterInfo(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CountWithFloaterInfo__ros_msg_type * ros_message = static_cast<const _CountWithFloaterInfo__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name floater_info
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->floater_info.size + 1);
  // field.name larvae_count
  {
    size_t item_size = sizeof(ros_message->larvae_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CountWithFloaterInfo__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_msgs__msg__CountWithFloaterInfo(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msgs
size_t max_serialized_size_custom_msgs__msg__CountWithFloaterInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: floater_info
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: larvae_count
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _CountWithFloaterInfo__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_custom_msgs__msg__CountWithFloaterInfo(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_CountWithFloaterInfo = {
  "custom_msgs::msg",
  "CountWithFloaterInfo",
  _CountWithFloaterInfo__cdr_serialize,
  _CountWithFloaterInfo__cdr_deserialize,
  _CountWithFloaterInfo__get_serialized_size,
  _CountWithFloaterInfo__max_serialized_size
};

static rosidl_message_type_support_t _CountWithFloaterInfo__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CountWithFloaterInfo,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msgs, msg, CountWithFloaterInfo)() {
  return &_CountWithFloaterInfo__type_support;
}

#if defined(__cplusplus)
}
#endif
