// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/Sensors.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/sensors__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `example_sensor1_name`
// Member `example_sensor2_name`
// Member `example_sensor3_name`
#include "rosidl_runtime_c/string_functions.h"

bool
interfaces__msg__Sensors__init(interfaces__msg__Sensors * msg)
{
  if (!msg) {
    return false;
  }
  // example_sensor1_name
  if (!rosidl_runtime_c__String__init(&msg->example_sensor1_name)) {
    interfaces__msg__Sensors__fini(msg);
    return false;
  }
  // example_sensor1_value
  // example_sensor2_name
  if (!rosidl_runtime_c__String__init(&msg->example_sensor2_name)) {
    interfaces__msg__Sensors__fini(msg);
    return false;
  }
  // example_sensor2_value
  // example_sensor3_name
  if (!rosidl_runtime_c__String__init(&msg->example_sensor3_name)) {
    interfaces__msg__Sensors__fini(msg);
    return false;
  }
  // example_sensor3_value
  return true;
}

void
interfaces__msg__Sensors__fini(interfaces__msg__Sensors * msg)
{
  if (!msg) {
    return;
  }
  // example_sensor1_name
  rosidl_runtime_c__String__fini(&msg->example_sensor1_name);
  // example_sensor1_value
  // example_sensor2_name
  rosidl_runtime_c__String__fini(&msg->example_sensor2_name);
  // example_sensor2_value
  // example_sensor3_name
  rosidl_runtime_c__String__fini(&msg->example_sensor3_name);
  // example_sensor3_value
}

bool
interfaces__msg__Sensors__are_equal(const interfaces__msg__Sensors * lhs, const interfaces__msg__Sensors * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // example_sensor1_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->example_sensor1_name), &(rhs->example_sensor1_name)))
  {
    return false;
  }
  // example_sensor1_value
  if (lhs->example_sensor1_value != rhs->example_sensor1_value) {
    return false;
  }
  // example_sensor2_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->example_sensor2_name), &(rhs->example_sensor2_name)))
  {
    return false;
  }
  // example_sensor2_value
  if (lhs->example_sensor2_value != rhs->example_sensor2_value) {
    return false;
  }
  // example_sensor3_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->example_sensor3_name), &(rhs->example_sensor3_name)))
  {
    return false;
  }
  // example_sensor3_value
  if (lhs->example_sensor3_value != rhs->example_sensor3_value) {
    return false;
  }
  return true;
}

bool
interfaces__msg__Sensors__copy(
  const interfaces__msg__Sensors * input,
  interfaces__msg__Sensors * output)
{
  if (!input || !output) {
    return false;
  }
  // example_sensor1_name
  if (!rosidl_runtime_c__String__copy(
      &(input->example_sensor1_name), &(output->example_sensor1_name)))
  {
    return false;
  }
  // example_sensor1_value
  output->example_sensor1_value = input->example_sensor1_value;
  // example_sensor2_name
  if (!rosidl_runtime_c__String__copy(
      &(input->example_sensor2_name), &(output->example_sensor2_name)))
  {
    return false;
  }
  // example_sensor2_value
  output->example_sensor2_value = input->example_sensor2_value;
  // example_sensor3_name
  if (!rosidl_runtime_c__String__copy(
      &(input->example_sensor3_name), &(output->example_sensor3_name)))
  {
    return false;
  }
  // example_sensor3_value
  output->example_sensor3_value = input->example_sensor3_value;
  return true;
}

interfaces__msg__Sensors *
interfaces__msg__Sensors__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__Sensors * msg = (interfaces__msg__Sensors *)allocator.allocate(sizeof(interfaces__msg__Sensors), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__Sensors));
  bool success = interfaces__msg__Sensors__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__Sensors__destroy(interfaces__msg__Sensors * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__msg__Sensors__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__msg__Sensors__Sequence__init(interfaces__msg__Sensors__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__Sensors * data = NULL;

  if (size) {
    data = (interfaces__msg__Sensors *)allocator.zero_allocate(size, sizeof(interfaces__msg__Sensors), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__Sensors__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__Sensors__fini(&data[i - 1]);
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
interfaces__msg__Sensors__Sequence__fini(interfaces__msg__Sensors__Sequence * array)
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
      interfaces__msg__Sensors__fini(&array->data[i]);
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

interfaces__msg__Sensors__Sequence *
interfaces__msg__Sensors__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__Sensors__Sequence * array = (interfaces__msg__Sensors__Sequence *)allocator.allocate(sizeof(interfaces__msg__Sensors__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__Sensors__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__msg__Sensors__Sequence__destroy(interfaces__msg__Sensors__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__msg__Sensors__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__msg__Sensors__Sequence__are_equal(const interfaces__msg__Sensors__Sequence * lhs, const interfaces__msg__Sensors__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__msg__Sensors__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__msg__Sensors__Sequence__copy(
  const interfaces__msg__Sensors__Sequence * input,
  interfaces__msg__Sensors__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__msg__Sensors);
    interfaces__msg__Sensors * data =
      (interfaces__msg__Sensors *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__msg__Sensors__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__msg__Sensors__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interfaces__msg__Sensors__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
