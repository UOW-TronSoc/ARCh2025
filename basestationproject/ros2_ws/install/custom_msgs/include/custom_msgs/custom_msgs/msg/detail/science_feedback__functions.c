// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msgs:msg/ScienceFeedback.idl
// generated code does not contain a copyright notice
#include "custom_msgs/msg/detail/science_feedback__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
custom_msgs__msg__ScienceFeedback__init(custom_msgs__msg__ScienceFeedback * msg)
{
  if (!msg) {
    return false;
  }
  // water_percent
  // temperature
  // ilmenite_percent
  return true;
}

void
custom_msgs__msg__ScienceFeedback__fini(custom_msgs__msg__ScienceFeedback * msg)
{
  if (!msg) {
    return;
  }
  // water_percent
  // temperature
  // ilmenite_percent
}

bool
custom_msgs__msg__ScienceFeedback__are_equal(const custom_msgs__msg__ScienceFeedback * lhs, const custom_msgs__msg__ScienceFeedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // water_percent
  if (lhs->water_percent != rhs->water_percent) {
    return false;
  }
  // temperature
  if (lhs->temperature != rhs->temperature) {
    return false;
  }
  // ilmenite_percent
  if (lhs->ilmenite_percent != rhs->ilmenite_percent) {
    return false;
  }
  return true;
}

bool
custom_msgs__msg__ScienceFeedback__copy(
  const custom_msgs__msg__ScienceFeedback * input,
  custom_msgs__msg__ScienceFeedback * output)
{
  if (!input || !output) {
    return false;
  }
  // water_percent
  output->water_percent = input->water_percent;
  // temperature
  output->temperature = input->temperature;
  // ilmenite_percent
  output->ilmenite_percent = input->ilmenite_percent;
  return true;
}

custom_msgs__msg__ScienceFeedback *
custom_msgs__msg__ScienceFeedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__ScienceFeedback * msg = (custom_msgs__msg__ScienceFeedback *)allocator.allocate(sizeof(custom_msgs__msg__ScienceFeedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msgs__msg__ScienceFeedback));
  bool success = custom_msgs__msg__ScienceFeedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
custom_msgs__msg__ScienceFeedback__destroy(custom_msgs__msg__ScienceFeedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    custom_msgs__msg__ScienceFeedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
custom_msgs__msg__ScienceFeedback__Sequence__init(custom_msgs__msg__ScienceFeedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__ScienceFeedback * data = NULL;

  if (size) {
    data = (custom_msgs__msg__ScienceFeedback *)allocator.zero_allocate(size, sizeof(custom_msgs__msg__ScienceFeedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msgs__msg__ScienceFeedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msgs__msg__ScienceFeedback__fini(&data[i - 1]);
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
custom_msgs__msg__ScienceFeedback__Sequence__fini(custom_msgs__msg__ScienceFeedback__Sequence * array)
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
      custom_msgs__msg__ScienceFeedback__fini(&array->data[i]);
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

custom_msgs__msg__ScienceFeedback__Sequence *
custom_msgs__msg__ScienceFeedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  custom_msgs__msg__ScienceFeedback__Sequence * array = (custom_msgs__msg__ScienceFeedback__Sequence *)allocator.allocate(sizeof(custom_msgs__msg__ScienceFeedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = custom_msgs__msg__ScienceFeedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
custom_msgs__msg__ScienceFeedback__Sequence__destroy(custom_msgs__msg__ScienceFeedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    custom_msgs__msg__ScienceFeedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
custom_msgs__msg__ScienceFeedback__Sequence__are_equal(const custom_msgs__msg__ScienceFeedback__Sequence * lhs, const custom_msgs__msg__ScienceFeedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!custom_msgs__msg__ScienceFeedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
custom_msgs__msg__ScienceFeedback__Sequence__copy(
  const custom_msgs__msg__ScienceFeedback__Sequence * input,
  custom_msgs__msg__ScienceFeedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(custom_msgs__msg__ScienceFeedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    custom_msgs__msg__ScienceFeedback * data =
      (custom_msgs__msg__ScienceFeedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!custom_msgs__msg__ScienceFeedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          custom_msgs__msg__ScienceFeedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!custom_msgs__msg__ScienceFeedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
