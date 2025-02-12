// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/CustomMessage.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/custom_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `data`
#include "rosidl_runtime_c/string_functions.h"

bool
custom_msgs__msg__CustomMessage__init(custom_msgs__msg__CustomMessage * msg)
{
  if (!msg) {
    return false;
  }
  // epoch_time
  // data
  if (!rosidl_runtime_c__String__init(&msg->data)) {
    custom_msgs__msg__CustomMessage__fini(msg);
    return false;
  }
  // flag
  // left_drive
  // right_drive
  return true;
}

void
custom_msgs__msg__CustomMessage__fini(custom_msgs__msg__CustomMessage * msg)
{
  if (!msg) {
    return;
  }
  // epoch_time
  // data
  rosidl_runtime_c__String__fini(&msg->data);
  // flag
  // left_drive
  // right_drive
}

bool
custom_msgs__msg__CustomMessage__are_equal(const custom_msgs__msg__CustomMessage * lhs, const custom_msgs__msg__CustomMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // epoch_time
  if (lhs->epoch_time != rhs->epoch_time) {
    return false;
  }
  // data
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->data), &(rhs->data)))
  {
    return false;
  }
  // flag
  if (lhs->flag != rhs->flag) {
    return false;
  }
  // left_drive
  if (lhs->left_drive != rhs->left_drive) {
    return false;
  }
  // right_drive
  if (lhs->right_drive != rhs->right_drive) {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__CustomMessage__copy(
  const custom_msgs__msg__CustomMessage * input,
  custom_msgs__msg__CustomMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // epoch_time
  output->epoch_time = input->epoch_time;
  // data
  if (!rosidl_runtime_c__String__copy(
      &(input->data), &(output->data)))
  {
    return false;
  }
  // flag
  output->flag = input->flag;
  // left_drive
  output->left_drive = input->left_drive;
  // right_drive
  output->right_drive = input->right_drive;
  return true;
}

custom_msgs__msg__CustomMessage *
custom_msgs__msg__CustomMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__CustomMessage * msg = (custom_msgs__msg__CustomMessage *)allocator.allocate(sizeof(custom_msgs__msg__CustomMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__CustomMessage));
  bool success = custom_msgs__msg__CustomMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__CustomMessage__destroy(custom_msgs__msg__CustomMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__CustomMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__CustomMessage__Sequence__init(custom_msgs__msg__CustomMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__CustomMessage * data = NULL;

  if (size) {
    data = (custom_msgs__msg__CustomMessage *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__CustomMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__CustomMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__CustomMessage__fini(&data[i - 1]);
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
custom_msgs__msg__CustomMessage__Sequence__fini(custom_msgs__msg__CustomMessage__Sequence * array)
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
      custom_msgs__msg__CustomMessage__fini(&array->data[i]);
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

custom_msgs__msg__CustomMessage__Sequence *
custom_msgs__msg__CustomMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__CustomMessage__Sequence * array = (custom_msgs__msg__CustomMessage__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__CustomMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__CustomMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__CustomMessage__Sequence__destroy(custom_msgs__msg__CustomMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__CustomMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__CustomMessage__Sequence__are_equal(const custom_msgs__msg__CustomMessage__Sequence * lhs, const custom_msgs__msg__CustomMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__CustomMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__CustomMessage__Sequence__copy(
  const custom_msgs__msg__CustomMessage__Sequence * input,
  custom_msgs__msg__CustomMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__CustomMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msgs__msg__CustomMessage * data =
      (custom_msgs__msg__CustomMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__CustomMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__CustomMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msgs__msg__CustomMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
