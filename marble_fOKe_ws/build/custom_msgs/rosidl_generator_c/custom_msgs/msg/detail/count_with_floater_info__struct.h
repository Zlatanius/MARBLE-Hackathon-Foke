// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/CountWithFloaterInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__COUNT_WITH_FLOATER_INFO__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__COUNT_WITH_FLOATER_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'floater_info'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/CountWithFloaterInfo in the package custom_msgs.
typedef struct custom_msgs__msg__CountWithFloaterInfo
{
  rosidl_runtime_c__String floater_info;
  uint16_t larvae_count;
} custom_msgs__msg__CountWithFloaterInfo;

// Struct for a sequence of custom_msgs__msg__CountWithFloaterInfo.
typedef struct custom_msgs__msg__CountWithFloaterInfo__Sequence
{
  custom_msgs__msg__CountWithFloaterInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__CountWithFloaterInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__COUNT_WITH_FLOATER_INFO__STRUCT_H_
