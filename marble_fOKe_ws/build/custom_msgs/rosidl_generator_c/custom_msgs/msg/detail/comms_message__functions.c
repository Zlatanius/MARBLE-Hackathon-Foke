// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/CommsMessage.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/comms_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_msgs__msg__CommsMessage__init(custom_msgs__msg__CommsMessage * msg)
{
  if (!msg) {
    return false;
  }
  // floater_id
  // concentration
  // latitude
  // longitude
  // altitude
  return true;
}

void
custom_msgs__msg__CommsMessage__fini(custom_msgs__msg__CommsMessage * msg)
{
  if (!msg) {
    return;
  }
  // floater_id
  // concentration
  // latitude
  // longitude
  // altitude
}

bool
custom_msgs__msg__CommsMessage__are_equal(const custom_msgs__msg__CommsMessage * lhs, const custom_msgs__msg__CommsMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // floater_id
  if (lhs->floater_id != rhs->floater_id) {
    return false;
  }
  // concentration
  if (lhs->concentration != rhs->concentration) {
    return false;
  }
  // latitude
  if (lhs->latitude != rhs->latitude) {
    return false;
  }
  // longitude
  if (lhs->longitude != rhs->longitude) {
    return false;
  }
  // altitude
  if (lhs->altitude != rhs->altitude) {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__CommsMessage__copy(
  const custom_msgs__msg__CommsMessage * input,
  custom_msgs__msg__CommsMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // floater_id
  output->floater_id = input->floater_id;
  // concentration
  output->concentration = input->concentration;
  // latitude
  output->latitude = input->latitude;
  // longitude
  output->longitude = input->longitude;
  // altitude
  output->altitude = input->altitude;
  return true;
}

custom_msgs__msg__CommsMessage *
custom_msgs__msg__CommsMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__CommsMessage * msg = (custom_msgs__msg__CommsMessage *)allocator.allocate(sizeof(custom_msgs__msg__CommsMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__CommsMessage));
  bool success = custom_msgs__msg__CommsMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__CommsMessage__destroy(custom_msgs__msg__CommsMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__CommsMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__CommsMessage__Sequence__init(custom_msgs__msg__CommsMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__CommsMessage * data = NULL;

  if (size) {
    data = (custom_msgs__msg__CommsMessage *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__CommsMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__CommsMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__CommsMessage__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msgs__msg__CommsMessage__Sequence__fini(custom_msgs__msg__CommsMessage__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msgs__msg__CommsMessage__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msgs__msg__CommsMessage__Sequence *
custom_msgs__msg__CommsMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__CommsMessage__Sequence * array = (custom_msgs__msg__CommsMessage__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__CommsMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__CommsMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__CommsMessage__Sequence__destroy(custom_msgs__msg__CommsMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__CommsMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__CommsMessage__Sequence__are_equal(const custom_msgs__msg__CommsMessage__Sequence * lhs, const custom_msgs__msg__CommsMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__CommsMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__CommsMessage__Sequence__copy(
  const custom_msgs__msg__CommsMessage__Sequence * input,
  custom_msgs__msg__CommsMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__CommsMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msgs__msg__CommsMessage * data =
      (custom_msgs__msg__CommsMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__CommsMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__CommsMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msgs__msg__CommsMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
