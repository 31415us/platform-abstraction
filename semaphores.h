#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef __unix__
#include "mock/semaphores.h"
#endif

/** Creates a semaphore with given count value. */
semaphore_t *os_semaphore_create(uint32_t count);

/** Frees the memory and operating system structures used by a semaphore. */
void os_semaphore_delete(semaphore_t *sem);

/** Takes a semaphore if available, blocks if not available. */
void os_semaphore_take(semaphore_t *sem);

/** Takes a semaphore non-blocking */
bool os_semaphore_try(semaphore_t *sem);

/** Acquire the semaphore blocking with timeout [us] */
bool os_semaphore_try_timeout(semaphore_t *sem, uint32_t timeout);

/** Releases (posts) a semaphore. */
void os_semaphore_release(semaphore_t *sem);

#endif
