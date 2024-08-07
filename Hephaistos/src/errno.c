/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaucoul <vvaucoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:00:29 by vvaucoul          #+#    #+#             */
/*   Updated: 2024/07/28 11:22:57 by vvaucoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>

// Define the global errno variable
errno_t errno = 0;

// Array of error messages corresponding to error codes
static const char *error_messages[] = {
	[0] = "No error",
	[EPERM] = "Operation not permitted",
	[ENOENT] = "No such file or directory",
	[ESRCH] = "No such process",
	[EINTR] = "Interrupted system call",
	[EIO] = "I/O error",
	[ENXIO] = "No such device or address",
	[E2BIG] = "Argument list too long",
	[ENOEXEC] = "Exec format error",
	[EBADF] = "Bad file number",
	[ECHILD] = "No child processes",
	[EAGAIN] = "Try again",
	[ENOMEM] = "Out of memory",
	[EACCES] = "Permission denied",
	[EFAULT] = "Bad address",
	[ENOTBLK] = "Block device required",
	[EBUSY] = "Device or resource busy",
	[EEXIST] = "File exists",
	[EXDEV] = "Cross-device link",
	[ENODEV] = "No such device",
	[ENOTDIR] = "Not a directory",
	[EISDIR] = "Is a directory",
	[EINVAL] = "Invalid argument",
	[ENFILE] = "File table overflow",
	[EMFILE] = "Too many open files",
	[ENOTTY] = "Not a typewriter",
	[ETXTBSY] = "Text file busy",
	[EFBIG] = "File too large",
	[ENOSPC] = "No space left on device",
	[ESPIPE] = "Illegal seek",
	[EROFS] = "Read-only file system",
	[EMLINK] = "Too many links",
	[EPIPE] = "Broken pipe",
	[EDOM] = "Math argument out of domain of func",
	[ERANGE] = "Math result not representable",
	[EDEADLK] = "Resource deadlock would occur",
	[ENAMETOOLONG] = "File name too long",
	[ENOLCK] = "No record locks available",
	[ENOSYS] = "Invalid system call number",
	[ENOTEMPTY] = "Directory not empty",
	[ELOOP] = "Too many symbolic links encountered",
	// [EWOULDBLOCK] = "Operation would block", // initializer overrides prior initialization of this subobject [EAGAIN]
	[ENOMSG] = "No message of desired type",
	[EIDRM] = "Identifier removed",
	[ECHRNG] = "Channel number out of range",
	[EL2NSYNC] = "Level 2 not synchronized",
	[EL3HLT] = "Level 3 halted",
	[EL3RST] = "Level 3 reset",
	[ELNRNG] = "Link number out of range",
	[EUNATCH] = "Protocol driver not attached",
	[ENOCSI] = "No CSI structure available",
	[EL2HLT] = "Level 2 halted",
	[EBADE] = "Invalid exchange",
	[EBADR] = "Invalid request descriptor",
	[EXFULL] = "Exchange full",
	[ENOANO] = "No anode",
	[EBADRQC] = "Invalid request code",
	[EBADSLT] = "Invalid slot",
	[EBFONT] = "Bad font file format",
	[ENOSTR] = "Device not a stream",
	[ENODATA] = "No data available",
	[ETIME] = "Timer expired",
	[ENOSR] = "Out of streams resources",
	[ENONET] = "Machine is not on the network",
	[ENOPKG] = "Package not installed",
	[EREMOTE] = "Object is remote",
	[ENOLINK] = "Link has been severed",
	[EADV] = "Advertise error",
	[ESRMNT] = "Srmount error",
	[ECOMM] = "Communication error on send",
	[EPROTO] = "Protocol error",
	[EMULTIHOP] = "Multihop attempted",
	[EDOTDOT] = "RFS specific error",
	[EBADMSG] = "Not a data message",
	[EOVERFLOW] = "Value too large for defined data type",
	[ENOTUNIQ] = "Name not unique on network",
	[EBADFD] = "File descriptor in bad state",
	[EREMCHG] = "Remote address changed",
	[ELIBACC] = "Can not access a needed shared library",
	[ELIBBAD] = "Accessing a corrupted shared library",
	[ELIBSCN] = ".lib section in a.out corrupted",
	[ELIBMAX] = "Attempting to link in too many shared libraries",
	[ELIBEXEC] = "Cannot exec a shared library directly",
	[EILSEQ] = "Illegal byte sequence",
	[ERESTART] = "Interrupted system call should be restarted",
	[ESTRPIPE] = "Streams pipe error",
	[EUSERS] = "Too many users",
	[ENOTSOCK] = "Socket operation on non-socket",
	[EDESTADDRREQ] = "Destination address required",
	[EMSGSIZE] = "Message too long",
	[EPROTOTYPE] = "Protocol wrong type for socket",
	[ENOPROTOOPT] = "Protocol not available",
	[EPROTONOSUPPORT] = "Protocol not supported",
	[ESOCKTNOSUPPORT] = "Socket type not supported",
	[EOPNOTSUPP] = "Operation not supported on transport endpoint",
	[EPFNOSUPPORT] = "Protocol family not supported",
	[EAFNOSUPPORT] = "Address family not supported by protocol",
	[EADDRINUSE] = "Address already in use",
	[EADDRNOTAVAIL] = "Cannot assign requested address",
	[ENETDOWN] = "Network is down",
	[ENETUNREACH] = "Network is unreachable",
	[ENETRESET] = "Network dropped connection because of reset",
	[ECONNABORTED] = "Software caused connection abort",
	[ECONNRESET] = "Connection reset by peer",
	[ENOBUFS] = "No buffer space available",
	[EISCONN] = "Transport endpoint is already connected",
	[ENOTCONN] = "Transport endpoint is not connected",
	[ESHUTDOWN] = "Cannot send after transport endpoint shutdown",
	[ETOOMANYREFS] = "Too many references: cannot splice",
	[ETIMEDOUT] = "Connection timed out",
	[ECONNREFUSED] = "Connection refused",
	[EHOSTDOWN] = "Host is down",
	[EHOSTUNREACH] = "No route to host",
	[EALREADY] = "Operation already in progress",
	[EINPROGRESS] = "Operation now in progress",
	[ESTALE] = "Stale NFS file handle",
	[EUCLEAN] = "Structure needs cleaning",
	[ENOTNAM] = "Not a XENIX named type file",
	[ENAVAIL] = "No XENIX semaphores available",
	[EISNAM] = "Is a named type file",
	[EREMOTEIO] = "Remote I/O error",
	[EDQUOT] = "Quota exceeded",
	[ENOMEDIUM] = "No medium found",
	[EMEDIUMTYPE] = "Wrong medium type",
	[ECANCELED] = "Operation Canceled",
	[ENOKEY] = "Required key not available",
	[EKEYEXPIRED] = "Key has expired",
	[EKEYREVOKED] = "Key has been revoked",
	[EKEYREJECTED] = "Key was rejected by service",
	[EOWNERDEAD] = "Owner died",
	[ENOTRECOVERABLE] = "State not recoverable",
	[ERFKILL] = "Operation not possible due to RF-kill",
	[EHWPOISON] = "Memory page has hardware error"};

/**
 * @brief Retrieves the error message string associated with the given error number.
 *
 * This function returns a pointer to a string that describes the error code specified by `errnum`.
 * The string may be a system-defined error message or a custom error message set by the application.
 *
 * @param errnum The error number for which to retrieve the error message.
 * @return A pointer to a string containing the error message.
 */
const char *strerror(errno_t errnum) {
	if ((unsigned int)errnum < sizeof(error_messages) / sizeof(error_messages[0]) && error_messages[errnum] != NULL) {
		return error_messages[errnum];
	}
	return "Unknown error";
}

/**
 * @brief Prints a descriptive error message to the standard error stream.
 *
 * This function prints a message to the standard error stream (`stderr`) that describes the last error encountered during a function call.
 * The message is preceded by the string `s` and followed by a colon and a space.
 * If `s` is `NULL`, only the error message is printed.
 *
 * @param s The prefix string to be printed before the error message. Can be `NULL`.
 */
void perror(const char *s) {
	if (s && *s) {
		printk("%s: %s\n", s, strerror(errno));
	} else {
		printk("%s\n", strerror(errno));
	}
}
