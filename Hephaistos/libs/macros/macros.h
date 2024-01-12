/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 11:21:32 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/01/11 17:32:42 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MACROS_H
#define _MACROS_H

/* OPERATORS */

#ifndef __cplusplus
#define and &&
#define or ||
#define not !
#define not_eq !=
#define equals ==
#define is =
#endif

/* INLINE FUNCTIONS */

#define pause() \
    while (1) { \
    }

/* LOOP */

#define for_range(i, x, y) \
    for (i = x; i < y; ++i)

#define for_range_reverse(i, x, y) \
    for (i = x; i > y; --i)

#define for_range_step(i, x, y, step) \
    for (i = x; i < y; i += step)

#define for_range_reverse_step(i, x, y, step) \
    for (i = x; i > y; i -= step)

#define for_each(i, array) \
    for (i = 0; i < array_size(array); ++i)

#define for_each_reverse(i, array) \
    for (i = array_size(array) - 1; i >= 0; --i)

/* ARRAY */

#define array_get_size(array) \
    (sizeof(array) / sizeof(array[0]))

#define array_last(array) \
    array[array_size(array) - 1]

#define array_first(array) \
    array[0]

#define array_last_index(array) \
    array_size(array) - 1

#define set_array(array, value)                      \
    for (uint32_t i = 0; i < array_size(array); ++i) \
        array[i] = value;

#define init_array(array)                            \
    for (uint32_t i = 0; i < array_size(array); ++i) \
        array[i] = 0x0;

#define is_array(array) \
    ((void *)&a == (void *)a)

/* UTILS */

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

/**
 * @brief Defines a macro to mark a variable as unused.
 * 
 * This macro is used to suppress compiler warnings about unused variables.
 * 
 * Example usage:
 * @code
 * int foo __unused__;
 * @endcode
 */
#define __unused__ __attribute__((unused))

/**
 * @brief Defines a macro to mark a function as not returning.
 * 
 * This macro is used to indicate that a function does not return to the caller.
 * 
 * Example usage:
 * @code
 * void exit_program() __noreturn__;
 * @endcode
 */
#define __noreturn__ __attribute__((noreturn))

/**
 * @brief Defines a macro to specify that a structure or variable should be packed.
 * 
 * This macro is used to ensure that a structure or variable is not padded by the compiler.
 * 
 * Example usage:
 * @code
 * struct __packed__ my_struct {
 *     int a;
 *     char b;
 * };
 * @endcode
 */
#define __packed__ __attribute__((packed))

/**
 * @brief Defines a macro to specify the alignment of a structure or variable.
 * 
 * This macro is used to specify the alignment of a structure or variable in memory.
 * 
 * Example usage:
 * @code
 * struct __aligned__(4) my_struct {
 *     int a;
 *     char b;
 * };
 * @endcode
 */
#define __aligned__(x) __attribute__((aligned(x)))

/**
 * @brief Defines a macro to specify the section where a variable or function should be placed.
 * 
 * This macro is used to specify the section where a variable or function should be placed in the final binary.
 * 
 * Example usage:
 * @code
 * int my_variable __section__("my_section");
 * @endcode
 */
#define __section__(x) __attribute__((section(x)))

/**
 * @brief Defines a macro to mark a function or variable as deprecated.
 * 
 * This macro is used to indicate that a function or variable is deprecated and should not be used anymore.
 * 
 * Example usage:
 * @code
 * void old_function() __deprecated__;
 * @endcode
 */
#define __deprecated__ __attribute__((deprecated))

/**
 * @brief Defines a macro to mark a variable as used.
 * 
 * This macro is used to prevent the compiler from optimizing out a variable that appears to be unused.
 * 
 * Example usage:
 * @code
 * void use_variable(int var) {
 *     var __used__;
 *     // Do something with var
 * }
 * @endcode
 */
#define __used__ __attribute__((used))

/**
 * @brief Defines a macro to mark a function or variable as weak.
 * 
 * This macro is used to indicate that a function or variable has weak linkage.
 * 
 * Example usage:
 * @code
 * void weak_function() __weak__;
 * @endcode
 */
#define __weak__ __attribute__((weak))

/**
 * @brief Defines a macro to mark a function as returning a malloc'ed pointer.
 * 
 * This macro is used to indicate that a function returns a pointer to memory that has been allocated with malloc.
 * 
 * Example usage:
 * @code
 * char* allocate_memory() __malloc__;
 * @endcode
 */
#define __malloc__ __attribute__((malloc))

/**
 * @brief Defines a macro to mark a function as always inlined.
 * 
 * This macro is used to indicate that a function should always be inlined by the compiler.
 * 
 * Example usage:
 * @code
 * inline int add_numbers(int a, int b) __always_inline__;
 * @endcode
 */
#define __always_inline__ __attribute__((always_inline))

/**
 * @brief Defines a macro to mark function parameters as non-null.
 * 
 * This macro is used to indicate that function parameters should not be null.
 * 
 * Example usage:
 * @code
 * void print_string(const char* str) __nonull__;
 * @endcode
 */
#define __nonull__ __attribute__((nonnull))

/**
 * @brief Defines a macro to mark a function as pure.
 * 
 * This macro is used to indicate that a function has no side effects and only depends on its arguments.
 * 
 * Example usage:
 * @code
 * int square(int x) __pure__;
 * @endcode
 */
#define __pure__ __attribute__((pure))

/**
 * @brief Defines a macro to mark a function as const.
 * 
 * This macro is used to indicate that a function does not modify any global or static variables.
 * 
 * Example usage:
 * @code
 * int get_value() __const__;
 * @endcode
 */
#define __const__ __attribute__((const))

/**
 * @brief Defines a macro to specify the format of a printf-like function.
 * 
 * This macro is used to specify the format of a printf-like function, allowing the compiler to perform format string checking.
 * 
 * Example usage:
 * @code
 * void print_formatted_string(const char* format, ...) __format__(printf, 1, 2);
 * @endcode
 */
#define __format__(x, y, z) __attribute__((format(x, y, z)))

/**
 * @brief Defines a macro to mark a function as potentially returning twice.
 * 
 * This macro is used to indicate that a function can return to its caller multiple times.
 * 
 * Example usage:
 * @code
 * void longjmp(jmp_buf env) __returns_twice__;
 * @endcode
 */
#define __returns_twice__ __attribute__((returns_twice))

/**
 * @brief Defines a macro to mark a function or variable as having a warn_unused_result attribute.
 * 
 * This macro is used to indicate that a function or variable should not be ignored by the caller.
 * 
 * Example usage:
 * @code
 * int calculate_sum(int a, int b) __warn_unused_result__;
 * @endcode
 */
#define __warn_unused_result__ __attribute__((warn_unused_result))

/**
 * @brief Defines a macro to specify a cleanup function for a variable.
 * 
 * This macro is used to specify a cleanup function that will be called when a variable goes out of scope.
 * 
 * Example usage:
 * @code
 * void cleanup_function(void* ptr) {
 *     // Cleanup code
 * }
 * 
 * void use_variable() {
 *     int var __cleanup__(cleanup_function);
 *     // Use var
 * }
 * @endcode
 */
#define __cleanup__(x) __attribute__((cleanup(x)))

/**
 * @brief Defines a macro to mark a function as a constructor.
 * 
 * This macro is used to indicate that a function is a constructor.
 * 
 * Example usage:
 * @code
 * void my_constructor() __constructor__;
 * @endcode
 */
#define __constructor__ __attribute__((constructor))

#endif /* !_MACROS_H */