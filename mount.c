#include "php_mount.h"

/* START: function implementations */
PHP_FUNCTION(mount_mount)
{
	char *src, *target, *fstype, *data;
	long flags = 0;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sss|ls", src, target, fstype, &flags, data) == FAILURE) {
		RETURN_FALSE;
	}

	mount(src,target,fstype,flags,data);

	RETURN_TRUE;
}

PHP_FUNCTION(mount_umount)
{
	RETURN_TRUE;
}

/* END: function implementations */

/* Create module function list */
const zend_function_entry php_mount_functions[] = {
	ZEND_NAMED_FE(mount, ZEND_FN(mount_mount), NULL)
	ZEND_NAMED_FE(umount, ZEND_FN(mount_umount), NULL)
	PHP_FE_END
};

/* Create the module (extension) entry */
zend_module_entry mount_module_entry = {
	STANDARD_MODULE_HEADER,
	PHP_MOUNT_EXTNAME,
	php_mount_functions, /* Functions */
	NULL, /* MINIT */
	NULL, /* MSHUTDOWN */
	NULL, /* RINIT */
	NULL, /* RSHUTDOWN */
	NULL, /* MINFO */
	PHP_MOUNT_EXTVER,
	STANDARD_MODULE_PROPERTIES
};

#ifdef MOUNT_DL_COUNTER
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(mount)
#endif
