PHP_ARG_ENABLE([php_sdl2],
  [whether to enable php_sdl2 support],
  [AS_HELP_STRING([--enable-php_sdl2],
    [Enable php_sdl2 support])],
  [no])

if test "$PHP_PHP_SDL2" != "no"; then

  AC_DEFINE(HAVE_PHP_SDL2, 1, [ Have php_sdl2 support ])

  LIBNAME=SDL2
  LIBSYMBOL=SDL_Init
  EXTRA_CFLAGS=`pkg-config --cflags --libs sdl2`

  PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  [
    PHP_SUBST(EXTRA_CFLAGS)
    AC_DEFINE(HAVE_PHP_SDL_INIT, 1, [Whether you have PHP_SDL2])
    AC_MSG_RESULT(found)
  ],[
    AC_MSG_ERROR([wrong lib$LIBNAME version or library not found])
  ])

  PHP_NEW_EXTENSION(php_sdl2, php_sdl2.c, $ext_shared)
fi
