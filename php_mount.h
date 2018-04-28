#ifndef PHP_MOUNT_H
#define PHP_MOUNT_H

#define PHP_MOUNT_EXTNAME  "mount"
#define PHP_MOUNT_EXTVER   "0.0"

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include "php.h"

#ifdef ZTS
#include "TSRM.h"
#endif

#if defined(ZTS) && defined(COMPILE_DL_SAMPLE)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif /* PHP_COUNTER_H */
