PHP_ARG_ENABLE(mount,
  [Whether to enable the mount extension],
  [  --enable-mount        Enable mount extension support])

if test $PHP_MOUNT != "no"; then
  PHP_SUBST(MOUNT_SHARED_LIBADD)
  PHP_NEW_EXTENSION(mount, mount.c, $ext_shared)
fi
