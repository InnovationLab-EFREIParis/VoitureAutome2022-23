// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interfaces:msg/MonAckermannDrive.idl
// generated code does not contain a copyright notice
#include "interfaces/msg/detail/mon_ackermann_drive__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
interfaces__msg__MonAckermannDrive__init(interfaces__msg__MonAckermannDrive * msg)
{
  if (!msg) {
    return false;
  }
  // steering_angle
  // steering_angle_velocity
  // speed
  // acceleration
  // jerk
  return true;
}

void
interfaces__msg__MonAckermannDrive__fini(interfaces__msg__MonAckermannDrive * msg)
{
  if (!msg) {
    return;
  }
  // steering_angle
  // steering_angle_velocity
  // speed
  // acceleration
  // jerk
}

bool
interfaces__msg__MonAckermannDrive__are_equal(const interfaces__msg__MonAckermannDrive * lhs, const interfaces__msg__MonAckermannDrive * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // steering_angle
  if (lhs->steering_angle != rhs->steering_angle) {
    return false;
  }
  // steering_angle_velocity
  if (lhs->steering_angle_velocity != rhs->steering_angle_velocity) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // acceleration
  if (lhs->acceleration != rhs->acceleration) {
    return false;
  }
  // jerk
  if (lhs->jerk != rhs->jerk) {
    return false;
  }
  return true;
}

bool
interfaces__msg__MonAckermannDrive__copy(
  const interfaces__msg__MonAckermannDrive * input,
  interfaces__msg__MonAckermannDrive * output)
{
  if (!input || !output) {
    return false;
  }
  // steering_angle
  output->steering_angle = input->steering_angle;
  // steering_angle_velocity
  output->steering_angle_velocity = input->steering_angle_velocity;
  // speed
  output->speed = input->speed;
  // acceleration
  output->acceleration = input->acceleration;
  // jerk
  output->jerk = input->jerk;
  return true;
}

interfaces__msg__MonAckermannDrive *
interfaces__msg__MonAckermannDrive__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__MonAckermannDrive * msg = (interfaces__msg__MonAckermannDrive *)allocator.allocate(sizeof(interfaces__msg__MonAckermannDrive), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interfaces__msg__MonAckermannDrive));
  bool success = interfaces__msg__MonAckermannDrive__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interfaces__msg__MonAckermannDrive__destroy(interfaces__msg__MonAckermannDrive * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interfaces__msg__MonAckermannDrive__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interfaces__msg__MonAckermannDrive__Sequence__init(interfaces__msg__MonAckermannDrive__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__MonAckermannDrive * data = NULL;

  if (size) {
    data = (interfaces__msg__MonAckermannDrive *)allocator.zero_allocate(size, sizeof(interfaces__msg__MonAckermannDrive), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interfaces__msg__MonAckermannDrive__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interfaces__msg__MonAckermannDrive__fini(&data[i - 1]);
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
interfaces__msg__MonAckermannDrive__Sequence__fini(interfaces__msg__MonAckermannDrive__Sequence * array)
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
      interfaces__msg__MonAckermannDrive__fini(&array->data[i]);
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

interfaces__msg__MonAckermannDrive__Sequence *
interfaces__msg__MonAckermannDrive__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interfaces__msg__MonAckermannDrive__Sequence * array = (interfaces__msg__MonAckermannDrive__Sequence *)allocator.allocate(sizeof(interfaces__msg__MonAckermannDrive__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interfaces__msg__MonAckermannDrive__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interfaces__msg__MonAckermannDrive__Sequence__destroy(interfaces__msg__MonAckermannDrive__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interfaces__msg__MonAckermannDrive__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interfaces__msg__MonAckermannDrive__Sequence__are_equal(const interfaces__msg__MonAckermannDrive__Sequence * lhs, const interfaces__msg__MonAckermannDrive__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interfaces__msg__MonAckermannDrive__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interfaces__msg__MonAckermannDrive__Sequence__copy(
  const interfaces__msg__MonAckermannDrive__Sequence * input,
  interfaces__msg__MonAckermannDrive__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interfaces__msg__MonAckermannDrive);
    interfaces__msg__MonAckermannDrive * data =
      (interfaces__msg__MonAckermannDrive *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interfaces__msg__MonAckermannDrive__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interfaces__msg__MonAckermannDrive__fini(&data[i]);
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
    if (!interfaces__msg__MonAckermannDrive__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
