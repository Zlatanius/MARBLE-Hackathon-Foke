// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msgs:msg/LocationWithFloaterInfo.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSGS__MSG__DETAIL__LOCATION_WITH_FLOATER_INFO__STRUCT_H_
#define CUSTOM_MSGS__MSG__DETAIL__LOCATION_WITH_FLOATER_INFO__STRUCT_H_

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

/// Struct defined in msg/LocationWithFloaterInfo in the package custom_msgs.
typedef struct custom_msgs__msg__LocationWithFloaterInfo
{
  rosidl_runtime_c__String floater_info;
  float latitude;
  float longitude;
  float altitude;
} custom_msgs__msg__LocationWithFloaterInfo;

// Struct for a sequence of custom_msgs__msg__LocationWithFloaterInfo.
typedef struct custom_msgs__msg__LocationWithFloaterInfo__Sequence
{
  custom_msgs__msg__LocationWithFloaterInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msgs__msg__LocationWithFloaterInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSGS__MSG__DETAIL__LOCATION_WITH_FLOATER_INFO__STRUCT_H_
